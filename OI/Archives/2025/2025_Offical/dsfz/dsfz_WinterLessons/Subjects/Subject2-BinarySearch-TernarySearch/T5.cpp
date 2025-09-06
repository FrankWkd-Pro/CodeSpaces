#include <bits/stdc++.h>
using namespace std;
int n;
double a[101010],b[101010],c[101010];
double f(double x){
	double mx = -1e9;
	for(int i = 1;i <= n;i++) mx = max(mx,a[i]*x*x+b[i]*x+c[i]);
	return mx;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		double l = 0,r = 1000;
		while(r-l>1e-11){
			double m1 = l+(r-l)/3,m2 = r-(r-l)/3;
			if(f(m1) <= f(m2)) r = m2;
			else l = m1;
		}
		printf("%.4lf\n",f(r));
	}
}

