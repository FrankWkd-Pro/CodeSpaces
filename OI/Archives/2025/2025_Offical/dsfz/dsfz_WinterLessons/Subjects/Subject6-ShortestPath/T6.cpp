#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
//SPFa

int dis[1010101];

struct node{
	int to,len;
};
int T;
int n,m,k;
bool vis[1010110],st[1001230];
int num[1010101];
vector<node> e[1010101];
void init(){
	memset(dis,inf,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(st,0,sizeof st);
	memset(num,0,sizeof num);
	for(int i = 1;i<=n;i++){
		e[i].clear();
	}
}
bool spfa(int s){
	queue <int> q;
	dis[s] = 0;
	q.push(s);    
	vis[s] = 1;
	num[s]=1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		st[u]=1;
		for(auto v:e[u]){
			if(dis[v.to] > dis[u]+v.len){
				dis[v.to] = dis[u]+v.len;
				if(!vis[v.to]){
					num[v.to]++;
					if(num[v.to] > n - 1) return 1;
					q.push(v.to);
					vis[v.to] = 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		init();
		for(int i = 1;i <= m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		for(int i = 1;i <= k;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[u].push_back({v,-w});
		}
		if(spfa(1)){
			puts("YES");
			goto Fuck_Everybody;
		}
		puts("NO");
		Fuck_Everybody:;
	}
}
