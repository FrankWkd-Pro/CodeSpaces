//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int a[100100];
int n,l,c;
int ans;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	cin>>n>>l>>c;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 2;i <= n;i++){
		a[i] = abs(a[i-1]-a[i]);
	}	
	
	
	
	return 0;
}

