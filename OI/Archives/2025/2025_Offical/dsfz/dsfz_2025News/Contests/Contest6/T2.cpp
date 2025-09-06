/*
飞屋单调栈板子。
从后向前 维护最大值 ，每次栈顶的值就是这个数后面的最大值，如果小于这个数，就pop所有比它小的值否则记录值（map）然后pop掉。
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;
stack <int> s;
map <int,int> mp;
int n;
int a[101010];
int ans[101010];
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		mp[a[i]] = i;
	}
	for(int i = n;i >= 0;i--){
		while(!s.empty() and a[i] >= s.top()){
			s.pop();
		}
		if(s.empty()) ans[i] = 0;
		else ans[i] = mp[s.top()];
		if(!s.empty() and a[i] == s.top()) s.pop();
		s.push(a[i]);
	}
	for(int i = 1;i <= n;i++){
		cout<<ans[i]<<"\n";
	}
	
	return 0;
}
