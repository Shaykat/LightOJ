#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int a,b,t;
    int rev[20],i,temp;

    scanf("%d",&t);
    for(int d=1;d<=t;d++){

    scanf("%d",&a);
    int p = a;
    b=0;
    i=0;
    while(a){
        temp = a%10;
        rev[i++] = temp;
        a = a/10;
    }
    int k=1;
    for(int j=i-1;j>=0;j--){
        b = rev[j]*k + b;
        k = k*10;
    }

    if(p == b){
        printf("Case %d: Yes\n",d);
    }
    else{
        printf("Case %d: No\n",d);
    }

    }
    return 0;
}
