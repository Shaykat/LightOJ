#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main()
{
    int x,y,z,t;
    double A,B,AP;

    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&x,&y,&z);

        A = (x+y);

        B = x - y;

        AP = z*(x+B)/A;

        //printf("%.0lf\n",AP);
         cout << fixed << setprecision(0) << AP << endl;

    }

    return 0;
}
