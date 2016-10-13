#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
   int T;
   int x1,y1,x2,y2;
   int nc,x,y,i=1;;

   scanf("%d",&T);
   while(T--)
   {
       scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
       scanf("%d",&nc);

       cout << "Case " << i++ << ":" << endl;
       for(int i=0;i<nc;i++)
       {
           scanf("%d%d",&x,&y);
           if((x1<x && x<x2) && (y1<y && y<y2))
           {
               cout << "yes" << endl;
           }
           else
           {
               cout << "No" << endl;
           }
       }
   }
}
