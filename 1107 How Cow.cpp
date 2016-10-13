#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,x1,x2,y1,y2,m,x,y;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        printf("Case %d:\n",i);
        for(int j = 0; j < m; j++){
            scanf("%d%d",&x,&y);
            if(x > x1 && x < x2 && y > y1 && y < y2){
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
}
