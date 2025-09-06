//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
//二分check：查看是否可以一种策略使得最终快乐值为mid！ 
int d,n,h[50010];

bool check(int x){
	int minn = INT_MAX;
	int kkk = 0;
	int kuai = 1;
	for(int i = 1;i <= d;i++){
		 
		while(kkk < x and kuai <= n){
			kkk += h[kuai++];
		}
		minn = min(minn,kkk);
		kkk>>=1;
	}
	return minn >= x;
}


int main(){
	scanf("%d%d",&n,&d);
	int l = INT_MAX,r = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&h[i]);
		l = min(l,h[i]);
		r += h[i];
	}
	
	while(l <= r){
		int mid = l+r>>1;
		bool xx = check(mid);
		if(xx){
			l = mid+1;
		}
		else {
			r = mid-1;
		}
	}
	printf("%d\n",l-1);
	return 0;
}

