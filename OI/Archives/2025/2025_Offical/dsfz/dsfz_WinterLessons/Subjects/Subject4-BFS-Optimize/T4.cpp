#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1010, M = N * N;

int n, m;
char g[N][N];
PII q[M];
int dist[N][N];

int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1}; 

void bfs() {
    memset(dist, -1, sizeof dist);
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '1') {
                dist[i][j] = 0;  
                q[++tt] = {i, j}; 
            }

    while (hh <= tt) {
        PII t = q[hh++];
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (~dist[x][y]) continue;
            dist[x][y] = dist[t.x][t.y] + 1;
            q[++tt] = {x, y};
        }
    }
}

int main() {
    cin >> n >> m;

   for (int i = 1; i <= n; i++) cin >> g[i] + 1;

    bfs();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", dist[i][j]);
        puts("");
    }
    return 0;
}

