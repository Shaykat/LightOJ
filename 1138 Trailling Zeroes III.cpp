#include<bits/stdc++.h>
using namespace std;

// input output
#define pf           printf
#define sf(n)        scanf("%d", &n)
#define sfl(n)        scanf("%lld", &n)
#define sfc(n)        scanf("%c", &n)
#define sff(a,b)     scanf("%d %d", &a, &b)
#define sfff(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INP          freopen("in.txt", "r", stdin);  // file input
#define OUT          freopen("out.txt", "w", stdout);  // file output

// operations
#define pb           push_back
#define mem(n, val)  memset((n), val, sizeof(n))
#define mp           make_pair
#define ff first
#define se second

// constant
#define MOD          1000000007
#define inf   1<<30                                           //infinity value
#define eps   1e-9

// Loop
#define For(i, a, b) for(int i = a; i <= b; i++)
#define Ror(i, a, b) for(int i = a; i >= b; i--)
#define all(v)       v.begin(), v.end()

// functions
#define gcd(a,b)     ll _gcd(int a,int b){ if(b%a == 0) return a; _gcd(b%a,a); }
#define lcm(a,b)     ((a*b)/gcd(a,b))

// binary tree || segment tree
#define cnd          tr[idx]
#define lnd          tr[idx << 1]
#define rnd          tr[lnd + 1]
#define leftcl       lnd,st,mid
#define rightcl      rnd,mid+1,ed

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, string> pis;
typedef priority_queue<int> pq;

// @Shaykat@
/////////////////////////////////// template //////////////////////////////
int n ;
int rez (int x){
    int sum=0 ;
    while (x!=0){
        x=x/5 ;
        sum+=x  ;
    }
    return sum ;
}

int Bisection(){
    int low=0 ,high=1000000000 ,mid ,ans=0 ;
    while (low<=high){
        mid=(low+high)/2 ;
        if (rez(mid) < n) low=mid+1 ;
        else if (rez(mid) > n) high = mid-1 ;
        else{
            ans =mid ;
            high=mid-1;
        }
    }
    return ans ;
}

int main () {
    int cas, i ,ret ;
    cin>>cas ;
    for (i=1 ;i <=cas ; i++) {
        cin>>n ;
        ret=Bisection() ;

        if (ret==0) cout<<"Case "<<i<<": "<<"impossible"<<endl ;
        else cout<<"Case "<<i<<": "<<ret<<endl ;
    }

    return 0 ;
}
