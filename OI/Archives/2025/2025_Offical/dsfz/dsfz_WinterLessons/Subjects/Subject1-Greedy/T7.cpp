#include <bits/stdc++.h>
using namespace std;

int a[1010101];
long long c[1010101];
long long sum,n;
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	long long ave = sum/n;
	for(int i = n;i >= 1;i--) c[i] = c[i+1]+ave-a[i];
	c[1] = 0;
	sort(c+1,c+1+n);
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		ans += abs(c[i]-c[(n+1)/2]);
	}
	cout<<ans<<endl;
}
