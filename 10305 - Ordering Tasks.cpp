#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<stack>
using namespace std;
#define s 110
int color[s];
vector<int>order;
vector<int>G[s];

void task(int u){

    int v;
    color[u] = 1;
    for(int i = 0; i < G[u].size(); i++){
        v = G[u][i];
        if(color[v] == 0){
            task(v);
        }
    }
    order.push_back(u);
    color[u] = 2;
}

void init(){
    memset(color,0,sizeof(color));
}
void destroy(){
    for(int i = 0; i < s; i++){
        G[i].clear();
    }

    order.clear();
}

int main(){
    int n,m,x,y;
    init();
    while(scanf("%d%d",&n,&m) != 0){
        if(n == 0 && m == 0){
            break;
        }

        for(int i = 0; i < m; i++){
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
        }

        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                task(i);
            }
        }

        for(int i = order.size()-1; i >= 0; i--){
            printf("%d ",order[i]);
        }
        printf("\n");
        destroy();
        init();
    }

    return 0;
}
