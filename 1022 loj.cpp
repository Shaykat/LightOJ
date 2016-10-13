#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    int t,i;
    double r;
    double pi = 2*acos(0);
    cin >> t;

    for(i=1;i<=t;i++)
    {
        double s=0,c=0,d=0;
        cin >> r;
        s = 4*r*r;
        c = pi*r*r;
        d = s-c;

        cout << "Case " << i << ": " << fixed << setprecision(2) << d << endl;
    }
    return 0;
}
