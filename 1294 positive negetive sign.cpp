#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long m,n,sum;
    int i,t;
    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        scanf("%lld",&m);
        sum= 0;

        sum = (n/2)*m;
        printf("Case %d: %lld\n",i,sum);
    }

    return 0;

}

