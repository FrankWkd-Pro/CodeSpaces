#include <bits/stdc++.h>
using namespace std;
#define P pair<int,int>
struct edge{
	int to,len;
};
int n,m,ans,tot,cnt;
vector<edge> e[1110101];
int dis[1101010];//当前点到联通块的距离
bool vis[1101010];

void prim(int rt){
	priority_queue <P,vector<P>,greater <P> > q;
	dis[rt] = 0;
	q.push(P(dis[rt],rt));
	while(!q.empty()){
		int u = q.top().second,w = q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		ans += w;
		for(auto v:e[u]){
			if(dis[v.to] > v.len){
				dis[v.to] = v.len;
				q.push(P(dis[v.to],v.to));
			}
		}
		
	}
}

int main(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		tot += w;
	}
	prim(1);
	cout<<tot-ans<<endl;
	
}
