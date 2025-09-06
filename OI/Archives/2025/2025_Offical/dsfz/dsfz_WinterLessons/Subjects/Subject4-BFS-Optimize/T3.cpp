#include<bits/stdc++.h>
using namespace std;
int mp[10][10],vis[10][10],tt,hh,a[10][10];
int n;
struct node{
	int x,y;
}q[11*11],st[10][10],ans[10*10];
int dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1};
void bfs(int sx,int sy){
	hh=1,tt=0;
	q[++tt]={sx,sy};
	vis[sx][sy]=1;
	while(hh<=tt){
		int x=q[hh].x,y=q[hh++].y;
		for(int i=1;i<=4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>0&&xx<=n&&yy>0&&yy<=n&&!vis[xx][yy]&&mp[xx][yy]==0){
				q[++tt]={xx,yy};
				vis[xx][yy]=1;
				if(a[xx][yy]>a[x][y]+1){
					st[xx][yy]={x-1,y-1};
					a[xx][yy]=a[x][y]+1;
				}
			}
		}
	}
	return ;
}
int main(){
	//cin>>n;
	n=5;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	memset(a,0x3f3f3f,sizeof a);
	vis[1][1]=1;
	a[1][1]=0;
    bfs(1,1);
    int fx=5,fy=5,cnt=0;
    ans[++cnt]={fx-1,fy-1};
    while(1){
    	ans[++cnt]={st[fx][fy].x,st[fx][fy].y};
		int xxx=fx;
		fx=st[fx][fy].x+1;
		fy=st[xxx][fy].y+1;
    	if(st[fx][fy].x==0&&st[fx][fy].y==0){
    		break;
    	}
    }
    ans[++cnt]={0,0};
    for(int i=cnt;i>=1;i--){
    	cout<<"("<<ans[i].x<<", "<<ans[i].y<<")"<<"\n";
    }
    return 0;
}
