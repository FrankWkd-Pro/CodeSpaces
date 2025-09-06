#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;
int vis[500000],n,m,p;
int dis[500000],tot,ans=inf;
int head[500000],sum;
int id[500000];
struct edge{
	int next,to,dis;
}e[1000000];
struct node{
	int dis,pos;
	bool operator <(const node&x)const{//重载
		return x.dis<dis;
	}
};
priority_queue<node>q;
inline void add(int x,int y,int w){//加边 
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
	e[tot].dis=w;
}
void dijkstra(int s){//堆优化dijkstra 
	for(int i=1;i<=p;++i)dis[i]=inf;
	memset(vis,0,sizeof(vis));
	dis[s]=0,q.push((node){0,s});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int x=tmp.pos;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].dis){
				dis[y]=dis[x]+e[i].dis;
				if(!vis[y])q.push((node){dis[y],y});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&p,&m);
	for(int i=1;i<=n;++i)scanf("%d",&id[i]);
	for(int i=1;i<=m;++i){
		int a,aa,aaa; 
		scanf("%d%d%d",&a,&aa,&aaa);
		add(a,aa,aaa);
		add(aa,a,aaa); 
	}
	for(int i=1;i<=p;++i){
		dijkstra(i);
		sum=0;
		for(int j=1;j<=n;++j)sum+=dis[id[j]];
		ans=min(ans,sum);
	}printf("%d\n",ans);
	return 0;
}
