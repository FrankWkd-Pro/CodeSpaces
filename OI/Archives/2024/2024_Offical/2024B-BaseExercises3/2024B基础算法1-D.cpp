//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}a[200];
bool cmp(node x,node y){
	if(x.l == y.l) return x.r<y.r;
	return x.l<y.l; 
}
int n; 
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		int ll,rr;
		scanf("%d%d",&ll,&rr);
		a[i].l = ll;
		a[i].r = rr;
	}
	bool aa = false;
	int la = -1;
	int lb = -1;
	bool bb = false;
	int ans = 0;
	sort(a+1,a+1+n,cmp);
//	for(int i = 1;i <= n;i++){
//		cout<<a[i].l<<" "<<a[i].r<<endl;
//	}
	for(int i = 1;i <= n;i++){
		if(a[i].l >= la){
			la = a[i].r,ans++;
		}else if(a[i].l >= lb){
			lb = a[i].r;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

