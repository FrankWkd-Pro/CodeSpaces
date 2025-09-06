#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
int ans[10100];
int n,m;
int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			int x;
			cin>>x;
			ans[x]++;
		}
	}
	int maxx = 0,maxi;
	for(int i = 1;i <= 1000;i++){
		if(ans[i] > maxx) maxx = ans[i],maxi = i;
	}
	if(maxx >= m) cout<<maxi;
	else cout<<0;
	return 0;
}
