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
		bool f = false;
		if(m == 1){
			cout<<"No\n";
			f = false;
		}
		else if(m == 2){
			cout<<"Yes\n";
			f = false;
		}
		else {
			for(int i = 2;i * i <= m;i++){
				if(m%i == 0){
					f = true;
					cout<<"No\n";
				}
			}
			if(!f){
				cout<<"Yes\n";
			}
		}
	}

	return 0;
}

