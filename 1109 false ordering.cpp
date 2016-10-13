#include<bits/stdc++.h>
using namespace std;
#define a 1500
vector< pair<int,int> >v;
int arr[a];
int prime[1005],k,f[20],p[20],l,t;
bool compare(const pair<int,int>&i,const pair<int,int>&j){
    if(i.second == j.second) return i.first > j.first;
    return i.second < j.second;
}

void sieve(){
    int i,j;
    k = 1;
    prime[0] = 2;
    int sn = sqrt((double)a);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 0;
    for(i=3;i<=sn;i+=2)
    {
        if(arr[i] == 0)
        {
        	prime[k++] = i;
            for(j=i*i;j<a;j+=2*i)
            {
                arr[j] = 1;
            }
        }
    }
}

int number_of_devisor(int n){
    int dev = 1;
	int sq = sqrt(n),cnt = 0;
	l =0;
	for(int i =0; i < k && prime[i] <= sq; i++ ){
		if(n%prime[i] == 0){
			cnt = 0;
			while(n%prime[i] == 0){
				cnt++;
				n/= prime[i];
			}
			f[l] = prime[i];
			p[l] = cnt;
			l++;
			sq = sqrt(n);
		}
	}
	if(n > 1){
		f[l] = n;
		p[l] = 1;
	}
	for(int i = 0; i <= l; i++){
        dev *= (p[i]+1);
	}
	memset(p,0,sizeof(p));
	memset(f,0,sizeof(f));
	return dev;
}
int main(){
    sieve();
    for(int i = 1; i <= 1000; i++){
        v.push_back(make_pair(i,number_of_devisor(i)));
    }
    sort(v.begin(),v.end(),compare);
    scanf("%d",&t);
    int p;
    for(int i = 1; i <= t; i++){
        cin >> p;
        printf("Case %d: %d\n",i,v[p-1].first);
    }
    return 0;
}
