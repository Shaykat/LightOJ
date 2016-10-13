#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int iv,t,len,temp1,j,f;
    char bv[16];
    char cbv[16],temp2;

    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        f = 1;
        j=0;
        scanf("%d",&iv);
        scanf("%s",bv);
        len = strlen(bv);
        /*for(int k=0;k<=len;k++)
        {
            cbv[k] = '0';
        }*/
        while(iv)
        {
            temp1 = iv%2;
            temp2 = temp1 + '0';
            cbv[j++] = temp2;
            iv = iv/2;
        }
        for(int k=0;k<=len;k++)
        {
            j=len;
            /*if(bv[k] != cbv[j])
            {
               f = 0;
               break ;
            }
            else
            {
                f = 1;
            }*/
            cout << cbv[j--];
        }
        /*if(f == 1)
        {
           printf("Case %d: Yes\n",i);
        }
        else
        {
            printf("Case %d: No\n",i);
        }*/
    }
    return 0;

}
