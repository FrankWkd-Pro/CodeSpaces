#include <bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,len;
}e[1001000];
int a[1010][1010],n,m,cnt;
int f[1010100];//并查集
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool is_sel[1010100];//是否被买过
bool cmp(edge xx,edge yy){
	return xx.len < yy.len;
}
void merge(int x,int y){
	f[find(x)] = f[find(y)];
}
int main(){
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			a[i][j] += a[i][j] == 0 ? n : 0;
			if(i != j){
				e[++cnt] = {min(i,j),max(i,j),a[i][j]};//邻接矩阵转存
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int noww = 0,ans = 0;//记录已经联通的点的数量和当前花费
	for(int i = 1;i <= m;i++) f[i] = i;//初始化并查集
	for(int i = 1;i <= m;i++){
		if(find(e[i].from) != find(e[i].to)){
			if(is_sel[e[i].from] == 0 and is_sel[e[i].to] == 0){
				s
			}
			cout<<e[i].from<<" "<<e[i].to<<endl;
			merge(e[i].from,e[i].to);
			noww++;
			ans += e[i].len;
		}
		if(noww == m-1){
			cout<<ans<<endl;
			return 0;
		}
	}
	
}
