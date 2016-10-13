#include<bits/stdc++.h>
using namespace std;

#define s 10010
#define mod %10000007
long long a[s];

int main(){
    int n, caseno = 0, cases;
    int g, b, c, d, e, f;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &g, &b, &c, &d, &e, &f, &n);
         a[0] = g;
        a[1] = b;
        a[2] = c;
        a[3] = d;
        a[4] = e;
        a[5] = f;
        /*a[6] = (a[0] + a[1] + a[2] + a[3]+ a[4] + a[5]);
        a[7] = (a[6] + a[5] + a[4] + a[3]+ a[2] + a[1]);
        a[8] = (a[7] + a[6] + a[5] + a[4] + a[3]+ a[2]);
        a[9] = (a[8] + a[7] + a[6] + a[5]+ a[4] + a[3]);
        a[10] = (a[9] + a[8] + a[7] + a[6]+ a[5] + a[4]);*/
        if(n < 6){
           printf("Case %d: %d\n", ++caseno,a[n]mod);
        }
        else {
            int j = 6;
            while(j <= n){
                a[j] = (a[j-1]mod + a[j-2]mod + a[j-3]mod + a[j-4]mod + a[j-5]mod + a[j-6]mod)mod;
                j++;
            }
            printf("Case %d: %d\n", ++caseno,a[n]mod);
        }
    }
    return 0;

}
