#include<bits/stdc++.h>
using namespace std;
const int N = 1010, M = 200010;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
int n,m,S,T,K;
int h[N],rh[N],e[M],w[M],ne[M],idx;
int dist[N],cnt[N];
bool st[N];

void add(int h[],int a,int b,int c){
	e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a]=idx++;
}
void dij(){
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	heap.push({0,T});
	memset(dist,0x3f,sizeof dist);
	dist[T] = 0;
	while(heap.size()){
		PII t = heap.top();
		heap.pop();
		int ver = t.second;
		if(st[ver]) continue;
		st[ver] = true;
		for(int i = rh[ver];~i;i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[ver]+w[i]){
				dist[j] = dist[ver]+w[i];
				heap.push({dist[j],j});
			}
		}
	}
}
int Astar(){
	priority_queue<PIII,vector<PIII>,greater<PIII> > heap;
	heap.push({0+dist[S],{0,S}});
	int cnt = 0;
	while(heap.size()){
		PIII t = heap.top();
		heap.pop();
		int ver=t.second.second,distance = t.second.first;
		if(ver == T) cnt++;
		if(cnt == K) return distance;
		for(int i = h[ver];~i;i=ne[i]){
			int j = e[i];
			heap.push({distance+w[i]+dist[j],{distance+w[i],j}});
		}
	}
	return -1;
}
int main() {
	scanf("%d%d",&n,&m);
	memset(h,-1,sizeof h);
	memset(rh,-1,sizeof rh);
	for(int i = 0;i <m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(h,a,b,c);
		add(rh,b,a,c);
	}
	scanf("%d%d%d",&S,&T,&K);
	if(S == T) K++;
	dij();
	printf("%d",Astar());
	return 0;
}
