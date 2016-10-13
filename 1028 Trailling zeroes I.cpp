#include<bits/stdc++.h>
using namespace std;

// input output
#define pf           printf
#define sf(n)        scanf("%d", &n)
#define sfl(n)       scanf("%lld", &n)
#define sfc(n)       scanf("%c", &n)
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

// compare
bool compare(const pair<int,int>&i,const pair<int,int>&j){
    return i.first < j.first;
}
// upper case
string To_Upper(string a){
    for(int i = 0; i < a.size()-1; i++){
        if(islower(a[i])) a[i] = toupper(a[i]);
    }
    return a;
}

// manual division
int divide(string a,int base){
    int b = a.size(),c = 0,r = 0,i = 0;
    while(i < b){
        c = c*base + a[i++]-'0';
        if(c/b > 0){
            r = r*base + c/b;
            c = c%b;
        }
    }
    if(c == 0) return r;
    return 0;
}
// @Shaykat@
/////////////////////////////////// template //////////////////////////////
#define a 1000007

ll arr[a];
ll n,k,f[50],p[50],l;
vector<ll>prime;
void sieve()
{
    ll i,j;
    prime.pb(2);
    ll sn = sqrt((double)a);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 0;
    for(i=3;i<=sn;i+=2)
    {
        if(arr[i] == 0)
        {
        	//prime[k++] = i;
            for(j=i*i;j<a;j+=2*i)
            {
                arr[j] = 1;
            }
        }
    }
    for(i = 3; i <= 1000010; i+=2){
        if(arr[i] == 0)
        prime.pb(i);
    }
}

void prime_factor(ll n){
	ll sq = sqrt(n),cnt = 0;
	l =0;
	for(ll i =0; i < prime.size() && prime[i] <= sq+1; i++){
		if(n%prime[i] == 0){
			cnt = 0;
			while(n%prime[i] == 0){
				cnt++;
				n/= prime[i];
			}
			f[l] = prime[i];
			p[l] = cnt;
			l++;
			sq = sqrt(n);
		}
	}
	if(n > 1){
		f[l] = n;
		p[l++] = 1;
	}
}
void init(){
    mem(f,0);
    mem(p,0);
}

int main(){
    ll t,n;
    sieve();
    sfl(t);
    For(j,1,t){
        sfl(n);
        prime_factor(n);
        ll d = 1;
        for(int i = 0; i < l; i++){
            d *= (p[i]+1);
        }
        pf("Case %d: %lld\n",j,d-1);
        init();
    }
}
