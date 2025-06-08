#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r;
    int lazy = 0, sum = 0, min = 0;  // 初始化懒标记和值
} tr[200010 * 4];                    // 4倍空间

int n, m;
char op[2];
int a[200010];  // 扩大数组范围到 2e5+10

void pushup(int k) {
    tr[k].min = min(tr[k << 1].min, tr[k << 1 | 1].min);  // 使用位运算统一风格
    tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum;
}

void pushdown(int k) {
    if (tr[k].lazy != 0) {
        int lazy = tr[k].lazy;
        tr[k << 1].sum += lazy * (tr[k << 1].r - tr[k << 1].l + 1);
        tr[k << 1].min += lazy;
        tr[k << 1].lazy += lazy;

        tr[k << 1 | 1].sum += lazy * (tr[k << 1 | 1].r - tr[k << 1 | 1].l + 1);
        tr[k << 1 | 1].min += lazy;
        tr[k << 1 | 1].lazy += lazy;

        tr[k].lazy = 0;
    }
}

void build(int k, int l, int r) {
    tr[k].l = l, tr[k].r = r;
    tr[k].lazy = 0;  // 显式初始化
    if (l == r) {
        tr[k].min = tr[k].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pushup(k);
}

void update(int k, int x, int y, int v) {
    int l = tr[k].l, r = tr[k].r;
    if (x <= l && r <= y) {
        tr[k].sum += v * (r - l + 1);
        tr[k].min += v;
        tr[k].lazy += v;
        return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (x <= mid)
        update(k << 1, x, y, v);
    if (y > mid)
        update(k << 1 | 1, x, y, v);
    pushup(k);
}

int queryMin(int k, int x, int y) {
    int l = tr[k].l, r = tr[k].r;
    if (x <= l && r <= y)
        return tr[k].min;
    pushdown(k);
    int mid = (l + r) >> 1;
    int res = INT_MAX;
    if (x <= mid)
        res = min(res, queryMin(k << 1, x, y));
    if (y > mid)
        res = min(res, queryMin(k << 1 | 1, x, y));
    return res;
}

int querySum(int k, int x, int y) {
    int l = tr[k].l, r = tr[k].r;
    if (x <= l && r <= y)
        return tr[k].sum;
    pushdown(k);
    int mid = (l + r) >> 1;
    int res = 0;
    if (x <= mid)
        res += querySum(k << 1, x, y);
    if (y > mid)
        res += querySum(k << 1 | 1, x, y);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--) {
        scanf("%s", op);
        int l, r;
        cin >> l >> r;
        if (op[0] == 'P') {
            int x;
            cin >> x;
            update(1, l, r, x);
        } else if (op[0] == 'M') {
            cout << queryMin(1, l, r) << endl;
        } else {
            cout << querySum(1, l, r) << endl;
        }
    }
    return 0;
}