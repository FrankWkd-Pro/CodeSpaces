#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 4e7 + 5;
bool f[N + 5];
int sub[N + 5];
int n, l, r;
int digit[11];

vector<int> pri;

bool check(int x) {
    for (int i = 0; i < 10; i++) digit[i] = 0;
    while (x > 0) {
        int ls = x % 10;
        digit[ls]++;
        if (digit[ls] > 1)
            return false;
        x /= 10;
    }
    return true;
}
void init() {
    for (int i = 2; i < N; i++) f[i] = 1;
    digit[2] = 1;
    for (int i = 2; i <= N; i++) {
        if (f[i])
            pri.push_back(i);
        for (int j = 0; j < pri.size() and i * pri[j] < N; j++) {
            f[i * pri[j]] = 0;
            if (i % pri[j] == 0)
                break;
        }
    }
    for (auto i : pri) {
        if (check(i))
            sub[i]++;
    }
    for (int i = 1; i < N; i++) {
        sub[i] += sub[i - 1];
    }
}
int main() {
    freopen("super.in", "r", stdin);
    freopen("super.out", "w", stdout);
    init();
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", sub[r] - sub[l - 1]);
    }
    return 0;
}