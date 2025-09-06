#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans;
bool f[1010][1010];

void dfs(int x,int y,int st){
    int dx[15] = {0,1,2,2,1,-1,-2,-2,-1};
    int dy[15] = {0,2,1,-1,-2,-2,-1,1,2};
    if(st == n*m) {ans++;return ;}
    for(int i = 1;i <= 8;i++){
        int xx = x+dx[i],yy = y+dy[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && f[xx][yy] == false){
            f[xx][yy] = true;
            dfs(xx,yy,st+1);
            f[xx][yy] = false;
        }
    }
}


int main(){
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		ans = 0;
	    cin>>n>>m;
	    int x,y;
	    cin>>x>>y;
	    f[x][y] = 1;
	    dfs(x,y,1);
	    cout<<ans<<endl;
	}
}
