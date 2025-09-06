#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>

#define inf 100000000000000
#define int long long
using namespace std;
const int N = 4e5;

// 节点数和边数
int n, m;
// 存储最终答案，初始化为无穷大
int ans = inf;

// 边的结构体，存储边的两个端点 u 和 v，边的权重 w，以及该边是否在最小生成树中（flag）
struct link
{
    int u, v, w;
    bool flag;
    // 重载小于运算符，用于边的排序，按照边的权重升序排序
    bool operator<(const link& ret) const
    {
        return w < ret.w;
    }
} edge[N + 10];

// 存储图的邻接表节点信息，存储邻接节点 to 和边的长度 len
struct node
{
    int to, len;
};
// 邻接表
vector<node>e[N + 10];
// 存储每个节点的父节点，用于倍增法
int fa[N + 10][20];
// 存储每个节点到父节点路径上的最大边权，用于倍增法
int maxs[N + 10][20];
// 存储每个节点到父节点路径上的次大边权，用于倍增法
int mins[N + 10][20];
// 存储每个节点的深度
int deep[N + 10];
// 存储最小生成树的边权和
int sum;
// 并查集数组，用于判断节点的父节点
int f[N + 10];

// 并查集的查找操作，用于找到节点 x 的根节点
int getfa(int x)
{
    if (f[x] == x)
        return x;
    // 路径压缩，将节点的父节点更新为根节点
    return f[x] = getfa(f[x]);
}

// 计算最小生成树
void mst()
{
    int cnt = 0;
    // 初始化并查集，每个节点的父节点为自身
    for (int i = 1; i <= n; i++)
        f[i] = i;
    // 对边按照权重进行排序
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        // 找到节点 u 和 v 的根节点
        int fu = getfa(u), fv = getfa(v);
        if (fu!= fv)
        {
            // 合并两个集合，更新父节点
            f[fu] = fv;
            cnt++;
            // 更新最小生成树的边权和
            sum += w;
            // 标记该边在最小生成树中
            edge[i].flag = 1;
            // 将边加入邻接表中
            e[u].push_back({ v, w });
            e[v].push_back({ u, w });
        }
        // 当最小生成树的边数达到 n-1 时，结束
        if (cnt >= n - 1)
            break;
    }
}

// 深度优先搜索，用于预处理倍增数组
void dfs(int u, int father)
{
    // 计算当前节点的深度
    deep[u] = deep[father] + 1;
    for (int i = 1; i <= 19; i++)
    {
        // 倍增更新父节点
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        // 倍增更新最大边权
        maxs[u][i] = max(maxs[u][i - 1], maxs[fa[u][i - 1]][i - 1]);
        if (maxs[u][i - 1]!= maxs[fa[u][i - 1]][i - 1])
        {
            // 如果两条路径上的最大边权不同，更新次大边权
            mins[u][i] = min(maxs[u][i - 1], maxs[fa[u][i - 1]][i - 1]);
            mins[u][i] = max(mins[u][i], mins[u][i - 1]);
            mins[u][i] = max(mins[u][i], mins[fa[u][i - 1]][i - 1]);
        }
        else
            // 如果两条路径上的最大边权相同，更新次大边权
            mins[u][i] = max(mins[u][i - 1], mins[fa[u][i - 1]][i - 1]);
    }
    // 遍历邻接节点
    for (auto v : e[u])
    {
        if (father == v.to)
            continue;
        // 更新邻接节点的父节点和初始边权信息
        fa[v.to][0] = u;
        maxs[v.to][0] = v.len;
        mins[v.to][0] = -inf;
        // 继续递归搜索
        dfs(v.to, u);
    }
}

// 计算最近公共祖先
int lca(int x, int y)
{
    // 保证 x 的深度大于等于 y 的深度
    if (deep[x] < deep[y])
        swap(x, y);
    for (int i = 19; ~i; i--)
    {
        if (deep[fa[x][i]] >= deep[y])
            x = fa[x][i];
        if (x == y)
            return x;
    }
    for (int i = 19; ~i; i--)
        if (fa[x][i]!= fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

// 获取从节点 x 到节点 top 路径上不等于 w 的最大边权
int get_val(int x, int top, int w)
{
    int ret = -inf;
    for (int i = 19; ~i; i--)
    {
        if (deep[fa[x][i]] >= deep[top])
        {
            if (w!= maxs[x][i])
                ret = max(ret, maxs[x][i]);
            else
                ret = max(ret, mins[x][i]);
            x = fa[x][i];
        }
    }
    return ret;
}

signed main(){
    // 输入节点数和边数
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
        // 输入边的信息，并将边标记为不在最小生成树中
        scanf("%lld%lld%lld", &edge[i].u, &edge[i].v, &edge[i].w), edge[i].flag = 0;
    // 计算最小生成树
    mst();
    // 从根节点开始深度优先搜索，预处理倍增数组
    dfs(1, 0);
    for (int i = 1; i <= m; i++){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        bool flag = edge[i].flag;
        if (flag)
            continue;
        // 计算 u 和 v 的最近公共祖先
        int l = lca(u, v);
        // 获取从 u 到 lca 路径上不等于 w 的最大边权
        int maxs_u = get_val(u, l, w);
        // 获取从 v 到 lca 路径上不等于 w 的最大边权
        int maxs_v = get_val(v, l, w);
        // 更新次小生成树的答案
        ans = min(ans, sum - max(maxs_u, maxs_v) + w);
    }
    // 输出次小生成树的边权和
    printf("%lld\n", ans);
    return 0;
}
