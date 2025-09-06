#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int n,m;
int ans = 1;
bool f[1010][1010];

void dfs(int x,int y){
    int dx[5] = {0,0,-1,0,1};
    int dy[5] = {0,1,0,-1,0};
    for(int i = 1;i <= 4;i++){
        int xx = x+dx[i],yy = y+dy[i];
        if(xx >= 1 && xx <= m && yy >= 1 && yy <= n && f[xx][yy] == false){
            if(a[xx][yy] == '.'){
                f[xx][yy] = true;
                dfs(xx,yy);
                ans++;
            }
        }
    }
}


int main(){
	while(1){
		ans = 1;
		memset(f,false,sizeof(f));
	    cin>>n>>m;
	    if(n == 0 and m == 0) return 0;
	    int x,y;
	    for(int i = 1;i <= m;i++){
	        for(int j = 1;j <= n;j++) {
	            cin>>a[i][j];
	            if(a[i][j] == '@') x = i,y = j;
	        }
	    }
	    dfs(x,y);
	//  for(int i = 1;i <= n;i++){
	//      for(int j = 1;j <= m;j++){
	//          if(f[i][j] && a[i][j] == '.') ans++;
	//      }
	//  }
	    cout<<ans<<endl;
	}
}
