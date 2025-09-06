#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10, MOD = 1e9+7;
const int P = 131;

typedef unsigned long long ull;
//离散化
long long a[N];
int maxx = 0;
long long b[N];
long long ans[N];
long long n;
long long k;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[++k] = a[i];
	}
	sort(b + 1, b + 1 + k);
	k = unique(b + 1, b + 1 + k) - b - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(b + 1, b + 1 + k, a[i]) - b;
	}
	/*
	1 2 3 2 1
	i = 3
	j = 4
	maxx = 3
	ans[1] = 0
	ans[2] = 2
	ans[3] = 1
	
	*/
	int i = 1, j = 1;
	ans[a[1]]++;
//  cout<<ans[a[i]]<<" "<<ans[a[j+1]]<<endl;
	while (j < n) {
		while (ans[a[j + 1]] != 0) {
			ans[a[i]]--;//ans是桶！！！！不要直接下标，要加a[]!!
			i++;
//          cout<<i<<" "<<j<<endl;
		}
		
		if (ans[a[j + 1]] == 0) {
			j++;
			ans[a[j]]++;
			maxx = max(maxx, j - i + 1);
		}
	}
	cout<<maxx;
	return 0;
}
