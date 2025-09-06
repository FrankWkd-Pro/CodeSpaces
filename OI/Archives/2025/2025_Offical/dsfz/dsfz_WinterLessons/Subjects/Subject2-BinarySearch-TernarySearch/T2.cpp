#include <bits/stdc++.h>
using namespace std;
int L,n,m;
int a[2101010];
int ans;
inline bool check(int mid){
	int times = 0,ip = 0;
	for(int i = 1;i <= n+1;i++){
		if(a[i]-a[ip] < mid){
			times++;
			if(times > m) return false;
		}else ip = i;
	}
	return times <= m;
}


int main(){
	cin>>L>>n>>m;	
	a[n+1] = L;
	int l = 1,r = L;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		l = min(l,a[i]-a[i-1]);
	}
	l = min(l,L-a[n]);
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid)){
			l = mid+1;
		}else r = mid-1;
	}
	cout<<l-1<<endl;
	return 0;
}

