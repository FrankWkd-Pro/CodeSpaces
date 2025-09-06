#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int u,v,w;
}a[1010101];
bool cmp(node xx,node yy){
	return xx.w < yy.w;
}
int f[1010101];
int cnt,ans,tot;
int find(int x){
	if(f[x] != x) return f[x] = find(f[x]);
	return x;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n+1;i++) f[i] = i;
	for(int i = 1;i <= n;i++){
		int v;
		scanf("%d",&v);
		a[++cnt] = {i,n+1,v};//将发电站的建造费用转化成边权
		
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			int w;
			cin>>w;
			if(i < j) {
				a[++cnt] = {i,j,w};
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int tot = 0;
	for(int i = 1;i <= cnt;i++){
		int fu = find(a[i].u),fv = find(a[i].v);
		if(fu != fv){
			f[fu] = fv;
			ans += a[i].w;
			tot++;
		}
		if(tot >= n) break;
	}
	cout<<ans<<endl;
}
