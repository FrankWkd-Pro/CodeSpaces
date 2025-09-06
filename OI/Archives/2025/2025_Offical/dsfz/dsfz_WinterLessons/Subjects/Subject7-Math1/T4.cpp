#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n;
	while(n--){
		cin>>m;
		for(int i = m;i >= 1;i--){
			if(m % i == 0){
				cout<<m/i<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}
