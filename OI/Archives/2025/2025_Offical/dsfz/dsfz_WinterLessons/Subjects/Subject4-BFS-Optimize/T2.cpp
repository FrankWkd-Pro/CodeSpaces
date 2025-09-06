#include<bits/stdc++.h>
using namespace std;
int t,tx,ty;
char a[1010][1010];
bool f[1005][1005];
int dx[9]={0,1,1,2,2,-1,-1,-2,-2};
int dy[9]={0,2,-2,1,-1,2,-2,1,-1};
struct node{
	int aa,bb,cc;
};	
int n,m;
int bfs(int tx,int ty){
	queue<node> q;
	q.push({tx,ty,0});
	f[tx][ty]=1;
	while(!q.empty()){
		int x=q.front().aa,y=q.front().bb,st = q.front().cc;
		if(a[x][y] == 'H') return st;
		q.pop();
		for(int i=1;i<=8;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=1 && xx<=n && yy>=1 && yy<=m && !f[xx][yy] and a[xx][yy] != '*'){
				q.push({xx,yy,st+1});
				f[xx][yy]=1;
				if(a[xx][yy] == 'H') return st+1;
			}
		}
	}
	return -1;
}

int main(){

	cin>>m>>n;
	int s,t;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			if(a[i][j] == 'K') s = i,t = j;
		}
	}
	cout<<bfs(s,t)<<endl;
	return 0;
}
