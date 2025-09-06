#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct node {
    double l, r;
    bool operator<(const node& W) const {
        return l < W.l;
    }
};


int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int cnt = 0;
        int n;
        double l, w;
        std::cin >> n >> l >> w;
        std::vector<node> a;
        double w2 = w / 2.0;
        for (int i = 0; i < n; ++i) {
            double x, y;
            std::cin >> x >> y;
            if (y <= w / 2) {
                continue;
            }
            node temp;
            temp.l = x - std::sqrt(y * y - w * w / 4);
            temp.r = x + std::sqrt(y * y - w * w / 4);
            a.push_back(temp);
        }
        std::sort(a.begin(), a.end());
        double s = 0, e = l;
        int i = 0, ans = 0;
        bool t = false;
        while (s < e) {
            double vis = -2e9;
            size_t j;
            for (j = i; j < a.size(); ++j) {
                if (a[j].l <= s) {
                    vis = std::max(vis, a[j].r);
                } else {
                    break;
                }
            }
            if (s < e && vis < s) {
                std::cout << -1 << "\n";
                t = true;
                break;
            }
            ans++;
            s = vis;
            i = j;
        }
        if (!t) std::cout << ans << "\n";
    }
    return 0;
}
