#include <bits/stdc++.h>
using namespace std;
bool f[10100010];
int ans;
int pr[10101010];
int n, x, q;
int cnt;
void eulerPrimes() {
    for (int i = 2; i <= 10000050; i++) {
        if (!f[i]) {
            pr[++cnt] = i;
        }
        for (int j = 1; i * pr[j] <= 10000050 and j <= cnt; j++) {
            f[i * pr[j]] = true;
            // 			cout<<i<<" "<<pr[j]<<endl;
            if (i % pr[j] == 0)
                break;
        }
    }
    // 	for(int i = 1;i <= 20;i++) cout<<pr[i]<<" ";
}

int main() {
    scanf("%d", &q);
    eulerPrimes();
    while (q--) {
        scanf("%d", &x);
        int pre = lower_bound(pr + 1, pr + 1 + cnt, x) - pr;
        if (abs(pr[pre] - x) <= abs(pr[pre - 1] - x))
            printf("%d\n", pr[pre]);
        else
            printf("%d\n", pr[pre - 1]);
    }
}

© 东方博宜OJ 2025