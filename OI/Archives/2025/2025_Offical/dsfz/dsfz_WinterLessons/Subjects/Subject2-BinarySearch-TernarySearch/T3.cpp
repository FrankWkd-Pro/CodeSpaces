#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[2101010];
int ans;
inline bool check(int mid){
	int dis = a[1],mm = 1;
	for(int i = 2;i <= n;i++){
		if(a[i]-dis >= mid){
			mm++;
			dis = a[i];
		}
	}
	return mm >= m;
}
int main(){
	cin>>n>>m;
	int l = 1,r = -99;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		l = min(l,a[i]-a[i-1]);
	}
	r = a[n]-a[1];
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid)){
			l = mid+1;
		}else r = mid-1;
	}
	cout<<l-1<<endl;
	return 0;
}

