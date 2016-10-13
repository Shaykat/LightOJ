#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define s 100010
int arr[s];
int lowerBound(int k,int n){
    int beg,ed,index,mid=0;

    beg = 0;
    ed = n - 1;

    while(beg <= ed){
        mid = (beg + ed)/2;
        if(k == arr[mid]){
            index = mid;
            ed = mid - 1;
        }
        else if(k > arr[mid]){
            beg = mid + 1;
        }
        else {
            ed = mid - 1;
        }
    }
    return beg;
}

int uperBound(int p,int n){
    int beg,ed,index,mid=0;

    beg = 0;
    ed = n - 1;

    while(beg <= ed){
        mid = (beg + ed)/2;
        if(p == arr[mid]){
            index = mid;
            beg = mid + 1;
        }
        else if(p > arr[mid]){
            beg = mid + 1;
        }
        else {
            ed = mid - 1;
        }
    }
    return beg;
}

int main(){
    int q,t,n;
    int a,b,d;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
             d = 0;
        scanf("%d%d",&n,&q);
        for(int j = 0; j < n; j++){
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+n);
        printf("Case %d:\n",i);

        while(q--){
            scanf("%d%d",&a,&b);
            d = uperBound(b,n) - lowerBound(a,n);
            printf("%d\n",d);
        }
    }
}
/*
1

5 3

1 4 6 8 10

0 5

6 10

7 100000
*/
