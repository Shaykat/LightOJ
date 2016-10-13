#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstdlib>
#include<cstring>
using namespace std;
#define max 10005
int edge,t,v;
vector<int>graph[max];
map<string,int>mymap;
int color[max];
int flag;

bool topsort(int u){
    int v;
    color[u] = 1;
    for(int i=0;i<graph[u].size();i++){
        v = graph[u][i];
        //cout << u << " --> " << var << endl;
        if(color[v] == 1){
            //cout << u << "-->" << var << "back edge" << endl;
            flag = 1;
            break;
        }
        else if(color[v] == 0){

            topsort(v);
        }
    }
    color[u] = 2;
    if(flag == 1){
        return false;
    }
    else {
        return true;
    }
}

void init(){
    memset(color,0,sizeof(color));
    flag = 0;
}
void destroy(){
    mymap.clear();
    for(int k=0;k<v;k++){
        graph[k].clear();
    }
}
int main()
{
    string a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        init();
        cin >> edge;
        v = 3;
        getchar();
        while(edge--){
            cin >> a >> b;
            if(!mymap[a]){
               mymap[a] = v++;
            }

            if(!mymap[b]){
               mymap[b] = v++;
            }
            graph[mymap[a]].push_back(mymap[b]);
        }

        for(int j=3;j<v;j++){
            if(color[j] == 0){
                if(!topsort(j)){
                    break;
                }
            }
        }
                                                mn  n             if(flag){
            printf("Case %d: No\n",i);
        }
        else{
            printf("Case %d: Yes\n",i);
        }

        destroy();
        init();

    }
      return 0;
}

/*
fb fc
eb bf
bf fb
fc eb
fb a
eb a
*/
