#include<bits/stdc++.h>
using namespace std;

int main(){
    long long w,a,b;
    int T;

    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        scanf("%lld",&w);
        if(w%2 == 1){
             printf("Case %d: Impossible\n",i);
        }
        else{
            a = w/2;
            b = 2;
            while(a%2 == 0){
               a = a/2;
               b = b*2;
            }
            printf("Case %d: %lld %lld\n",i,a,b);

        }
    }
    return 0;
}
