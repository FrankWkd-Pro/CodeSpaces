#include <bits/stdc++.h>
using namespace std;
int n,a[2010][3];
double minn = 9999999.0;
int mai,maj;
double calc(int aa,int bb){
	return sqrt((a[aa][1]-a[bb][1])*(a[aa][1]-a[bb][1])+(a[aa][2]-a[bb][2])*((a[aa][2]-a[bb][2])));
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
		//	cout<<i<<" "<<j<<" "<<calc(i,j)<<endl;
			if(calc(i,j) < minn) minn = calc(i,j),mai = i,maj = j;
		}
	}
	cout<<mai<<" "<<maj<<endl;
}
