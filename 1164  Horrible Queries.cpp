#include<bits/stdc++.h>
using namespace std;
#define s 100005
#define cnd tr[idx]
#define lnd tr[idx*2]
#define rnd tr[idx*2 + 1]
#define leftcl idx*2,st,mid
#define rightcl idx*2 + 1,mid+1,ed
#define mset() memset(arr,0,sizeof(arr))
#define inf 1000000000
#define ll long long
int T,n,m,p;
struct node{
    ll sum;
    ll prop;
}tr[4*s];

/*
void init(int idx,int st,int ed){
    if(st == ed){
        cnd.sum = 0;
        cnd.prop = 0;
        return;
    }
    int mid = (st+ed)/2;
    init(leftcl);
    init(rightcl);
    cnd.sum = lnd.sum + rnd.sum;
    cnd.prop = 0;
    //cout << "sum: " << cnd.sum << endl;
}
*/

void update(int idx,int st,int ed,int i,int j,int v){
    if(st > j || ed < i){
        return;
    }
    if(st >= i && ed <= j){
        cnd.sum += (ed-st+1)*v;
        cnd.prop += v;
        return;
    }

    int mid = (st+ed)/2;
    update(leftcl,i,j,v);
    update(rightcl,i,j,v);
    cnd.sum = lnd.sum + rnd.sum + (ed-st+1)*cnd.prop;
}

ll query(int idx,int st,int ed,int i,int j,ll carry){
    if(st > j || ed < i){
        return 0;
    }
    if(st >= i && ed <= j){
        return cnd.sum + (ed-st+1)*carry;
    }

    int mid = (st+ed)/2;
    ll a = query(leftcl,i,j,carry+cnd.prop);
    ll b = query(rightcl,i,j,carry+cnd.prop);
    return a+b;
}

int main(){
    int x,y,op,v;
    scanf("%d",&T);

    for(int i = 1; i <= T; i++){
        scanf("%d%d",&n,&m);
        //init(1,1,n);
        memset(tr, 0, sizeof(tr));
        printf("Case %d:\n",i);
        for(int j = 0; j < m; j++){
            scanf("%d",&op);
            if(op == 0){
                scanf("%d%d%d",&x,&y,&v);
                update(1,1,n,x + 1,y + 1,v);
            }
            else if(op == 1){
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(1,1,n,x + 1,y + 1,0));
            }
        }
    }
    return 0;
}
