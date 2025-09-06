#include <bits/stdc++.h>
using namespace std;
//Kruskal
int f[101010];
struct node{
	int x,y,z;
}a[1010101];
int n,m,ans,cnt,tot;
int find(int x){
	if(f[x] != x)  return f[x] = find(f[x]);
	return x;
}
bool cmp(node xx,node yy){
	return xx.z < yy.z;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		f[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int p,x,y,z;
		cin>>p>>x>>y>>z;
		if(p == 1){
			f[find(x)] = f[find(y)];
			tot++;
			ans += z;
		}else{
			cnt++;
			a[cnt].x = x;
			a[cnt].y = y;
			a[cnt].z = z;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	
	for(int i = 1;i <= cnt;i++){
//		if(tot == n-1) break;
		if(find(a[i].x) != find(a[i].y)){
			ans += a[i].z;
			tot++;
			f[find(a[i].x)] = find(a[i].y);
		}
//		if(tot == n-1) break;
	}
	cout<<ans<<endl;
}
