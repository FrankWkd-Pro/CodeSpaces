#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    return b ? gcd(b,a%b) : a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long m,l;
	while(n--){
		cin>>m>>l;
		cout<<gcd(m,l)<<"\n";
	}

	return 0;
}

