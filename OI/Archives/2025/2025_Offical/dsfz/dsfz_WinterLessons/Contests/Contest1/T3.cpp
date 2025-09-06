#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>

#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;
const int N = 60;
char g[N][N], bg[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};
void turn(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5)
            continue;
        g[a][b] ^= 1;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 5; i++) scanf("%s", bg[i]);
        int res = 10;
        for (int op = 0; op < 32; op++) {
            int cnt = 0;
            memcpy(g, bg, sizeof(g));
            for (int i = 0; i < 5; i++)
                if (op >> i & 1) {
                    turn(0, i);
                    cnt++;
                }

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                    if (g[i][j] == '0') {
                        turn(i + 1, j);
                        cnt++;
                    }

            bool success = true;
            for (int i = 0; i < 5; i++)
                if (g[4][i] == '0')
                    success = false;
            if (success && res > cnt)
                res = cnt;
        }
        if (res > 6)
            res = -1;
        printf("%d\n", res);
    }
    return 0;
}
