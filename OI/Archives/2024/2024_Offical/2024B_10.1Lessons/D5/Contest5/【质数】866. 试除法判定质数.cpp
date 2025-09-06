#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		int f = 0;
		if(x == 1){
			cout<<"No\n";
			continue;
		}
		for(int i = 2;i < x;i++){
			if(x%i == 0) f = 1;
		}
		if(f) cout<<"No\n";
		else cout<<"Yes\n";
	}
} 
