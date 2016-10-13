#include<bits/stdc++.h>
using namespace std;

string a;
vector<char>v;
int flag[30];
int k,cnt = 0,n;
void call(){
    if(cnt >=k) return;
    if(v.size() == n){
        for(int i = 0; i < n; i++){
            cout << v[i];
        }
        cout << endl;
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++){
        if(flag[i] == 0){
            v.push_back(a[i]);
            flag[i] = 1;
            call();
            v.pop_back();
            flag[i] = 0;
        }
    }
}
void init(){
    v.clear();
    memset(flag,0,sizeof(flag));
    cnt = 0;
}
int main(){
    int t;
    a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> t;
    int i;
    for(i = 1; i <= t; i++){
        cin >> n >> k;
        printf("Case %d:\n",i);
        call();
        init();
    }
}
