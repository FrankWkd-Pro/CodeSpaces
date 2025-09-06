//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
string s;
string v_str[100000];
string v_num[100000];
string v_uk[100000];
int lis;

void inport_word() {
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			if (s[i] == ';' or s[i] == ',') {
				lis += 2;
			} else {
				v_uk[++lis] += s[i];
			}
		} else if (s[i] == ';' or s[i] == ',') {
			lis++;
		} else if (s[i] != ';' and s[i] != ',') {
			v_uk[lis] += s[i];
		}
	}
//	for (int i = 1; i <= lis; i++) {
//		cout << v_uk[i] << endl;
//	}
}


bool is_num_word(string op) {
	if (op.size() == 0 or (op != "0" and op[0] == '0'))
		return false;
	for (int i = 0; i < op.size(); i++) {
		if (op[i] < '0' or op[i] > '9')
			return false;
	}
	return true;
}


int lis_num, lis_word;

int main() {
	cin >> s;
	inport_word();
	for (int i = 1; i <= lis; i++) {
		if (is_num_word(v_uk[i])) {
			v_num[++lis_num] = v_uk[i];
		} else {
			v_str[++lis_word] = v_uk[i];
		}
	}
	if (lis_num == 0) {
		cout << "-\n";
	} else {
		cout << "\"";
		cout << v_num[1];
		for (int i = 2; i <= lis_num; i++) {
			cout << "," << v_num[i];
		}
		cout << "\"\n";
	}
	if (lis_word == 0) {
		cout << "-";
		return 0;
	} else {
		cout << "\"";
		cout << v_str[1];
		for (int i = 2; i <= lis_word; i++) {
			cout << "," << v_str[i];
		}
		cout << "\"";
	}
	return 0;
}
