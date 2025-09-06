#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
map<string, int> tong;
int n;

string tostring(int i) {
    int x = i;
    string s = "";
    while (i > 0) {
        s += i % 10 + '0';
        i /= 10;
    }
    reverse(s.begin(), s.end());
    // cout<<"Convert to string: "<<x<<" -> "<<s<<endl;
    return s;
}

int main() {
    cin >> n;
    string s;
    for (int i = 1; i <= n + 1; i++) {
        getline(cin, s);
        s += " ";
        int posi = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                tong[s.substr(posi, j - posi)]++;
                // cout<<"substr: "<<s.substr(posi,j-posi)<<"<"<<endl;
                // cout<<posi<<" "<<j<<endl;
                posi = j + 1;
            }
        }
    }
    bool f = false;
    int shao = -1, duo = -1;
    for (int i = 1; i <= 100020; i++) {
        if (!f and tong[tostring(i)] != 0)
            f = true;
        else if (f and tong[tostring(i)] == 0 and shao == -1) {
            shao = i;
        } else if (f and tong[tostring(i)] == 2 and duo == -1) {
            duo = i;
        }
        if (shao != -1 and duo != -1)
            break;
    }
    cout << shao << " " << duo;
}
