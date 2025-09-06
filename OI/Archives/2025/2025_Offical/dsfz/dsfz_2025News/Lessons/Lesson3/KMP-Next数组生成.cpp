#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;

int nxt[N];
int n,m,j = 0,i = 2;//Notice: i从2开始长度为0和1的串共同前后缀为零
char s[N];
int main() {
	cin>>n>>s+1;
	while(i <= n){
		while(s[j+1] != s[i] and j != 0) j = nxt[j];
		if(s[i] == s[j+1]) j++;
		nxt[i] = j; 
		i++;
	}
	for(int i = 1;i <= strlen(s+1);i++){
		cout<<nxt[i]<<endl;
	}
	return 0;
}
