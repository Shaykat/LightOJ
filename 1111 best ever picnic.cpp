#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
#define sz 1010
queue<int>Q;
vector<int>G[sz];
int visited[sz],person[sz],cont[sz];
int k,m,n,cnt;

void BFS(int src)
{
    Q.push(src);
    int u,v;
    visited[src]++;
    while(!Q.empty())
    {
        u = Q.front();
        for(int i=0;i<G[u].size();i++)
        {
            v = G[u][i];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                cont[v]++;
                //cout << "hgjdfghj" << endl;
                Q.push(v);
            }
        }
        Q.pop();
    }

}

void init(){
    memset(visited,0,sizeof(visited));
    memset(person,0,sizeof(person));
    memset(cont,0,sizeof(cont));
    cnt = 0;
}
void destroy(){
    for(int i = 0; i < n; i++){
        G[i].clear();
    }
}

int main(){

    int t;
    scanf("%d",&t);
    int p;
    int x,y;

    init();
    for(int i = 1; i <= t; i++){

        scanf("%d%d%d",&k,&n,&m);
        for(int l = 0; l < k; l++){
            scanf("%d",&person[l]);
        }

        for(int j = 0; j < m; j++){
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
        }

        for(int j = 0; j < k; j++){
            BFS(person[j]);
            memset(visited,0,sizeof(visited));
        }

        for(int j = 1; j <= n; j++){
           if(cont[j] == k)
            cout << cont[j] << " ";
           cnt++;
        }
        cout << endl;
        printf("Case %d: %d\n",i,cnt);

        init();
        destroy();

    }

    return 0;
}
