#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int n;
void f(int x){
	for(int i = 2;i <= x/i;i++){
		if(x % i == 0){
			int res = 0;
			while(x % i == 0){
				res++;
				x /= i;
			}
			printf("%d %d\n",i,res);
		}
	}
	if(x != 1){
		printf("%d %d\n",x,1);
	}
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		f(x);
		cout<<endl;
	}
	
	return 0;
}

