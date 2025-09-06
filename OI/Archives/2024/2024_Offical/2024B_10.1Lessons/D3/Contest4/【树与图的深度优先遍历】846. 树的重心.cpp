#include <bits/stdc++.h> 
using namespace std;
const int N=100010;
int h[N],e[N*2],ne[N*2],idx,ans=N;
bool st[N];
int n;
void add(int a,int b) {
	e[idx]=b;
	ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u) {
	st[u]=true;
	int size=0,sum=0;
	for(int i=h[u]; i!=-1; i=ne[i]) {
		int j=e[i];
		if(st[j]) continue;
		int s=dfs(j);
		size=max(size,s);
		sum+=s;
	}
	size=max(size,n-sum-1);
	ans=min(ans,size);
	return sum+1;
}
int main() {
	memset(h, -1, sizeof h);
	cin>>n;
	for(int i=0; i<n-1; i++) {
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
