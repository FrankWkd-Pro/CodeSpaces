#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,op,k;
vector <int> v;
map<int,int> mp;
int logg(int x){
	int sum = 0;
	while(x > 0){
		x /= 2;
		sum++;
	}
	return sum-1;
}
signed main() {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>op>>k;
		if(op == 1){
			v.push_back(k);
		}else{
			int anss = 0;
			for(auto i : v){
				if(i < k)
				anss += logg(k-i);
			}
			cout<<anss<<"\n";
			mp[k] = anss;
		}
	}
	return 0;
}

