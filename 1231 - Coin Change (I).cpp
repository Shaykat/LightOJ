#include<bits/stdc++.h>
using namespace std;
#define s1 1000
#define s2 50
#define s3 25

int dp[s2][s1];
int coin[s2],n,k;
int coin_dp(int i,int k){
    if(k == 0){
        return 1;
    }
    if(i == n+1){
        return 0;
    }
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    int a = 0,b = 0;
    if(k-a[i] > 0){
        a = coin_dp(i,k-a[i]);
    }
    b = coin_dp(i+1,k);

    return dp[i][k] = a + b;
}
int main(){
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n >> k;
        memset(coin,0,sizeof(coin));
        for(int j = 0; j < n; j++){
            cin >> coin[j];
        }
        cout << coin_dp(0,k) << endl;
        memset(coin,0,sizeof(coin));
    }

}
