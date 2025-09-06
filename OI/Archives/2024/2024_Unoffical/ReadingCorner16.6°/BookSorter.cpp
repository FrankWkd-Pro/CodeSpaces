#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("TGH1.txt","r",stdin);
	freopen("TGH2.txt","w",stdout);
	for(int i = 1;i <= 37422;i++){
		string s;
		cin>>s;
		if(s[0] == '#'){
			cout<<"\n<\n";
			cout<<s<<endl;
			cout<<time(0)<<endl;
		}else{
			cout<<s<<endl;
		}
	}
	cout<<"#EOF"<<endl;
}
