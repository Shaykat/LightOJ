#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define p 20005

vector<int>G[p];
queue<int>Q;
int visited[p],taken[p];
int va,ly,tvl=0;

void BFS(int src){
    Q.push(src);
    int u,v;
    visited[src] = 1;

    while(!Q.empty()){
        u = Q.front();
        for(int i=0;i<G[u].size();i++){
            v = G[u][i];
            if(!visited[v]){
                if(visited[u] == 1){
                    visited[v] = 2;
                    ly++;
                    Q.push(v);
                }
                else if(visited[u] == 2){
                    visited[v] = 1;
                    va++;
                    Q.push(v);
                }
            }
        }
        Q.pop();
    }
}


int main(){
    int n,x,y,T;
    scanf("%d",&T);
    memset(visited,0,sizeof(visited));
    memset(taken,0,sizeof(taken));

    for(int t = 1; t <= T; t++){
            tvl = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){

            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
            taken[x] = 1;
            taken[y] = 1;
        }
        for(int q = 1; q <= p; q++){
            if(taken[q] && !visited[q]){
                taken[q] = 0;
                va = 0;
                ly = 0;
                BFS(q);
                if(va >= ly){
                    tvl += va;
                    tvl ++;
                }
                else if(va < ly){
                    tvl += ly;
                    //tvl ++;
                }
                va = 0;
                ly =0;
            }
        }
        printf("Case %d: %d\n",t,tvl);
        for(int j = 0; j <= p; j++){
            G[j].clear();
            memset(visited,0,sizeof(visited));
            memset(taken,0,sizeof(taken));
            tvl = 0;
        }
    }
}
/*
8
39 61
26 19
2 75
65 19
51 84
26 41
83 37
36 66
*/
