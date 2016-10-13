#include<cstdio>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    char string[2000],sub_string[2000];
    int i,j,k,len;

    while(1)
    {
       j=0,k=0;
       cin.getline(string,2000);
       if( string == "DONE")
       {
           break;
       }
       len = strlen(string);
       for(i=0;i<=len;i++)
       {
           if(string[i] != ' '&&string[i] != ','&&string[i] != '!'&&string[i] != '?'&&string[i] != '.')
           {
               sub_string[j++] = string[i];
           }
       }
       sub_string[j] = '\0';
       //cout << sub_string;
       for(i=j-1;i>=0;i--)
       {
            string[k++] = sub_string[i];
       }
       string[k] = '\0';
       if(string == sub_string)
       {
           printf("You won't be eaten!\n");
       }
       else
       {
            printf("Uh oh..\n");
       }
    }
    return 0;
}
