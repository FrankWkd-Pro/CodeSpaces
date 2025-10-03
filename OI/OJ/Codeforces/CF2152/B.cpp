/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-03
 * @Network   "https://codeforces.com/contest/2152/problem/B"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  B.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Codeforces/CF2152/B.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (auto aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (auto aa = bb; aa >= cc; aa--)
#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>

// 定义坐标结构体
struct pnt {
    int x;
    int y;
    pnt(int _x, int _y) : x(_x), y(_y) {}
    // 定义小于运算符重载，用于比较两个pnt结构体的大小
    bool operator<(const pnt& other) const {
        if (x < other.x)
            return true;
        if (x > other.x)
            return false;
        return y < other.y;
    }
    // 定义相等运算符重载，用于unordered_set判断元素相等
    bool operator==(const pnt& other) const {
        return x == other.x && y == other.y;
    }
};

// 为pnt类型特化std::hash，以便在unordered_set中能正确计算哈希值
namespace std {
    template <>
    struct hash<pnt> {
        std::size_t operator()(const pnt& p) const {
            // 简单的哈希计算方式，可根据实际情况优化调整
            return std::hash<int>{}(p.x) ^ (std::hash<int>{}(p.y) << 1);
        }
    };
}

// 计算克鲁格的存活时间的函数
int bfs(int n, int r_K, int c_K, int r_D, int c_D) {
    std::queue<std::pair<pnt, pnt>> q;
    std::unordered_set<std::pair<pnt, pnt>> visited;
    q.push(std::make_pair(pnt(r_K, c_K), pnt(r_D, c_D)));
    visited.insert(std::make_pair(pnt(r_K, c_K), pnt(r_D, c_D)));
    int turn = 0;
    bool krug_turn = true;
    // 四个方向的偏移量，对应上下左右
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    // 八个方向的偏移量，对应多兰的上下左右和斜向
    int dx_doran[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy_doran[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    // 计算初始曼哈顿距离
    int initial_distance = manhattanDistance(pnt(r_K, c_K), pnt(r_D, c_D));
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            pnt krug = q.front().first;
            pnt doran = q.front().second;
            q.pop();
            if (krug.x == doran.x && krug.y == doran.y) {
                return turn;
            }
            // 距离剪枝判断，如果多兰在剩余回合内无论如何都追不上克鲁格，判定为无限存活
            if (turn * 8 < initial_distance) {  // 假设多兰每回合最多斜向移动8格（8个方向），这里可以根据实际情况调整
                return -1;
            }
            if (krug_turn) {
                // 克鲁格行动
                for (int j = 0; j < 4; ++j) {
                    int new_x = krug.x + dx[j];
                    int new_y = krug.y + dy[j];
                    if (new_x >= 0 && new_x <= n && new_y >= 0 && new_y <= n) {
                        pnt new_krug(new_x, new_y);
                        if (visited.find(std::make_pair(new_krug, doran)) == visited.end()) {
                            visited.insert(std::make_pair(new_krug, doran));
                            q.push(std::make_pair(new_krug, doran));
                        }
                    }
                }
            } else {
                // 多兰行动
                for (int j = 0; j < 8; ++j) {
                    int new_x = doran.x + dx_doran[j];
                    int new_y = doran.y + dy_doran[j];
                    if (new_x >= 0 && new_x <= n && new_y >= 0 && new_y <= n) {
                        pnt new_doran(new_x, new_y);
                        if (visited.find(std::make_pair(krug, new_doran)) == visited.end()) {
                            visited.insert(std::make_pair(krug, new_dordan));
                            q.push(std::make_pair(krug, new_doran));
                        }
                    }
                }
            }
        }
        turn++;
        krug_turn = !krug_turn;
    }
    return -1;
}

// 计算曼哈顿距离
int manhattanDistance(const pnt& a, const pnt& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, r_K, c_K, r_D, c_D;
        std::cin >> n >> r_K, std::cin >> c_K, std::cin >> r_D, std::cin >> c_D;
        std::cout << bfs(n, r_K, c_K, r_D, c_D) << std::endl;
    }
    return 0;
}
