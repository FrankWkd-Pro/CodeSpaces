#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

const int MaxN = 1005;
struct segment {
    double l, r;
} a[MaxN];
int n;
double d;
int num[MaxN];

inline double calc(double y) {
    return sqrt(d * d - y * y);
}

inline void init() {
    scanf("%d%lf", &n, &d);
    for (register int i = 1; i <= n; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        if (y > d) {  // 如果y太大了，说明在哪放都无济于事
            printf("-1");
            exit(0);
        }
        double len = calc(y);
        a[i].l = x - len;
        a[i].r = x + len;
        num[i] = 1;  // 这一行和前两行的意思：[l,r]要求有一个点
    }
}

bool cmp(segment x, segment y) {
    return x.r < y.r;
}

inline void work() {
    int ans = 0;
    sort(a + 1, a + 1 + n, cmp);    // 先排序，按右端点
    for (int i = 1; i <= n; i++) {  // 看每一条区间
        double nowr = a[i].r;       // 这一条区间的右端点。因为放右端点的话就有更大几率影响其他的区间
        if (num[i] <= 0)
            continue;                                // 如果没需求了，就直接跳过
        num[i]--;                                    // 需求减一
        for (register int j = i + 1; j <= n; j++) {  // 看后面相交的区间
            if (a[j].l <= nowr) {
                num[j]--;  // 同样需求减一
            }
        }
        ans++;  // 代价加一
    }
    printf("%d", ans);
}

int main() {
    init();  // 初始化出区间
    work();  // 贪心
}