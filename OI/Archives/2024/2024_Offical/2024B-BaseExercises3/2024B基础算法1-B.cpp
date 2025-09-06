//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int a[100010];
int check(int x,int op){
	if(a[x] >= op and a[x-1] <= op){
		if(abs(a[x]-op) >= abs(a[x-1]-op)){
			printf("%d\n",a[x-1]);
			return 0;
		}else{
			printf("%d\n",a[x]);
			return 0;
		}
	}
	if(a[x] > op) return 2;
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	int m;
	for(int i = 1;i <=  n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	scanf("%d",&m);
	while(m--){
		int op;
		cin>>op;
		if(op > a[n]){
			printf("%d\n",a[n]);
			continue;
		}
		if(op < a[1]){
			printf("%d\n",a[1]);
			continue;
		}
		int l = 1,r = n;
		while(l <= r){
			int mid = l+r>>1;
			int xum = check(mid,op);
			if(xum == 0) break;
			else if(xum == 1) l = mid+1;
			else r = mid-1; 
		}
	}
	return 0;
}

