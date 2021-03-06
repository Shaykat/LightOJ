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
#define PC(T,R)         printf("Case %d: %d\n",T,R);

// operations
#define pb              push_back
#define ppb             pop_back
#define mem(n, val)     memset((n), val, sizeof(n))
#define mp              make_pair
#define ff first
#define se second

// Loop
#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ror(i, a, b)    for(int i = a; i >= b; i--)
#define all(v)          v.begin(), v.end()

// functions
#define gcd(a,b)        ll _gcd(int a,int b){ if(b%a == 0) return a; _gcd(b%a,a); }
#define lcm(a,b)        ((a*b)/gcd(a,b))

// binary tree || segment tree
#define cnd tr[idx]
#define lnd tr[idx*2]
#define rnd tr[idx*2 + 1]
#define leftcl idx*2,st,mid
#define rightcl idx*2 + 1,mid+1,ed

// compare
// functions
#define cmpr            bool compare(const pair<int,int>&i,const pair<int,int>&j)   {return i.first < j.first;}
#define tostring(a)     string To_Upper(string a)   {for(int i = 0;i < a.size()-1;i++){  if(islower(a[i])) a[i] = toupper(a[i]); } return a; }

//operator overloading
class Compare{
    public:
    bool operator()(const int& l, const int& r){
       return l > r;
   }
};

// typedef
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, string> PIS;
typedef priority_queue<int> PQ; // for max heap
typedef priority_queue<int,vector<int>, Compare > P_Q; // for min heap

// constants
const int MOD = 1000000007;
const double EPS = 1e-11;
const double INF = 2e30;
const double PI = 2 * acos( 0.0 );

// manual division
int divide(string a,int base)   {int b = a.size(),c = 0,r = 0,i = 0;
    while(i < b)    {c = c*base + a[i++]-'0';
    if(c/b > 0) {r = r*base + c/b; c = c%b;}}
    if(c == 0) return r;
    return 0;
}

bool Prime(int n){
    int sqt = sqrt(n);
    for (int i=2;i<=sqt;i++){
        if (n%i == 0)   return false;
    }
    return true;
}

// binary operations
int Bset(int N,int pos){return N=N | (1<<pos);}
int Breset(int N,int pos){return N= N & ~(1<<pos);}
bool Bcheck(int N,int pos){return (bool)(N & (1<<pos));}

/////////////////////////////////// template //////////////////////////////
struct node{
    int sum;
}tr[300010];

int t,n,a[100010];

void init(int idx,int st,int ed){
   if(st == ed){
        cnd.sum = 1;
        return;
    }
    int mid = (st+ed)/2;

    init(leftcl);
    init(rightcl);
    cnd.sum = lnd.sum+rnd.sum;
}

int query(int idx,int st,int ed,int p){
    if(st == ed){
        //cout << "total: " << cnd.sum << endl;
        return st;
    }
    int mid = (st+ed)/2;
    int a;
    if(p > rnd.sum){
        a = query(leftcl,(p-rnd.sum));
    }
    else{
        a = query(rightcl,p);
    }
    return a;
}

void update(int idx,int st,int ed,int i,int v){
    if(i > ed || i < st){
        return;
    }
    if(st >= i && ed <= i){
        cnd.sum = v;
        //cout << cnd.sum << endl;
        return;
    }

    int mid = (st+ed)/2;
    update(leftcl,i,v);
    update(rightcl,i,v);
    cnd.sum = lnd.sum + rnd.sum;
}

/*int bisection(int p){
    int hi = n, lo = 1, mid = 0, last = n,v,x;

    while(hi >= lo){
        mid = (lo+hi)/2;
        v = query(1,1,n,mid,last);
        if(v < p){
            hi = mid-1;
        }
        else{
            x = mid;
            lo = mid + 1;
        }
    }
    return x;
}*/

int main(){
    sf(t);
    For(k,1,t){
        mem(a,0);
        sf(n);

        init(1,1,n);

        For(i,0,n-1){
            sf(a[i]);
        }

        int res;
        Ror(i,n-1,0){

            res = query(1,1,n,a[i]+1);
            //cout << res << " " << endl;
            update(1,1,n,res,0);
        }
        PC(k,res);
    }

    return 0;
}
