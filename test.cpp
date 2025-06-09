#include <bits/stdc++.h>
#define N 1001
using namespace std;

int n, p, k, u, v, ll;
int dis[N], len[N][N], line[N * 10][4];
bool used[N];
queue<int> q;

bool check(int m) {
    memset(len, -1, sizeof(len));
    memset(used, false, sizeof(used));
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= p; ++i)
        if (line[i][3] > m) {
            len[line[i][1]][line[i][2]] = 1;
            len[line[i][2]][line[i][1]] = 1;
        } else {
            len[line[i][1]][line[i][2]] = 0;
            len[line[i][2]][line[i][1]] = 0;
        }

    used[1] = true;
    dis[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (len[x][i] != -1 && dis[x] + len[x][i] < dis[i]) {
                dis[i] = dis[x] + len[x][i];
                if (!used[i]) {
                    used[i] = true;
                    q.push(i);
                }
            }
        }
        used[x] = false;
    }
    if (dis[n] > k)
        return false;
    else
        return true;
}

int main() {
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1; i <= p; ++i) {
        scanf("%d%d%d", &u, &v, &ll);
        line[i][1] = u;
        line[i][2] = v;
        line[i][3] = ll;
    }
    int l = 0, r = 1000000000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (r != 1000000000)
        cout << l;
    else
        cout << -1;
}