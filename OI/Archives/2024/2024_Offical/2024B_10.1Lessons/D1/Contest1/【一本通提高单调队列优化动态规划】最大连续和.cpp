#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int a[N],sum[N];
struct node {
	int pos,val;
} q[N];
int n,m;
int l,r;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) {
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	a[0]=0;
	q[r].pos=0;
	q[r++].val=0;
	for(int i=1; i<=n; ++i) {
		while(l<r&&(i-q[l].pos+1)>m)
			l++;
		while(l<r&&q[r-1].val>=sum[i])
			r--;
		q[r].pos=i;
		q[r++].val=sum[i];
		a[i]=q[l].val;
	}
	int ma=-inf;
	for(int i=0; i<n; ++i)
		ma=max(ma,sum[i+1]-a[i]);
	printf("%d\n",ma);
	return 0;
}
