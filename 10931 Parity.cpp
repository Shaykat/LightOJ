#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    int n,i,t1,p;
    char binary[100],m_binary[100],t2;

    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
        break;

        p = n;
        i=0;
        while(n)
        {
            t1 = n%2;
            t2 = t1 + '0';
            binary[i++] = t2;
            n = n/2;
        }
        int k=0;
        for(int j=i-1;j>=0;j--)
        {
            m_binary[k++] = binary[j];
        }
        m_binary[k] = '\0';

        int c=0;
        for(i=0;i<k;i++)
        {
            if(binary[i] == '1')
            {
                c++;
            }
        }
        printf("The parity of %s is %d (mod 2).\n",m_binary,c);
    }

    return 0;
}
