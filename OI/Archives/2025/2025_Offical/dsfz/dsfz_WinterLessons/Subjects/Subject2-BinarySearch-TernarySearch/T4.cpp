#include <bits/stdc++.h>
using namespace std;
int a[101010],n,L;
double b[101010];
int main(){
	cin>>n;
	cin>>L;
	int maxx = 0;
	for(int i = 1;i <= n;i++) cin>>a[i],maxx = max(maxx,a[i]);
	double l = 0,r = maxx*1.0,mid;
	while(r-l > 1e-5){
		mid = (l+r)/2;
		for(int i = 1;i <= n;i++) 
		b[i] = (b[i-1]+a[i]*1.0-mid)*1.0;
		double ans = 0;
		bool fl = 0;
		for(int i = L;i <= n;i++){
			ans = min(ans,b[i-L]);
			if(b[i]-ans >= 0.0){
				fl = 1;
				break;
			}
		}
		if(fl == 1) l = mid;
		else r = mid;
	}
	cout<<(int)(r*1000)<<endl;
}

