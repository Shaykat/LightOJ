#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,i,k,account,op,array[100],j;
    char d[10],r[10],s;

    scanf("%d",&t);

    for(i=1;i<=t;i++)
    {
        account = 0;
        j=0;
        scanf("%d",&op);
        while(op--)
        {
            scanf("%s%c",d,&s);
            if(strcmp(d,"donate") == 0)
            {
                scanf("%d",&k);
                account += k;

            }
            else if(strcmp(d,"report") == 0)
            {
                array[j++] = account;
            }

        }

        printf("Case %d:\n",i);
        for(int l=0;l<j;l++)
        {
            printf("%d\n",array[l]);
        }


    }
    return 0;
}
