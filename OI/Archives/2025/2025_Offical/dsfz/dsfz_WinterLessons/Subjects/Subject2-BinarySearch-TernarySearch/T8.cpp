#include <bits/stdc++.h>
using namespace std;
long long a[10101010];
long long n,k;
bool check(int x){
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		ans += a[i]/x;
	}
	return ans >= k;
}
int main(){
	cin>>n>>k;
	long long l = 1,r = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		r += a[i];
	}
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid)) l = mid+1;
		else r = mid-1;
	}
	cout<<l-1;
}
