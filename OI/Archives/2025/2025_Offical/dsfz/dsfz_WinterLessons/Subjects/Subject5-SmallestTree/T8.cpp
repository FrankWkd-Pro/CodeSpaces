#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>

#define inf 100000000000000
#define int long long
using namespace std;
const int N = 4e5;

// �ڵ����ͱ���
int n, m;
// �洢���մ𰸣���ʼ��Ϊ�����
int ans = inf;

// �ߵĽṹ�壬�洢�ߵ������˵� u �� v���ߵ�Ȩ�� w���Լ��ñ��Ƿ�����С�������У�flag��
struct link
{
    int u, v, w;
    bool flag;
    // ����С������������ڱߵ����򣬰��ձߵ�Ȩ����������
    bool operator<(const link& ret) const
    {
        return w < ret.w;
    }
} edge[N + 10];

// �洢ͼ���ڽӱ�ڵ���Ϣ���洢�ڽӽڵ� to �ͱߵĳ��� len
struct node
{
    int to, len;
};
// �ڽӱ�
vector<node>e[N + 10];
// �洢ÿ���ڵ�ĸ��ڵ㣬���ڱ�����
int fa[N + 10][20];
// �洢ÿ���ڵ㵽���ڵ�·���ϵ�����Ȩ�����ڱ�����
int maxs[N + 10][20];
// �洢ÿ���ڵ㵽���ڵ�·���ϵĴδ��Ȩ�����ڱ�����
int mins[N + 10][20];
// �洢ÿ���ڵ�����
int deep[N + 10];
// �洢��С�������ı�Ȩ��
int sum;
// ���鼯���飬�����жϽڵ�ĸ��ڵ�
int f[N + 10];

// ���鼯�Ĳ��Ҳ����������ҵ��ڵ� x �ĸ��ڵ�
int getfa(int x)
{
    if (f[x] == x)
        return x;
    // ·��ѹ�������ڵ�ĸ��ڵ����Ϊ���ڵ�
    return f[x] = getfa(f[x]);
}

// ������С������
void mst()
{
    int cnt = 0;
    // ��ʼ�����鼯��ÿ���ڵ�ĸ��ڵ�Ϊ����
    for (int i = 1; i <= n; i++)
        f[i] = i;
    // �Ա߰���Ȩ�ؽ�������
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        // �ҵ��ڵ� u �� v �ĸ��ڵ�
        int fu = getfa(u), fv = getfa(v);
        if (fu!= fv)
        {
            // �ϲ��������ϣ����¸��ڵ�
            f[fu] = fv;
            cnt++;
            // ������С�������ı�Ȩ��
            sum += w;
            // ��Ǹñ�����С��������
            edge[i].flag = 1;
            // ���߼����ڽӱ���
            e[u].push_back({ v, w });
            e[v].push_back({ u, w });
        }
        // ����С�������ı����ﵽ n-1 ʱ������
        if (cnt >= n - 1)
            break;
    }
}

// �����������������Ԥ����������
void dfs(int u, int father)
{
    // ���㵱ǰ�ڵ�����
    deep[u] = deep[father] + 1;
    for (int i = 1; i <= 19; i++)
    {
        // �������¸��ڵ�
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        // ������������Ȩ
        maxs[u][i] = max(maxs[u][i - 1], maxs[fa[u][i - 1]][i - 1]);
        if (maxs[u][i - 1]!= maxs[fa[u][i - 1]][i - 1])
        {
            // �������·���ϵ�����Ȩ��ͬ�����´δ��Ȩ
            mins[u][i] = min(maxs[u][i - 1], maxs[fa[u][i - 1]][i - 1]);
            mins[u][i] = max(mins[u][i], mins[u][i - 1]);
            mins[u][i] = max(mins[u][i], mins[fa[u][i - 1]][i - 1]);
        }
        else
            // �������·���ϵ�����Ȩ��ͬ�����´δ��Ȩ
            mins[u][i] = max(mins[u][i - 1], mins[fa[u][i - 1]][i - 1]);
    }
    // �����ڽӽڵ�
    for (auto v : e[u])
    {
        if (father == v.to)
            continue;
        // �����ڽӽڵ�ĸ��ڵ�ͳ�ʼ��Ȩ��Ϣ
        fa[v.to][0] = u;
        maxs[v.to][0] = v.len;
        mins[v.to][0] = -inf;
        // �����ݹ�����
        dfs(v.to, u);
    }
}

// ���������������
int lca(int x, int y)
{
    // ��֤ x ����ȴ��ڵ��� y �����
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

// ��ȡ�ӽڵ� x ���ڵ� top ·���ϲ����� w ������Ȩ
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
    // ����ڵ����ͱ���
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
        // ����ߵ���Ϣ�������߱��Ϊ������С��������
        scanf("%lld%lld%lld", &edge[i].u, &edge[i].v, &edge[i].w), edge[i].flag = 0;
    // ������С������
    mst();
    // �Ӹ��ڵ㿪ʼ�������������Ԥ����������
    dfs(1, 0);
    for (int i = 1; i <= m; i++){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        bool flag = edge[i].flag;
        if (flag)
            continue;
        // ���� u �� v �������������
        int l = lca(u, v);
        // ��ȡ�� u �� lca ·���ϲ����� w ������Ȩ
        int maxs_u = get_val(u, l, w);
        // ��ȡ�� v �� lca ·���ϲ����� w ������Ȩ
        int maxs_v = get_val(v, l, w);
        // ���´�С�������Ĵ�
        ans = min(ans, sum - max(maxs_u, maxs_v) + w);
    }
    // �����С�������ı�Ȩ��
    printf("%lld\n", ans);
    return 0;
}
