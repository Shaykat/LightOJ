#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,l;
    int T;

    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        scanf("%d%d",&m,&l);
        int dl = abs(l-m);
        int tt = dl*4 + 19 + m*4;
        printf("Case %d: %d\n",i,tt);
    }
    return 0;
}
