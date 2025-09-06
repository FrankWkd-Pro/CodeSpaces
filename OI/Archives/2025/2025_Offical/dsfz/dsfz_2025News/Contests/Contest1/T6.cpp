#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;
int n;
string a, b, c;
int num[MAXN];  
bool used[MAXN];  
bool found = false;  

bool check() {
	int carry = 0;
	for (int i = n - 1; i >= 0; i--) {
		int x = num[a[i] - 'A'];
		int y = num[b[i] - 'A'];
		int z = num[c[i] - 'A'];
		if (x == -1 || y == -1 || z == -1) continue; 
		if ((x + y + carry) % n != z) return false;
		carry = (x + y + carry) / n;
	}
	if (carry != 0) return false;  
	return true;
}
void dfs(int pos) {
	if (found) return; 
	if (pos == n) {
		if (check()) {
			found = true;
			for (int i = 0; i < n; i++) {
				if (i > 0) cout << " ";
				cout << num[i];
			}
			cout << endl;
		}
		return;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (!used[i]) {
			num[pos] = i;
			used[i] = true;
			if (pos == n - 1 && (num[a[pos] - 'A'] + num[b[pos] - 'A']) >= n) {
				used[i] = false;
				continue;
			}
			if (pos < n - 1) {
				int j = n - 1;
				int carry = 0;
				bool valid = true;
				while (j > pos) {
					int x = num[a[j] - 'A'];
					int y = num[b[j] - 'A'];
					int z = num[c[j] - 'A'];
					if (x != -1 && y != -1 && z != -1) {
						if ((x + y + carry) % n != z) {
							valid = false;
							break;
						}
						carry = (x + y + carry) / n;
					}
					j--;
				}
				if (!valid) {
					used[i] = false;
					continue;
				}
			}
			dfs(pos + 1);
			used[i] = false;
		}
	}
}

int main() {
	cin >> n;
	cin >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		num[i] = -1;
	}
	dfs(0);
	if (!found) {
		cout << "NO" << endl;
	}
	return 0;
}

