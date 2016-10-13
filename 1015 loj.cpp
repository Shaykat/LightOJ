#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    int t;
    int n,i,j,m;
    cin >> t;
    for(j=0;j<t;j++)
    {
        int sum = 0;
        cin >> n;
        for(i=0;i<n;i++)
        {
            cin >> m;
            if(m>0)
            sum = sum + m;

        }

        cout << "Case " << j+1 << ": " << sum << endl;

    }

    return 0;
}
