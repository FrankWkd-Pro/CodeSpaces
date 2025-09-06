#include <bits/stdc++.h>
int primes[101000], n, phi[1001000];  // 分别存储:素数,数据总数,i的欧拉函数
bool f[1010000];                      // 标记当前数是不是素数
void get_phi() {                      // 设p是i的最小质因子，p为质数
    int cnt = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!f[i]) {
            primes[++cnt] = i;
            phi[i] = i - 1;  // 对应情况一
        }
        for (int j = 1; j <= cnt and primes[j] * i <= n; j++) {
            f[i * primes[j]] = true;

            /*在此for循环中，i的定义发生了转移，由var_i*primes[j]来表示i，
            那么var_i与primes[j]就理所当然地成为了i的因子。
            由于primes[j]不可能比var_i更大(因为大于i的质数还没筛到)s
            所以primes[j]符合公式中p的定义。
            而var_i呢？它很被动，必须保证与p的乘积为i，所以干脆把var_i在数学公式中定义为i/p
            */
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            } else {
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }
}

int main() {
    std::cin >> n;
    long long ans = 0;
    get_phi();
    for (int i = 1; i <= n; i++) {
        ans += phi[i];
    }
    std::cout << ans;
}