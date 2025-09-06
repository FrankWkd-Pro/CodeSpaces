#include <bits/stdc++.h>
using namespace std;
bool f[101010];
struct node{
	int x,y,z;
}a[101010];
int n;
bool cmp(node xx,node yy){
	return xx.y < yy.y;
}
int h;
int main(){
	cin>>n>>h;
	for(int i = 1;i <= h;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+1+h,cmp);
	int ans = 0;
	for(int i = 1;i <= h;i++){
		int lim = a[i].z;
		for(int j = a[i].x;j <= a[i].y and lim;j++){
			if(f[j]) lim--;
		}
		if(lim != 0){
			for(int j = a[i].y;j >= a[i].x and lim;j--){
				if(f[j]) continue;
				ans++;
				f[j] = true;
				lim--;
			}
		}
	}
	cout<<ans<<endl;
} 
