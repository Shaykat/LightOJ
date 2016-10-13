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
    int sum;
}tr[5*s];

int T,n,m,p;
int arr[s];

void init(int idx,int st,int ed){
    if(st == ed){
        cnd.sum = arr[st];
        return;
    }
    int mid = (st+ed)/2;

    init(leftcl);
    init(rightcl);
    cnd.sum = lnd.sum+rnd.sum;
}
int query(int idx,int st,int ed,int i,int j){
    if(i > ed || j < st){
        return 0;
    }
    if(st >= i && ed <= j){
        //cout << "total: " << cnd.sum << endl;
        return cnd.sum;
    }
    int mid = (st+ed)/2;
    int a = query(leftcl,i,j);
    int b = query(rightcl,i,j);
    return a+b;
}

void gift(int idx,int st,int ed,int i){
    if(i > ed || i < st){
        return;
    }
    if(st >= i && ed <= i){
        p = cnd.sum;
        //cout << "ddd: " << p << endl;
        cnd.sum = 0;
        return;
    }

    int mid = (st+ed)/2;
    gift(leftcl,i);
    gift(rightcl,i);
    cnd.sum=lnd.sum+rnd.sum;
}
void update(int idx,int st,int ed,int i,int v){
    if(i > ed || i < st){
        return;
    }
    if(st >= i && ed <= i){
        cnd.sum += v;
        //cout << cnd.sum << endl;
        return;
    }

    int mid = (st+ed)/2;
    update(leftcl,i,v);
    update(rightcl,i,v);
    cnd.sum = lnd.sum + rnd.sum;
}

int main(){
    int op,x,y;

    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        memset(arr,0,sizeof(arr));
        scanf("%d%d",&n,&m);
        for(int j = 0; j < n; j++){
            scanf("%d",&arr[j]);
        }
        printf("Case %d:\n",i);
        init(1,0,n-1);
        for(int j = 0; j < m; j++){
            scanf("%d",&op);
            if(op == 1){
                scanf("%d",&x);
                gift(1,0,n-1,x);
                printf("%d\n",p);
            }
            else if(op == 2){
                scanf("%d%d",&x,&y);
                update(1,0,n-1,x,y);
            }
            else if(op == 3){
                scanf("%d%d",&x,&y);
                printf("%d\n",query(1,0,n-1,x,y));
            }
        }

        memset(arr,0,sizeof(arr));
    }
    return 0;
}
