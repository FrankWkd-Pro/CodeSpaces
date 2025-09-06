#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
bool f[1001010];
int sum,n;
int main(){
	cin>>n;
	for(int i = 2;i <= n;i++){
		if(!f[i]){
			sum++;
			for(int j = i*2;j <= n;j+=i){
				f[j] = true;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
