#include<bits/stdc++.h>
using namespace std;
const int N = 1010000, MOD = 1e9+7;
const int P = 131;
int n,m;
char p[N];
int ne[N];

int main() {
	scanf("%d%s",&n,p+1);
	for(int i = 2,j = 0;i <= n;i++){
		while(j and p[i] != p[j+1]) j = ne[j];
		if(p[i] == p[j+1]) j++;
		ne[i] = j;
//		cout<<ne[i]<<" ";
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		int j = i;
		while(ne[j] != 0) j = ne[j];
		ans += i-j;
//		cout<<i<<" ";
		if(ne[i]) ne[i] = j;
	}
	cout<<ans<<endl;
	return 0;
}
