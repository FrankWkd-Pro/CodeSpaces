#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010][1010];
struct link{
	int u,v,w;
	bool operator < (const link &ret) const{
		return w<ret.w;//从大到小
	}
}e[1101010];
int cnt,ans,tot;
int f[1010101];
int find(int x){
	if(x != f[x]) return f[x] = find(f[x]);
	return x;
}



int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d",&a[i][j]);
			if(i < j) e[++cnt] = {i,j,a[i][j]};
		}
	}
	for(int i = 1;i <= n;i++) f[i] = i;
	sort(e+1,e+cnt+1);
	for(int i = 1;i <= cnt;i++){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		int fu = find(u),fv = find(v);
		if(fu!= fv){
			f[fu] = fv;
			tot++;
			ans += w;
		}
		if(tot == n-1) break;
	}
	cout<<ans<<endl;
}

