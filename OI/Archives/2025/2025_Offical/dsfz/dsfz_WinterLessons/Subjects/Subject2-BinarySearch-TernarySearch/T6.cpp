#include <bits/stdc++.h>
using namespace std;
int t;
double hb,h,d;
double f(double x){
	double l = hb-(d*(hb-h)/x);
	return d-x+l;
}
int main(){
	cin>>t;
	while(t--){
		cin>>hb>>h>>d;
		double l = d-(h*d/hb),r = d;
		while(r-l >= 1e-5){
			double m1 = l+(r-l)/3,m2 = r-(r-l)/3;
			if(f(m1) < f(m2)) l = m1;
			else r = m2;
		}
		printf("%.3lf\n",f(r));
	}	
}

