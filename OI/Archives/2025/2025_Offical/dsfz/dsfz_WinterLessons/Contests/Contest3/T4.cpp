#include <iostream>
using namespace std;
const int MOD = 1000000007;
const int N = 55;
int w[N][N];  // 坐标(i, j)宝贝价值
// dpp[i][j][k][c] : 走到(i, j),拾取k个宝贝，且所有宝贝中最大的价值为c的方案数
int dp[N][N][13][14];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    // 收集物品价值，扩展到1～13，0代表还没有拾取物品
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
            w[i][j]++;
        }
    }
    // 初始化
    dp[1][1][1][w[1][1]] = 1;
    dp[1][1][0][0] = 1;
    // 开始动态规划
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // (1, 1)的所有情况都初始化过了，直接跳过
            if (i == 1 && j == 1)
                continue;
            for (int u = 0; u <= k; u++) {
                for (int v = 0; v <= 13; v++) {
                    int &val = dp[i][j][u][v];               // dp数组常用，这样方便后面用到时好写
                    val = (val + dp[i - 1][j][u][v]) % MOD;  // 来自上方且不取(i, j)的宝贝
                    val = (val + dp[i][j - 1][u][v]) % MOD;  // 来左边且不取(i, j)的宝贝
                    // 下面是取(i, j)宝贝情况
                    if (u > 0 && v == w[i][j])  // u > 0 才能取，根据dp定义以及题目含义，取的(i, j)宝贝价值w必须为v
                    {
                        for (int c = 0; c < v; c++)  // 上一个状态的最大价值宝贝的价值有很多可能，但一定价值小于v
                        {
                            val = (val + dp[i - 1][j][u - 1][c]) % MOD;  // 转移自上方且取(i, j)的宝贝
                            val = (val + dp[i][j - 1][u - 1][c]) % MOD;  // 转移自左边且取(i, j)的宝贝
                        }
                    }
                }
            }
        }
    }
    // 计算答案，累加各种c的可能
    int res = 0;
    for (int c = 0; c <= 13; c++) {
        res = (res + dp[n][m][k][c]) % MOD;
    }
    cout << res;
    return 0;
}
