#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;

#define s 30010
vector<int>G[s];
vector<int>cost[s];
queue<int>Q;
int costa[s],visit[s],maxa = 0,maxi;

void bfsForFarthestNode(int src){
    Q.push(src);
    int u,v;
    visit[src] = 1;
    //cout << " bfs" << endl;
    while(!Q.empty()){
        //cout << " while" << endl;
        u = Q.front();
        Q.pop();
        //cout << "U: " << u << "size: " << G[u].size() << endl;
        for(int i = 0; i < G[u].size(); i++){

            //cout << "for" << endl;
            v = G[u][i];
            if(visit[v] == 0){
                visit[v] = 1;
                if(costa[u]+cost[u][i] > costa[v]){
                    costa[v] = costa[u]+cost[u][i];
                    if(costa[v] > maxa){
                        maxa = costa[v];
                        maxi = v;
                    }
                    //cout << "Max: " << maxa << endl;
                }
                 Q.push(v);
            }

        }
        //cout << "Max: " << maxa << endl;
    }
}

void farthestNode(int src){
    bfsForFarthestNode(src);
    memset(visit,0,sizeof(visit));
    memset(costa,0,sizeof(costa));
    maxa = 0;
    bfsForFarthestNode(maxi);
}
void init(){
    memset(visit,0,sizeof(visit));
    memset(costa,0,sizeof(costa));
    maxa = 0;
    maxi = 0;
    for(int i = 0; i < s; i++){
        G[i].clear();
        cost[i].clear();
    }
    while(!Q.empty()){
        Q.pop();
    }
}

int main(){
    int t,x,y,c,n;
    cin >> t;
    init();
    for(int k =  0; k < t; k++){
            cin >> n;
        for(int i = 0; i < n-1; i++){
            cin >> x >> y >> c;
            G[x].push_back(y);
            G[y].push_back(x);
            cost[x].push_back(c);
            cost[y].push_back(c);
        }
        farthestNode(0);
        //bfsForFarthestNode(0);
        cout << "Case " << k+1 << ": " << maxa << endl;
        init();

    }
}
