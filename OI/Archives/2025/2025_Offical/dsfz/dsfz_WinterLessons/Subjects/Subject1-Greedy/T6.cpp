#include <bits/stdc++.h>
using namespace std;
int n,leisure,fish[200],trip[1010],delta[1010];
struct node{
	int id,key;
	bool operator < (const node &rhs)const{
		return key<rhs.key;
	}
};
int main(){
	cin>>n>>leisure;
	leisure *= 12;
	node t;
	int answer = -1;
	for(int i = 1;i <= n;i++){
		cin>>fish[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>delta[i];
	}
	for(int i = 1;i < n;i++){
		cin>>trip[i];
		trip[i] += trip[i-1];
	}
	int lt,ans;
	for(int i = 1;i <= n;i++){
		lt = leisure-trip[i-1],ans = 0;
		priority_queue<node> q;
		for(int j = 1;j <= i;j++) q.push({j,fish[j]});
		for(int j = 1;j <= lt;j++){
			t=q.top();
			q.pop();
			if(t.key < 0) break;
			ans += t.key;
			q.push({t.id,t.key-delta[t.id]});
		}
		answer = max(answer,ans);
	}
	cout<<answer<<endl;
	
}
