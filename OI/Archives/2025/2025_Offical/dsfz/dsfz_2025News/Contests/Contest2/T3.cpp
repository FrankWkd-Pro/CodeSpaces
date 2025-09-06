#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
int n,m,k;
int ans,maxx;
int a[1010][1010];
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 1;i <= m;i++){
		if(a[k][i] != 0){
			ans++;
		}else{
			maxx = max(ans,maxx);
			ans = 0;
		}
	}
	printf("%d",max(maxx,ans));
	return 0;
}
