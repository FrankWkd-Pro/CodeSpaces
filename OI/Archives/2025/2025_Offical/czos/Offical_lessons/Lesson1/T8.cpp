#include <bits/stdc++.h>
using namespace std;

int f[2010100];
int k, all[2010101];
int n;
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = f[find(y)];
}
struct node {
    int x, y, z;
} a[1010100];
bool cmp(node aa, node bb) {
    return aa.z > bb.z;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2000100; i++) f[i] = i;
        k = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            all[++k] = a[i].x;
            all[++k] = a[i].y;
        }
        sort(a + 1, a + 1 + n, cmp);
        sort(all + 1, all + 1 + k);
        k = unique(all + 1, all + 1 + k) - all - 1;
        for (int i = 1; i <= n; i++) {
            a[i].x = lower_bound(all + 1, all + 1 + k, a[i].x) - all;
            a[i].y = lower_bound(all + 1, all + 1 + k, a[i].y) - all;
        }
        for (int i = 1; i <= n; i++) {
            // cout << a[i].x << " " << a[i].y << " " << a[i].z << endl;
            if (a[i].z == 1)
                merge(a[i].x, a[i].y);
            else {
                if (find(a[i].x) == find(a[i].y)) {
                    puts("NO");
                    goto cont;
                }
            }
        }
        cout << "YES\n";
    cont:;
    }
}