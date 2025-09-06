#include <bits/stdc++.h>
using namespace std;
//Kruskal
int f[101010];
struct node{
	int x,y,z;
}a[1010101];
int n,m,ans = -1,cnt,tot;
int find(int x){
	if(f[x] != x)  return f[x] = find(f[x]);
	return x;
}
bool cmp(node xx,node yy){
	return xx.z < yy.z;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		++cnt;
		cin>>a[cnt].x>>a[cnt].y>>a[cnt].z;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i <= n;i++){
		f[i] = i;
	}
	for(int i = 1;i <= cnt;i++){
		if(find(a[i].x) != find(a[i].y)){
			ans = max(ans,a[i].z);
			tot++;
			f[find(a[i].x)] = find(a[i].y);
		}
		if(tot == n-1) break;
	}
	cout<<n-1<<" "<<ans<<endl;
}
