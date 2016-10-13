#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define s 25
queue<pair<int,int> > Q;

int visited[s][s];
int cell[s][s];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int W,H,cnt;
void init(){
    memset(cell,0,sizeof(cell));
    memset(visited,0,sizeof(visited));
}

void tdbfs(int g,int h){
    int p1,p2,x,y;
    visited[g][h] = 1;
    Q.push(make_pair(g,h));
    while(!Q.empty()){
        pi mp = Q.front();
        Q.pop();
        p1 = mp.first;
        p2 = mp.second;
        for(int i = 0; i < 4; i++){
            x = p1+fy[i];
            y = p2+fx[i];
            if(x >= 0 && x < H && y >= 0 && y < W && cell[x][y] == 0 && visited[x][y] == 0){
                Q.push(make_pair(x,y));
                visited[x][y] = 1;
                cnt++;
            }
        }
    }
    while(!Q.empty()){
        Q.pop();
    }
}
int main(){
    int t,s1,s2;
    char a;
    init();
    cin >> t;
    for(int m = 1; m <= t; m++){
        cin >> W >> H;

        for(int i = 0; i < H;i++){
            for(int j = 0; j < W; j++){
                cin >> a;
                if(a == '.'){
                    cell[i][j] = 0;
                }
                else if(a == '#'){
                    cell[i][j] = 1l;
                }
                else if(a == '@'){
                    cell[i][j] = 3;
                    s1 = i;
                    s2 = j;
                }
            }
        }
        cnt = 0;
        tdbfs(s1,s2);
        printf("Case %d: %d\n",m,cnt+1);
        //cout << cnt+1 << endl;
        init();
    }
}
