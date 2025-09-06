#include <bits/stdc++.h>
using namespace std;

int n,l = INT_MIN,r,m;
int a[1010001]; 

bool check(int mid){
	int tot = 0;
	int times = 1;
	for(int i = 1;i <= n;i++){
		if(tot+a[i] <= mid) tot += a[i];
		else tot = a[i],times++;
	}
	return times <= m;
}

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		l = max(l,a[i]);
		r += a[i];
	}
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid)) r = mid-1;
		else l = mid+1;
	}
	cout<<l<<endl;
	return 0;
}

