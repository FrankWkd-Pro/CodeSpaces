#include<bits/stdc++.h>
using namespace std;
string rround;
int n;
string org;
bool f = 0, noww = 0;
int main() {

	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') noww = 1;
		else if (s[i] == '(') f = 1;
		else if (s[i] == ')') f = 0;
		else {
			if (!f and noww) org += s[i];
			if (f and noww) rround = rround + to_string(s[i]-'0');
		}
	}
	if((n-org.size())%rround.size() == 0) cout<<rround[rround.size()-1];
	else cout<<rround[(n-org.size())%rround.size()-1];
	//1.111(23) 6
	return 0;
}
