/*------------------------------------************************************************---------------------------*/
//************************************   Author      : ABDUL MUTALAB SHAYKAT
//************************************   University  : AIUB
//************************************   E-mail      : SHAYKAT2057@GMAIL.COM
//************************************   Problem ID  :
//************************************   Problem Name:
//************************************   Algorithm   :
/*------------------------------------************************************************---------------------------*/

#include<bits/stdc++.h>
using namespace std;

#define S  30010
#define cnd tr[idx]
#define lnd tr[idx*2]
#define rnd tr[idx*2 + 1]
#define leftcl idx*2,st,mid
#define rightcl idx*2 + 1,mid+1,ed
#define inf 1000000000

// input output
#define pf              printf
#define sf(n)           scanf("%d", &n)
#define sfl(n)          scanf("%lld", &n)
#define sfc(n)          scanf("%c", &n)
#define sff(a,b)        scanf("%d %d", &a, &b)
#define sfff(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define INP             freopen("in.txt", "r", stdin);  // file input
#define OUT             freopen("out.txt", "w", stdout);  // file output
#define EL              cout << endl

//Test Case:
#define PC(C,R)         printf("Case %d: %d\n",C,R);

struct node{
    int pos;
    int minv;
}tr[5*S];

int T,n,d,p,mn = inf;
int arr[S];

int solve(int s, int e);
void init(int idx,int st,int ed){
    if(st == ed){
        cnd.pos = st;
        cnd.minv = arr[st];
        return;
    }
    int mid = (st+ed)/2;

    init(leftcl);
    init(rightcl);
    cnd.minv = min(lnd.minv,rnd.minv);
    if(cnd.minv == lnd.minv) cnd.pos = lnd.pos;
    else cnd.pos = rnd.pos;
}
int query_min(int idx,int st,int ed,int i,int j){
    if(i > ed || j < st){
        return inf;
    }
    if(st >= i && ed <= j){
        if(cnd.minv < mn){
            mn = cnd.minv;
            p = cnd.pos;
        }
        return cnd.minv;
    }
    int mid = (st+ed)/2;
    int a = query_min(leftcl,i,j);
    int b = query_min(rightcl,i,j);
    return min(a,b);
}

int solve(int s, int e){
    int res,resl = 0,resr = 0,ps;
    mn = inf;
    if(s > e) return arr[s];
    int mid = query_min(1,1,n,s,e);
    ps = p;

    res = (e-s+1)*mid;
    resl = solve(s,ps-1);
    resr = solve(ps+1,e);

    res = max(res,resl);
    return res = max(res,resr);

}

int main(){
    int minv = inf,diff;
    scanf("%d",&T);
    for(int i =1; i <= T; i++){
        sf(n);
        memset(arr,0,sizeof(arr));
        for(int j = 1; j <= 5*n; j++){
           tr[j].pos = 0;
           tr[j].minv = inf;
        }

        for(int j = 1; j <= n; j++){
            sf(arr[j]);
        }
        init(1,1,n);

        int res = solve(1,n);
        PC(i,res);
    }
    return 0;
}
