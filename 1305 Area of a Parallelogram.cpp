#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy,h,base,t;
    int area;

    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        area = 0;
        scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);

        if(cy>by)
        h = cy - by;
        else
        h = by - cy;
        if(bx>ax)
        base = bx - ax;
        else
        base = ax - bx;

        area = base * h;
        dx = cx - base;
        dy = cy;

        printf("Case %d: %d %d %d\n",i,dx,dy,area);
    }

    return 0;
}
