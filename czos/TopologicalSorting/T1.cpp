/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-08
 * @FileName  T1.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/czos/TopologicalSorting/T1.cpp
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 2010;
struct node {
    int to, nxt;
} a[M];
int pre[N], in[N];
queue<int> q;
int n, m;
int k;
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int cnt = 0;
        memset(in, 0, sizeof in);
        memset(pre, 0, sizeof pre);
        k = 0;
        while (!q.empty()) q.pop();
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            add(x, y);
            in[y]++;
        }
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            for (int i = pre[h]; i; i = a[i].nxt) {
                int to = a[i].to;
                in[to]--;
                if (in[to] == 0) {
                    q.push(to);
                    cnt++;
                }
            }
        }
        bool fl = 1;
        for (int i = 1; i <= n; i++)
            if (in[i] != 0)
                fl = 0;
        if (fl)
            cout << "N\n";
        else
            cout << "Y\n";
    }
}