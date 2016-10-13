
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
}tr[4*s];

int n,m;
int arr[s];

void init(int idx,int st,int ed){
    int mid;
    if(st == ed){
        cnd.minv = arr[st];
        return;
    }
    int left = idx*2;
    int right = idx*2 + 1;

    mid = (st+ed)/2;
    init(left,st,mid);
    init(right,mid+1,ed);

    cnd.minv = min(lnd.minv,rnd.minv);
    //cout << "root: " << idx << " " << cnd.minv << endl;
}


int query(int idx,int st,int ed,int i,int j){
    int mid;
    if(st > j || ed < i){
        return inf;
    }
    if(st >= i && ed <= j){
        return cnd.minv;
    }
    int left = idx*2;
    int right = idx*2 + 1;

    mid = (st+ed)/2;
    int a = query(left,st,mid,i,j);
    int b = query(right,mid+1,ed,i,j);
    return min(a,b);
}
int main(){
    int x,y,T;
    scanf("%d",&T);
    for(int j = 1; j <= T; j++){
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++){
           scanf("%d",&arr[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",j);
        for(int i = 0; i < m; i++){
            scanf("%d%d",&x,&y);
            printf("%d\n",query(1,1,n,x,y));
        }
    }
}
