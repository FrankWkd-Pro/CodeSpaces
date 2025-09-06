#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
}a[101010];
int n;
bool cmp(node xx,node yy){
	return xx.y < yy.y;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	int ans = 1,ls;
	ls = a[1].y;
	for(int i = 2;i <= n;i++){
		if(a[i].x >= ls) ans++,ls = a[i].y;
	}
	cout<<ans<<endl;
} 
