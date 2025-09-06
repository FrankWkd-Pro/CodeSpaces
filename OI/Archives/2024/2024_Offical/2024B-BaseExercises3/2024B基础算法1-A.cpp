//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
 
struct node{
	int v,k;
}a[101];
int c,n;
bool cmp(node x,node y){
	return x.v < y.v;
}
//策略：从小到大对于每个v[i]，
//寻找是否存在>=n-v[i]的数，
//若存在，则删除这两个数，并ans加 
int main(){
	int ans = 0;
	scanf("%d%d",&n,&c);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].v,&a[i].k);
	} 
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n;i++){
		if(a[i].k <= 0) continue;
		for(int j = 1;j <= n;j++){
			if((i == j and a[j].k <= 1) or a[j].k <= 0 or a[i].k <= 0) continue;
			if(n-a[i].v <= a[j].v and a[i].v+a[j].v%n){
				while(a[i].k >= 1 and a[j].k >= 1){
					int t = a[i].v+a[j].v;
					ans += t/c;
					a[i].k--,a[j].k--;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(a[i].v>=n) ans += a[i].k;
	}
	printf("%d\n",ans);
	return 0;
}

