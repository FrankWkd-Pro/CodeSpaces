#include <bits/stdc++.h>
using namespace std;
int quh, qum, qus;
int qutot;
int huih, huim, huis;
int huitot;
int T;
string qu, hui;
void _init() {
    quh = 0, qum = 0, qus = 0;
    qutot = 0;
    huih = 0, huim = 0, huis = 0;
    huitot = 0;
}

void print(int a, int b) {
    int ak = (a / 3600 + b / 3600) / 2;
    int akk = a % 3600 / 60;
    int akkk = a % 3600 % 60;
    if (ak < 10)
        cout << 0 << ak << ":";
    else
        cout << ak << ":";
    if (akk < 10)
        cout << 0 << akk << ":";
    else
        cout << akk << ":";
    if (akkk < 10)
        cout << 0 << akkk << endl;
    else
        cout << akkk << endl;
}

void convert() {
    if (qu.find("+1") != string::npos) {
        quh += 24;
    }
    if (qu.find("+2") != string::npos) {
        quh += 48;
    }
    if (hui.find("+1") != string::npos) {
        huih += 24;
    }
    if (hui.find("+2") != string::npos) {
        huih += 48;
    }
    quh += (qu[0] - '0') * 10 + qu[1] - '0';
    qum = (qu[3] - '0') * 10 + qu[4] - '0';
    qus = (qu[6] - '0') * 10 + qu[7] - '0';
    huih += (hui[0] - '0') * 10 + hui[1] - '0';
    huim = (hui[3] - '0') * 10 + hui[4] - '0';
    huis = (hui[6] - '0') * 10 + hui[7] - '0';
    qutot = quh * 3600 + qum * 60 + qus;
    huitot = huih * 3600 + huim * 60 + huis;
}

int main() {
    cin >> T;
    getchar();
    while (T--) {
        _init();
        string s;
        getline(cin, s);
        if (s.find("+1") == string::npos and s.find("+2") == string::npos) {
            qu = s.substr(0, 8);
            hui = s.substr(9);
        }
        if (s.find("+1") <= 14 or s.find("+2") <= 14) {
            qu = s.substr(0, 13);
            hui = s.substr(14);
        } else {
            qu = s.substr(0, 8);
            hui = s.substr(9);
        }
        convert();
        int ansa = huitot - qutot;
        _init();
        getline(cin, s);
        if (s.find("+1") == string::npos and s.find("+2") == string::npos) {
            qu = s.substr(0, 8);
            hui = s.substr(9);
        }
        if (s.find("+1") <= 14 or s.find("+2") <= 14) {
            qu = s.substr(0, 13);
            hui = s.substr(14);
        } else {
            qu = s.substr(0, 8);
            hui = s.substr(9);
        }
        convert();
        int ansb = huitot - qutot;
        print(ansa, ansb);
    }

    return 0;
}