#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
    int t,n,r,sum,f;
      scanf("%d",&t);
    while(t--){
            r=0;
            f=0;
            sum=0;
       scanf("%d",&n);
           while(n!=0){
            r=n%2;
            if(r==1){
               sum+=r;
               f=1;
            }
            else
            {
               f=0;
            }
            n=n/2;
           }

          cout<<sum<<endl;
       }
    return 0;
}
