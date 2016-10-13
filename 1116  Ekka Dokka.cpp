#include<bits/stdc++.h>
using namespace std;

int main(){
    long long w;
    int T,n,m,a,b,flag;

    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        b = 2;
        flag = 0;
        scanf("%lld",&w);
        if(w%2 == 1){
             printf("Case %d: Impossible\n",i);
        }
        else{
            n = w/b;
            while(1){
                if(n%2 == 1){
                    flag = 1;
                    break;
                }
                b += 2;
                a = w/b;
                if(a*b == w){
                    n = a;
                }
            }
            if(flag == 1){
                m = b;
                printf("Case %d: %d %d\n",i,n,m);
            }
            else {
                printf("Case %d: Impossible\n",i);
            }
        }
    }
    return 0;
}
