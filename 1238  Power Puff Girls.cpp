#include<bits/stdc++.h>
using namespace std;

#define s 25
#define p pair<int,int>
int cell[s][s];
int visit[s][s];
int level[s][s];
int row,colom,asx,asy,dx,dy,bsx,bsy,csx,csy,da,db,dc,d;
queue< pair<int,int> > Q;
int fy[] = {1,-1,0,0};
int fx[] = {0,0,1,-1};

void init(){
    memset(cell,0,sizeof(cell));
    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));
}

void tdbfs(int sy,int sx){
    int x,y;
    Q.push(make_pair(sy,sx));
    visit[sy][sx] = 1;
    level[sy][sx] = 0;
    while(!Q.empty()){
        p mp = Q.front();
        int p1 = mp.first;
        int p2 = mp.second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            y = p1+fy[i];
            x = p2+fx[i];
            if(x >= 0 && x < colom && y >= 0 && y < row && cell[y][x] == 0 && visit[y][x] == 0){
                Q.push(make_pair(y,x));
                visit[y][x] = 1;
                level[y][x] = level[p1][p2] + 1;
            }
        }
    }
}

int main(){
    char a;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> row >> colom;
        for(int j = 0; j < row; j++){
            for(int k = 0; k < colom; k++){
                cin >> a;
                if(a == 'a'){
                    asx = k;
                    asy = j;
                }
                else if(a == 'b'){
                    bsx = k;
                    bsy = j;
                }
                else if(a == 'c'){
                    csx = k;
                    csy = j;
                }
                else if(a == '.'){
                    cell[j][k] = 0;
                }
                else if(a == 'm' || a == '#'){
                    cell[j][k] = 1;
                }
                else if(a == 'h'){
                    dx = k;
                    dy = j;
                }
            }
        }
        tdbfs(asy,asx);
        da = level[dy][dx];
        memset(visit,0,sizeof(visit));
        memset(level,0,sizeof(level));
        d = max(0,da);
        tdbfs(bsy,bsx);
        db = level[dy][dx];
        memset(visit,0,sizeof(visit));
        memset(level,0,sizeof(level));
        d = max(db,d);
        tdbfs(csy,csx);
        dc = level[dy][dx];
        d = max(dc,d);
        //cout << d << endl;
        printf("Case %d: %d\n",i,d);
        init();
    }
}

