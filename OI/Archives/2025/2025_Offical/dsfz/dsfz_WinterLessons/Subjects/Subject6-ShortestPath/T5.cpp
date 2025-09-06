#include <bits/stdc++.h>
using namespace std;
inline int read() {
    char c = 0;
    int x = 0;
    bool f = 0;
    while (!isdigit(c)) f = c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
    return f ? -x : x;
}
const int N = 100100;
const int M = 500100;
struct node {
    int next, to, len;
} e[M * 6 + N * 2];
int h[N * 3], tot;
void add(int a, int b, int w) {
    e[++tot] = (node){h[a], b, w};
    h[a] = tot;
}
int d[N * 3];
bool vis[N * 3];
void spfa_algorithm(int s) {
    memset(d, 128, sizeof(d));
    memset(vis, 1, sizeof(vis));
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (int i = h[u]; i; i = e[i].next) {
            int to = e[i].to;
            if (d[to] < d[u] + e[i].len) {
                d[to] = d[u] + e[i].len;
                if (vis[to]) {
                    vis[to] = false;
                    q.push(to);
                }
            }
        }
    }
}  // 因为有负边所以必须要spfa
int n, m, cost[N];
void read_the_date() {
    n = read();
    m = read();
    for (int i = 1; i <= n; i++) {
        cost[i] = read();
        add(i, i + n, -cost[i]);
        add(i + n, i + 2 * n, cost[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), z = read();
        add(u, v, 0);
        add(u + n, v + n, 0);
        add(u + 2 * n, v + 2 * n, 0);
        if (z == 2)
            add(v, u, 0), add(v + n, u + n, 0), add(v + 2 * n, u + 2 * n, 0);
    }
}  // 注意如何建边
int main() {
    read_the_date();
    spfa_algorithm(1);
    cout << max(d[n], d[3 * n]);
    return 0;
}
