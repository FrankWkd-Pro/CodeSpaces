#include <bits/stdc++.h>
using namespace std;

int f[5000010];

struct node{
	int x,y,z;
}e[5010100];

int a[1100][1100];
int n,m,k=0,o,p,q,r;
int ans;

int fe(int i,int j){
	return m*(i-1)+j;
}

int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}

bool cmp(node i,node j){
	return i.z < j.z;
}

void kruskal(){
	sort(e+1,e+k+1,cmp);//一定要注意排序！
	for(int i = 1;i <= k;i++){
		if(find(e[i].x) != find(e[i].y)){
			f[find(e[i].x)] = find(e[i].y);
			ans += e[i].z;
		}
	}
}

int main(){
	
	cin>>n>>m;//n行m列
	for(int i = 1;i <= n*m;i++){
		f[i] = i;
	}
	while(cin>>o>>p>>q>>r){
		f[find(fe(o,p))] = f[find(fe(q,r))];
	}
	for(int i = 1;i < m;i++){
		for(int j = 1;j <= n;j++){//注意：fe函数的格式为：fe(行,列)！！注意i、j顺序！！！
			k++;
			e[k].x = fe(j,i);
			e[k].y = fe(j,i+1);
			e[k].z = 2;
		}
	}
	for(int i = 1;i < n;i++){
		for(int j = 1;j <= m;j++){
			k++;
			e[k].x = fe(i,j);
			e[k].y = fe(i+1,j);
			e[k].z = 1;
		}
	}
	kruskal();
	cout<<ans<<endl;
	return 0;
}

