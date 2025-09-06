#include<bits/stdc++.h>
using namespace std;
const int N = 30010, MOD = 1e9+7;
const int P = 131;
char s[N];
int ne[N],ans,k,n;
void kmp(char s[]){
	int len = strlen(s+1);
	for(int i = 2,j = 0;i <= len;i++){
		while(j and s[i] != s[j+1]) j = ne[j];
		if(s[i] == s[j+1]) j++;
		int p = ne[i] = j;
		while(p and 2*p >= i) p = ne[p];
		if(p >= k) ans++;
	}
}
int main() {
	cin>>s+1>>k;
	n = strlen(s+1);
	for(int i = 0;i <= n;i++){
		kmp(s+i);
	}
	cout<<ans<<endl;
	return 0;
}
