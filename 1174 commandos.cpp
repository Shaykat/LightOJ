#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;
#define max 100
vector<int>graph[max];
int time[2][max],color[max];
int node,edge,t=0,T;
bool flag;

void dfs(int u)
{
    color[u] = 1;
    time[0][u] = ++t;
    //printf("%d ",u);
    for(int i=0;i<graph[u].size();i++)
    {
        if(graph[u][i] == 4){
            flag = false;
            T = t;
            break;
        }
        if(color[graph[u][i]] == 0)
        {
            printf("%d --> %d is a tree edge\n",u,graph[u][i]);
            dfs(graph[u][i]);
        }
    }
    color[u] = 2;
    time[1][u] = ++t;
}
int main()
{
    int x,y;
    int u;
    flag = true;
    scanf("%d%d",&node,&edge);
    for(int i=0;i<edge;i++) // take input and make adjecency matrix
    {
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(color,0,sizeof(color));

    for(int i=0;i<node;i++)
    {
        //temp = t;
        if(color[i] == 0)
        {
            dfs(i);
            if(flag == false){
                break;
            }
        }

    }
    cout << T << endl;
    return 0;
}
