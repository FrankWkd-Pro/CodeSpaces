#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
bool f[1010][1010]; 
struct node{
	int x,y;
};
queue <node> q;
int feng,gu,n;
bool h,l;
int dx[9] = {0,-1,-1,-1,0,1,1,1,0};
int dy[9] = {0,-1,0,1,1,1,0,-1,-1};
void bfs(int xxx,int yyy){
	f[xxx][yyy] = 1;
	q.push({xxx,yyy});
	while(!q.empty()){
		node t = q.front();
		q.pop();
		for(int i = 1;i <= 8;i++){
			int xx = t.x+dx[i],yy = t.y+dy[i];
			if(xx >= 1 and xx <= n and yy >= 1 and yy <= n)
				if(a[xx][yy] > a[t.x][t.y]) h = 1;
				else if(a[xx][yy] < a[t.x][t.y]) l = 1;
				else if(a[xx][yy] == a[t.x][t.y] and !f[xx][yy]){
					f[xx][yy] = 1;
					q.push({xx,yy});
				}
		}
	}
}

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(!f[i][j]){
				h = l = 0;
				bfs(i,j);
				if(!h) feng++;//周围没有比我高的了 
				if(!l) gu++;//周围没有比我低的了 
			}
		}
	}
	cout<<feng<<" "<<gu<<endl;
}
