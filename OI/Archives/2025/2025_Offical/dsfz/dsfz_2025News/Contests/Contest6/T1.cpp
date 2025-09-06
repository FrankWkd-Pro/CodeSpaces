#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;

struct node{
	int l,r;
}a[1010];
int n;
bool cmp(node ii,node jj){
	if(ii.r < jj.r or (ii.r == jj.r and ii.l > jj.l)) return true;
	return false;
}
int main() {
	cin>>n;
//	int maxx = 0;
	for(int i = 1;i <= n;i++){
		cin>>a[i].l>>a[i].r;
//		maxx = max(maxx,a[i].r);
	}
	sort(a+1,a+1+n,cmp);
//	for(int i = 1;i <= n;i++){
//		cout<<a[i].l<<" "<<a[i].r<<endl;
//	}
	int t1 = 0,t2 = 0;
	
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(t1 < t2) swap(t1,t2);
		if(t1 <= a[i].l) t1 = a[i].r,ans++;
		else if(t2 <= a[i].l) t2 = a[i].r,ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}
