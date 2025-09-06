#include<bits/stdc++.h>
using namespace std;
const int maxn=110;

int n,dep;

int a[maxn];
bool dfs(int k) {
	if(k>dep) {
		if(a[dep]==n) return true;
		else return false;
	}
	bool v[maxn]= {false};
	for(int i=k-1; i>=1; i--)
		for(int j=k-1; j>=1; j--) {
			if(a[i]+a[j]<=a[k-1]) break;
			if(a[i]+a[j]<=n && !v[a[i]+a[j]]) {
				v[a[i]+a[j]]=true;
				a[k]=a[i]+a[j];
				if(dfs(k+1)) return true;
			}
		}
	return false;
}

int main() {
	while(scanf("%d",&n),n!=0) {
		if(n==1) {
			printf("1\n");
			continue;
		}
		dep=1;
		a[1]=1;
		while(1) {
			dep++;
			if(dfs(2)) {
				for(int i=1; i<dep; i++) printf("%d ",a[i]);
				printf("%d\n",a[dep]);
				break;
			}
		}
	}
	return 0;
}
