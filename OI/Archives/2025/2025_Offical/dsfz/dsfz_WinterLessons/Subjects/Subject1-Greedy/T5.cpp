#include <bits/stdc++.h>
using namespace std;

struct node{
	int t,w;
	bool operator<(const node &W) const{
		return w>W.w;
	}
}a[1010];
bool st[1010];
int n,m;
int main(){
 	cin>>m>>n;
 	for(int i = 1;i <= n;i++) cin>>a[i].t;
 	for(int i = 1;i <= n;i++) cin>>a[i].w;
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		bool flag = false;
		for(int k = a[i].t;k >= 1;k--){
			if(!st[k]){
				flag = true;
				st[k] = 1;
				break;
			}
		}
		if(!flag) m -= a[i].w;
		
	}
	cout<<m<<endl;
} 
