#include<bits/stdc++.h>
using namespace std;

#define s  100005
#define cnd tr[idx]
#define lnd tr[idx*2]
#define rnd tr[idx*2 + 1]
#define leftcl idx*2,st,mid
#define rightcl idx*2 + 1,mid+1,ed
#define inf 1000000000

struct node{
    int minv;
    int maxv;
}tr[5*s];

int T,n,d,p;
int arr[s];

void init(int idx,int st,int ed){
    if(st == ed){
        cnd.minv = arr[st];
        cnd.maxv = arr[st];
        return;
    }
    int mid = (st+ed)/2;

    init(leftcl);
    init(rightcl);
    cnd.minv = min(lnd.minv,rnd.minv);
    cnd.maxv = max(lnd.maxv,rnd.maxv);
}
int query_min(int idx,int st,int ed,int i,int j){
    if(i > ed || j < st){
        return inf;
    }
    if(st >= i && ed <= j){
        return cnd.minv;
    }
    int mid = (st+ed)/2;
    int a = query_min(leftcl,i,j);
    int b = query_min(rightcl,i,j);
    return min(a,b);
}
int query_max(int idx,int st,int ed,int i,int j){
    if(i > ed || j < st){
        return 0;
    }
    if(st >= i && ed <= j){
        return cnd.maxv;
    }
    int mid = (st+ed)/2;
    int a = query_max(leftcl,i,j);
    int b = query_max(rightcl,i,j);
    return max(a,b);
}

int main(){
    int minv = inf,diff;
    int maxv = 0;
    scanf("%d",&T);
    for(int i =1; i <= T; i++){
        memset(arr,0,sizeof(arr));
        scanf("%d%d",&n,&d);
        for(int j = 0; j < n; j++){
            scanf("%d",&arr[j]);
        }
        init(1,0,n-1);
        maxv=0;
        for(int j = 0; j < n; j++){
            int a = query_min(1,0,n-1,j,j+(d-1));
            int b = query_max(1,0,n-1,j,j+(d-1));
            diff = b-a;
            maxv = max(diff,maxv);
        }
        printf("Case %d: %d\n",i,maxv);
        memset(arr,0,sizeof(arr));
    }
}
