#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m;
typedef pair< int, int > P;
struct node {
	int to, len;
};
int dis[1010101];
vector<node> e[N + 10];
bool vis[1010101];
void dijkstra(int s) {
	priority_queue < P, vector<P>, greater<P> > q;
	dis[s] = 0;
	q.push({dis[s],s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(auto v:e[u]){
			if(dis[v.to] > dis[u]+v.len){
				dis[v.to] = dis[u]+v.len;
				q.push({dis[v.to],v.to});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(dis, 0x3f3f3f3f, sizeof dis);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	dijkstra(1);
	int ans = -1;
	for(int i = 1;i <= n;i++){
		ans = max(ans,dis[i]);
	}
	if(ans >= 0x3f3f00000){
		cout<<-2<<endl;
	}else{
		cout<<ans<<endl;
	}
}
