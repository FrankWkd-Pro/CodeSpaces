//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

char libaryx[50] = {'0', '1', '2', '3',
                    '4', '5', '6', '7', '8',
                    '9', 'A', 'B', 'C', 'D',
                    'E', 'F', 'G', 'H', 'I',
                    'J', 'K', 'L', 'M', 'N',
                    'O', 'P', 'Q', 'R', 'S',
                    'T', 'U', 'V', 'W', 'X',
                    'Y', 'Z'
                   };

string getto(int num, int jinzhi) {
	string ans = "";
	while (num > 0) {
//		cout << libaryx[num % jinzhi] << endl;
		ans = ans + libaryx[num % jinzhi];
		num /= jinzhi;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool is_huiwen(string str) {
	string chk = str;
	reverse(chk.begin(), chk.end());
	return chk == str;
}

int main() {
	int n, jinzhinum;
	cin >> jinzhinum;
	for (int i = 1; i <= 300; i++) {
		string test_str;
		string save;

		test_str = getto(i * i, jinzhinum);
		save = getto(i, jinzhinum);
		if (is_huiwen(test_str) == true) {
			cout << save << " " << test_str << "\n";
		}
	}
	return 0;
}

