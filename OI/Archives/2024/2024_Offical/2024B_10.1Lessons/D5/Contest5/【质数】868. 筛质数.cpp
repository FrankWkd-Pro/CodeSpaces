#include <bits/stdc++.h>
using namespace std;
int pri[2000010];
int tot;
bool ntp[10000010];
void gp(int n){
	for(int i = 2;i <= n;i++){
		if(!ntp[i]) pri[++tot] = i;
		for(int j = 1;j <= tot and i*pri[j]<=n;j++){
			ntp[i*pri[j]] = 1;
			if(i%pri[j] == 0) break;
		}
	}
}
int main(){
	int n;
	cin>>n;
	gp(n);
	cout<<tot<<endl;
}
