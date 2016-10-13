#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
#define s 100010

vector<int>G[s];
queue<int>Q;
int visited[s];
int va,ly;

void BFS(int src){
    va = 1, ly =0;
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
                    //cout << "l: " << ly << endl;
                }
                else if(visited[u] == 2){
                    visited[v] = 1;
                    va++;
                    Q.push(v);
                    //cout << "v: " << va << endl;
                }
            }
        }
        Q.pop();
    }
    //cout << v << "  " << l << endl;
}


int main(){
    int n,x,y,T;
    scanf("%d",&T);

    for(int t = 1; t <= T; t++){
        scanf("%d",&n);
        for(int i = 0; i < n; i++){

            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        BFS(1);
        //cout << va << "  " << ly << endl;
        if(va > ly){
            printf("Case %d: %d\n",t,va);
        }
        else if(va < ly){
            printf("Case %d: %d\n",t,ly);
        }
        for(int j = 0; j <= n; j++){
            G[j].clear();
            memset(visited,0,sizeof(visited));
        }
    }
}
