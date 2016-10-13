#include<bits/stdc++.h>
using namespace std;
#define s 10010
vector<int>G[s];
map<string,int>m;
int visit[s];
int n,v;
bool flag;

void init(){
    memset(visit,0,sizeof(visit));
    for(int i = 0; i < s; i++){
        G[i].clear();
    }
    flag = true;
}

void dfs(int u){
    visit[u] = 1;

    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(visit[u] == 1 && visit[v] == 1){
            flag = false;
            break;
        }
        if(visit[v] == 0){
            dfs(v);
        }
    }
    visit[u] = 2;
}

int main(){
    int T;
    string a,b;

    cin >> T;
    init();
    for(int i = 1; i <= T; i++){
        v = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> a >> b;
            if(m.find(a) == m.end()){
                m[a] = v++;
            }
            if(m.find(b) == m.end()){
                m[b] = v++;
            }
            G[m[a]].push_back(m[b]);
        }

        for(int j = 0; j < n;j++){
            if(visit[j] == 0){
                dfs(j);
            }
            if(flag == false){
                printf("Case %d: No\n",i);
                break;
            }
        }
        if(flag == true){
            printf("Case %d: Yes\n",i);
        }
        init();

    }
}
