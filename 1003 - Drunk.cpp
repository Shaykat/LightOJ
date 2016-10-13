#include<bits/stdc++.h>
using namespace std;
#define s 10010
vector<int>graph[s];
map<string,int>m;
int n,t = 0;
int Time[2][s],color[s];
bool flag = true;
init(){
    memset(Time,0,sizeof(Time));
    memset(color,0,sizeof(color));
    for(int i = 0; i < n; i++){
        graph[i].clear();
    }
}
void dfs(int u){
    color[u] = 1;
    Time[0][u] = ++t;
    for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(color[v] == 1){
            flag = false;
            return;
        }
        if(color[v] == 0){
            dfs(graph[u][i]);
        }
    }
    color[u] = 2;
    Time[1][u] = ++t;
}
int main(){
    int T,value;
    string a,b;
    cin >> T;
    for(int i =  1; i <= T; i++){
        value = 10;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> a;
            cin >> b;
            if(!m[a]) m[a] = value++;
            if(!m[b])m[b] = value++;
            graph[m[a]].push_back(m[b]);
        }
        dfs(10);
        if(flag == true) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
        init();
    }
    return 0;
}
