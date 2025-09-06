#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],ans,sum[101];
void dfs(int u,int v){
	if(v>=ans) return;
	if(u==n){
		ans=v;
		return;
	}
	for(int i=0;i<v;i++){
		if(sum[i]+a[u]<=m){
			sum[i]+=a[u];
			dfs(u+1,v);
			sum[i]-=a[u];
		}
	}
	sum[v]=a[u];
	dfs(u+1,v+1);
	sum[v]=0;
}
int main(){
	cin>>n>>m;
	ans=n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<int>());
	dfs(0,0);
	cout<<ans;
	return 0;
}
