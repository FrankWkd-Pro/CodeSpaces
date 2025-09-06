/*
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-06-09
 * @Source    "https://oj.czos.cn/contest/problem?id=24562&pid=5"
 * @License   GNU General Public License 2.0
 * @FileName  T6.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/TopologicalSorting/T6.cpp
 * @Solution  能够确定顺序的判定方法就是看这个图是不是一个单链。依次加边看能不能组成单链就行了。发生矛盾就是出现了环。复杂度够用。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
struct node {
    int to, nxt;
} a[N];
set<char> s;
vector<int> v;
int pre[N], in[N], mark[N], t, n, m, k;
void add(int u, int v) {
    a[++k] = {v, pre[u]};
    pre[u] = k;
}
void check() {
    v.clear();
    t = 0;
    for (auto i : s) {
        mark[i - 'A' + 1] = in[i - 'A' + 1];
    }
    queue<int> q;
    for (auto i : s) {
        if (in[i - 'A' + 1] == 0) {
            q.push(i - 'A' + 1);
            t++;
            v.push_back(i - 'A' + 1);
        }
    }
    if (t > 1)  // 多个叶子节点
        t = 100000000;
    while (!q.empty()) {
        if (q.size() > 1) {  // 同一层存在多个入度为 0 的节点
            t = 100000000;
        }
        int h = q.front();
        q.pop();
        for (int i = pre[h]; i; i = a[i].nxt) {
            int to = a[i].to;
            mark[to]--;
            if (mark[to] == 0) {
                q.push(to);
                v.push_back(to);
                t++;
            }
        }
    }
}
void print() {
    for (int i = 0; i < v.size(); i++) {
        cout << (char)(v[i] + 'A' - 1);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        char o, p, q;
        cin >> o >> p >> q;

        if (o == q) {  // 出现自环
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
        s.insert(o);
        s.insert(q);
        x = o - 'A' + 1;
        y = q - 'A' + 1;
        if (p == '>')
            swap(x, y);
        in[y]++;
        add(x, y);
        check();
        if (t < s.size()) {
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
        if (t == n and s.size() == n) {
            cout << "Sorted sequence determined after " << i << " relations: ";
            print();
            cout << ".\n";
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined.";
    return 0;
}