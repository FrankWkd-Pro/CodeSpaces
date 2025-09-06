// HACK:东方博宜寒假C组集训T7 代码未完成
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int st_i, st_j, ed_i, ed_j;
        bool is_st = 0;
        int length;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            is_beg = 0;
            for (int j = 0; j < s.size(); j++) {
                if (!is_st and s[j] == '#') {
                    is_st = 1;
                    st_i = i;
                    st_j = j;
                    for (int k = 0; k < s.size(); k++) {
                        if (s[i] == '#')
                            is_beg = 1, length++;
                        if (is_beg == 1 and s[i] == '.')
                            goto no;
                    }
                }
                if (j != 0)
            }
        }
        cin >> s;
    no:;
        cout << "Unlike\n";
        continue;
    yes:;
        cout << "Like\n";
    }

    return 0;
}