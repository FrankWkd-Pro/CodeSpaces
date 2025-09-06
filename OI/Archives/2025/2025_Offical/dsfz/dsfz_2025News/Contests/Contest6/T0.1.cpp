#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;
int n;
int sav;
int ls,x;
int main() {
	for(int i = 1;i <= 12;i++){
		cin>>x;
		ls += 300;
		if(ls < x) {
			cout<<-i;
			return 0;
		}
		ls -= x;
		sav += ls/100*100;
		ls -= ls/100*100;
		cout<<ls<<" "<<sav<<endl;
	}
	cout<<ls+sav*1.2<<endl;
	return 0;
}
