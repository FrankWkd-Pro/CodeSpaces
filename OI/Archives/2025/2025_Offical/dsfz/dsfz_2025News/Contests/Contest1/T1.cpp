#include<bits/stdc++.h>
using namespace std;
unsigned long long a[5010],n,k;
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i];
	unsigned long long ans =0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			if(a[i] > a[j]) ans += k*(k-1)/2;
		}
		for(int j = i+1;j <= n;j++){
			if(a[i] > a[j]) ans += k*(k+1)/2;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
