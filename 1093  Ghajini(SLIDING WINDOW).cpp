//#include<bits/stdc++.h>
#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <algorithm>
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
//typedef priority_queue<int> pq;

// @Shaykat@
/////////////////////////////////// template //////////////////////////////
#define s 1000110
deque < pair<int,int> > dq;
deque < pair<int,int> > DQ;

vector<int>mn;
vector<int>mx;

int n,k,t;
int a[s],c[s];

void init(){
    mn.clear();
    mx.clear();
    mem(c,0);
    while(!dq.empty()){
        dq.pop_front();
    }
    while(!DQ.empty()){
        DQ.pop_front();
    }
}

int main(){
    int p,T=1;
    sf(t);
    while(t--){
        sff(n,k);
        For(i, 0, n-1){
            sf(p);
            a[i] = p;
        }
        // min
        int j = 0;
        //cout << k << endl;
        while(j < k){
            if(dq.empty()){
                dq.push_front(make_pair(a[j],j));
            }
            else {
                while(!dq.empty() && dq.front().first >= a[j]){
                    dq.pop_front();
                }
                dq.push_front(make_pair(a[j],j));
            }
            j++;
        }
        mn.pb(dq.back().first);
        int st = 1;
        while(j < n){
            while(dq.back().second < st){
                dq.pop_back();
            }
            if(dq.empty()){
                dq.push_front(make_pair(a[j],j));
            }
            else {
                while(!dq.empty() && dq.front().first >= a[j]){
                    dq.pop_front();
                }
                dq.push_front(make_pair(a[j],j));
            }
            mn.pb(dq.back().first);
            j++;
            st++;
        } // min

        // max
        j = 0;
        //cout << k << endl;
        while(j < k){
            if(DQ.empty()){
                DQ.push_front(make_pair(a[j],j));
            }
            else {
                while(!DQ.empty() && DQ.front().first <= a[j]){
                    DQ.pop_front();
                }
                DQ.push_front(make_pair(a[j],j));
            }
            j++;
        }
        mx.pb(DQ.back().first);
        st = 1;
        while(j < n){
            while(DQ.back().second < st){
                DQ.pop_back();
            }
            if(DQ.empty()){
                DQ.push_front(make_pair(a[j],j));
            }
            else {
                while(!DQ.empty() && DQ.front().first <= a[j]){
                    DQ.pop_front();
                }
                DQ.push_front(make_pair(a[j],j));
            }
            mx.pb(DQ.back().first);
            j++;
            st++;
        }
        // max

        For(i,0,mn.size()-1){
            c[i] = mx[i]-mn[i];
        }
        sort(c,c+n);
        cout << "Case " << T << ": " << c[n-1] << endl;
        T++;
        init();
    }
    return 0;
}

