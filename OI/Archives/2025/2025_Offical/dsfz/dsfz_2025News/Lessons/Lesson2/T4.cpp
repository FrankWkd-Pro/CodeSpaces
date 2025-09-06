#include<bits/stdc++.h>
using namespace std;
const int N = 200010, MOD = 1e9+7;
typedef unsigned long long ull;
const int P = 13331;
ull p[N],h[N],t[N];
int n;
int s[N],ans[N],tot,cnt,idx;
int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",s[i]);
	p[0] = 1;
	for(int i = 1;i <= n;i++){
		p[i] = p[i-1]*P;
		h[i] = h[i-1]*P+s[i];
	}
	for(int i = n;i >= 1;i--) t[i] = t[i+1]*P+s[i];
	for(int k = 1;k <= n;k++){
		unordered_map<ull,bool> mp;
		cnt = 0;
		for(int i = 1;i <= n-k+1;i += k){
			ull lh = h[i+k-1]-h[i-1]*p[k];
			ull rh = t[i]-t[i+k]*p[k];
			ull h = lh*rh;
			if(!mp[h]){
				mp[h] = 1;
				cnt++;
			}
		}
		if(cnt > tot){
			tot = cnt;
			idx = 1;
			ans[1] = k;
		}else if(cnt == tot) ans[++idx] = k;
	}
	printf("%d %d\n",tot,idx);
	for(int i = 1;i <= idx;i++) printf("%d ",ans[i]);
	return 0;
}
