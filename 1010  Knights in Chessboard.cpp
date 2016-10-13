#include<bits/stdc++.h>
using namespace std;

#define mx 250
#define p pair<int,int>
//vector<int>graph[mx];
int color[mx][mx];
int row,colom;
int fx[] = {1,1,-1,-1,2,2,-2,-2};
int fy[] = {2,-2,2,-2,1,-1,1,-1};

void tddfs(int x,int y){
    //cout << "tddfs" << endl;
    int p1,p2;
    color[y][x] = 1;
    //cout << color[y][x] << endl;
    for(int i = 0; i < 8; i++){
        p1 = x + fx[i];
        p2 = y + fy[i];
        if(p2>=0 && p2<row && p1>=0 && p1<colom && color[p2][p1] == 0){
            tddfs(p1,p2);
            //cout << "inside" << endl;
        }
    }
    color[y][x] = 2;
}

int main(){
    int T,cnt;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        cnt = 0;
        scanf("%d%d",&row,&colom);
        memset(color,0,sizeof(color));
        for(int j = 0; j < row; j++){
            for(int k = 0; k < colom; k++){
                if(color[j][k] == 0){
                    cnt++;
                    tddfs(k,j);
                    //cout << "loop" << endl;
                }
            }
        }
        cout << cnt << endl;
        memset(color,0,sizeof(color));
    }
}

