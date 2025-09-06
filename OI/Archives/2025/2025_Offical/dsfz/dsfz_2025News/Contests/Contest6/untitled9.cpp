#include <bits/stdc++.h>
using namespace std;
int n,a[1010010][30],cnt[1010101],op;
char s[1001010];
int idx;//节点编号
void insert(char s[]){
	int x,p = 0;
	for(int i= 0;s[i];i++){
		x = s[i]-'a';
		if(a[p][x] == 0) a[p][x] = ++idx;
		p = a[p][x];
		
	}
	cnt[p]++;
}
int query(char s[]){
	int x,p = 0,anss = 0;
	for(int i = 0;s[i];i++){
		x = s[i]-'a';
		if(cnt[p] != 0) anss += cnt[p];
		if(a[p][x] == 0) return anss;
		p = a[p][x];
	}
	return anss;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>op>>s;
		if(op == 1){
			insert(s);
		}else cout<<query(s)<<"\n";
	}	
}
