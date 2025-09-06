#include <bits/stdc++.h>
using namespace std;
struct node{
	int w,id;
}e[1010];
int a[1010],b[1010],n;
bool cmp(node xx,node yy){
	return xx.w < yy.w;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++) cin>>b[i];
	for(int i = 1;i <= n;i++) e[i] = {min(a[i],b[i]),i};
	sort(e+1,e+1+n,cmp);
	int q[1010] = {0},l = 0,r = n+1;
	for(int i = 1;i <= n;i++)
		if(e[i].w == a[e[i].id]) q[++l] = e[i].id;
		else q[--r] = e[i].id;
	int ta = 0,tb = 0;
	for(int i = 1;i <= n;i++){
		ta += a[q[i]];
		tb = max(ta,tb);
		tb += b[q[i]];
	}
	cout<<tb<<endl;
}
