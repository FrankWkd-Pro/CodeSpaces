#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("破云2：TGH.txt","r",stdin);
	freopen("TGH.txt","w",stdout);
	for(int i = 1;i <= 37422;i++){
		string s;
		cin>>s;
		if(s[0] == '#'){
			cout<<"\n<\n";
			cout<<s<<endl;
			cout<<time(0)<<endl;
			cout<<"淮上"<<endl;
		}else{
			cout<<s<<endl;
		}
	}
	cout<<"#EOF"<<endl;
}
