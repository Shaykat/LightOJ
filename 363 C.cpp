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
#define sz 110
int n,m,k;
int a[sz];
int main(){
    sf(n);
    For(i,0,n-1){
        sf(a[i]);
    }
    int j = 0,p = 0,r = 0;
    while(j < n){
        if(a[j] == 0 || (a[j] == p)){
            r++;
            p = 0;
        }
        else{
            if(a[j] == 3){
                if(p == 0){
                   if(j+1 < n && a[j+1] == 1) p = 2;
                   else if(j+1 < n && a[j+1] == 2) p = 1;
                   else p = 1;
                }
                else if(j-1 >= 0 && a[j-1] == 3){
                    if(j+1 < n && a[j+1] == 1) p = 2;
                    else if(j+1 < n && a[j+1] == 2) p = 1;
                }
                else if(p == 1) p = 2;
                else p = 1;
            }
            else  p = a[j];
        }
        j++;
    }
    cout << r << endl;
}
