# Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2) Editorial
##### By [Bahamin](https://codeforces.com/profile/Bahamin), 20 hours ago,
### ✨ **Hope you enjoyed the problems!** ✨

## [2127A - Mix Mex Max](/contest/2127/problem/A)  
**Idea:** [Bahamin](/profile/Bahamin "Master Bahamin")  
**Preparation:** [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari")

**Hints**

**Hint 1**

What happens if $\operatorname{mex}([a_i, a_{i+1}, a_{i+2}]) = 0$?

**Hint 2**

Now what happens if $\operatorname{mex}([a_i, a_{i+1}, a_{i+2}]) \neq 0$?

**Solution**

Let's see when does $\operatorname{mex}([a_i, a_{i+1}, a_{i+2}])$ equal $\max([a_i, a_{i+1}, a_{i+2}]) - \min([a_i, a_{i+1}, a_{i+2}])$.

**Case 1:** $\operatorname{mex}([a_i, a_{i+1}, a_{i+2}]) = 0$

This implies that all numbers are equal and non-zero, since otherwise $\min$ would be less than $\max$ and the difference wouldn't be $0$.

**Case 2:** $\operatorname{mex}([a_i, a_{i+1}, a_{i+2}]) \neq 0$

In this case $\min([a_i, a_{i+1}, a_{i+2}])$ should be $0$ because $0$ is in the sequence. So $\operatorname{mex}([a_i, a_{i+1}, a_{i+2}]) = \max([a_i, a_{i+1}, a_{i+2}])$ but this is not possible, since $\operatorname{mex}([a_i, a_{i+1}, a_{i+2}])$ should not be among $a_i$, $a_{i+1}$, or $a_{i+2}$.

So an array is good if all elements are equal and non-zero. Remove every $-1$ from $a$, then check whether all remaining elements are equal and non-zero.

**Code**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        set<int> s(v.begin(), v.end());
        
        s.erase(-1);
        if (s.size()<=1 && !s.count(0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
```

## [2127B - Hamiiid, Haaamid... Hamid?](/contest/2127/problem/B)  
**Idea:** [\_R00T](/profile/_R00T "Master _R00T") and [Error\_Yuan](/profile/Error_Yuan "Grandmaster Error_Yuan")  
**Preparation:** [\_R00T](/profile/_R00T "Master _R00T") and [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari")

**Hints**

**Hint 1**

The answer to the problem only depends on $x$, $n$, the index of the wall Hamid would hit if he moves to the left, and the index of the wall he would hit if he moves to the right.

**Hint 2**

If we denote the two indices defined in Hint 1 as $L$ and $R$, then in each of Hamid's turns, he can move in a way that ensures by the next time, either $L$ has decreased by at least one, or $R$ has increased by at least one, regardless of Mani's moves. So, if it's Hamid's turn, what is the maximum possible answer in terms of $L$, $R$, and $n$?

**Answer**

The answer is at most $\min(L + 1, n - R + 2)$.

**Solution**

Suppose it's Hamid's turn. If there is no wall to his right or to his left, he can escape the grid in one move. Otherwise, define:

-   $L$ as the index of the wall Hamid would reach if he moves to the left.
-   $R$ as the index of the wall he would reach if he moves to the right.

Hamid can move to the left and decrease $L$ by at least one. (Since $L$ is always to the left of Hamid's current position, when Hamid moves left, he reaches and destroys the wall at position L. As a result, on his next turn, the new L will be at least one position further to the left. meaning $L$ decreases by at least one, regardless of Mani's actions.) Similarly, Hamid can increase $R$ by at least $1$ by moving to the right and destroying the wall there.

So, since Hamid wants to escape in the minimum number of moves, he can escape the grid in at most $\min(L + 1, n - R + 2)$ moves.

On the other hand, with each of Hamid's moves, Mani can place a wall in such a way that $L$ decreases by at most one or R increases by at most one.

So the minimum number of moves Hamid needs is also $\min(L + 1, n - R + 2)$.

Therefore, assuming Hamid starts first, the answer is $\min(L + 1, n - R + 2)$.

Now consider Mani's first move. Since Mani wants to maximize the number of days Hamid needs. Moreover, with each of his moves, at least one of the $L$ or $R$ remains unchanged. So, on his first move, he can:

-   maximize $L + 1$ by setting $L = x - 1$, or
-   maximize $n - R + 2$ by minimizing $R$, setting it to $x + 1$.

So the answer becomes either $\min((x-1) + 1, n - R + 2)$ or $\min(L + 1, n - (x+1) + 1)$.

Because Mani wants the number of days to be as large as possible, the final answer is: $\max(\min(x, n - R + 2), \min(L + 1, n - x + 1))$

We can easily find L and R with a time complexity of $\mathcal{O}(n)$. Therefore, the problem is solved in $\mathcal{O}(n)$ time complexity.

**Code**

```cpp
#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n, x;
        string s;
        cin >> n >> x >> s;
        if(x==1 || x==n) {
            cout << "1\n";
            continue;
        }
        x--;
        int inf = 1e9;
        int lf=-inf, rg=inf;
        for(int i=x-1; i>=0; i--)
            if(s[i]=='#') {
                lf=i;
                break;
            }
        for(int i=x+1; i<n; i++)
            if(s[i]=='#') {
                rg=i;
                break;
            }
        if(lf==-inf && rg==inf) {
            cout << "1\n";
            continue;
        }
        cout << max(min(x+1, n-rg+1), min(lf+2, n-x)) << '\n';
    }
    return 0;
}
```
## [2127C - Trip Shopping](/contest/2127/problem/C)  
**Idea:** [Bahamin](/profile/Bahamin "Master Bahamin")  
**Preparation:** [Bahamin](/profile/Bahamin "Master Bahamin") and [\_R00T](/profile/_R00T "Master _R00T")

**Hints**

**Hint 1**

We can see that permuting arrays $a$ and $b$ **in the same way** or changing $a_i$ with $b_i$ for a specific index $i$ doesn't change the answer. WLOG assume $a_i \leq b_i$ is always true.

**Hint 2**

Imagine Ali selects indices $i$ and $j$ in a round of game. What are all the different new arrays Bahamin can achieve?

Can Ali ever achieve a $value$ less that the initial $value$?

**Answer**

He can't. Because Bahamin can always keep the chosen indices as they are, and so the $value$ won't change. No matter what Ali does.

**Solution**

Read the hints.

Let’s first address hint $2$. To determine all arrays that Bahamin can reach, WLOG assume $a_i \leq b_i \leq a_j \leq b_j$. The specific order doesn't matter, since Bahamin can permute them freely. Set $x_1 = a_i$, $x_2 = b_i$, $x_3 = a_j$, $x_4 = b_j$ — this makes the following cases reachable for Bahamin:

1.  $a_i := x_1, b_i := x_2, a_j := x_3, b_j := x_4 \rightarrow \space value = x_2 - x_1 + x_4 - x_3$
2.  $a_i := x_1, b_i := x_3, a_j := x_2, b_j := x_4 \rightarrow \space value = x_3 - x_1 + x_4 - x_2$
3.  $a_i := x_1, b_i := x_4, a_j := x_2, b_j := x_3 \rightarrow \space value = x_4 - x_1 + x_3 - x_2$

Other cases are similar (based on Hint $1$). We observe that the second and third options yield the same $value$, while the first option is exactly $2 \times (x_3 - x_2)$ **less** than the other two. There are now two possible cases:

**Case 1:** Ali can choose two indices $i$ and $j$ such that the ordering of $[a_i, b_i, a_j, b_j]$ already matches one of the second or third options. In this case, Bahamin cannot increase the value when he is **initially** given indices $i$ and $j$. Since Ali also cannot reduce the $value$, his optimal strategy is to always give Bahamin such indices so that the final $value$ remains equal to the initial $value$.

**Case 2:** Ali cannot find any two indices $i$ and $j$ that match the second or third option. This implies that for every pair of indices $i, j$, either $b_i &lt; a_j$ or $b_j &lt; a_i$. We claim the answer is $\sum\limits_{i=1}^{n} (b_i - a_i) + \min\limits_{1 \leq i, j \leq n, \space b_i &lt; a_j} (2 \times (a_j - b_i))$.

A strategy for Ali is to always select the two indices $i, j$ such that $b_i &lt; a_j$ and the difference $a_j - b_i$ is minimized. Bahamin can increase the $value$ only once — when he changes the configuration of indices $i, j$ from the first option to either the second or third option. We know this increases the initial $value$ by exactly $2 \times (a_j - b_i)$. Also, it's impossible for Ali to force any $value$ lower than this. Since regardless of Ali's selection, Bahamin can always change it to the second or third option, and by definition, any choice by Ali gives Bahamin a chance to increase $value$ by **at least** our claimed amount. Also Bahamin should skip his turn (i.e., make no changes) on all subsequent turns after the first.

Now to calculate the answer so that it fits the time limit, let’s first represent our array as a set of $n$ segments of the form $[a_i, b_i]$ on the number line. An interesting property of this representation is that the first option now corresponds to two completely separate intervals, while the second and third options correspond to two intersecting intervals.

Now finding the answer becomes relatively easy. Sort the intervals by their left endpoint. If there are two neighboring intervals that intersect, then the input satisfies the **Case 1** condition, and so the answer is the initial $value$. Otherwise, we observe that all pairs of intervals are non-intersecting, and thus the input satisfies the **Case 2** condition. The answer, based on **Case 2** and our earlier definitions, is $2 \times (\text{distance between closest two segments}) + (\text{initial value})$.

The two closest intervals must also be adjacent after sorting by their left endpoint. So, by computing the minimum distance between each pair of neighboring intervals, we obtain a solution in $\mathcal{O}(n \log n)$.

**Code**

**Bonus**

There were completely different versions of this problem at first.

The original version was that Ali and Bahamin would take turns, and on each turn, a player would perform **both** operations described in the problem. Their goals and the constraints were similar to what is stated in the final version of the question.

Can you solve it?

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5+5;

int n, k, a[MXN];

void Main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    vector<pair<int, int>> vec;
    long long ans = 0;
    for(int i=1, b; i<=n; i++) {
        cin >> b;
        if(b<a[i]) swap(b, a[i]);
        ans += b-a[i];
        vec.push_back({a[i], b});
    }
    sort(vec.begin(), vec.end());
    for(int i=1; i<n; i++)
        if(vec[i].first<=vec[i-1].second) {
            cout << ans << '\n';
            return;
        }
    int mn = 2e9;
    for(int i=1; i<n; i++)
        mn = min(mn, vec[i].first - vec[i-1].second);
    cout << ans + 2*mn << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--) Main();
}
```

## [2127D - Root was Built by Love, Broken by Destiny](/contest/2127/problem/D)  
**Idea:** [\_R00T](/profile/_R00T "Master _R00T") and [Bahamin](/profile/Bahamin "Master Bahamin")  
**Preparation:** [\_R00T](/profile/_R00T "Master _R00T") and [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari")

**Hints**

**Hint 1**

We can prove that the map of Destinyland contains no cycles.

**Hint 2**

Take a look at the map below:  
![ ](/predownloaded/ec/68/ec685d26ad5bed3f4580ccbc063510078b7cec17.png)

**Hint 3**

Prove that a tree can be a valid Destinyland map if and only if it does **not** contain a subtree that looks like the one shown in **Hint 2**.

**Hint 4**

If we remove all the leaves from the Destinyland tree, the remaining graph forms a simple path.

**Solution**

Let $G$ be the graph of the Destinyland map.

If there exists a subgraph $H$ of $G$ that cannot be a valid Destinyland map, then $G$ itself cannot be valid either.

To prove this, assume, for contradiction, that $G$ is valid but $H$ is not. Then, by removing the vertices and edges not in $H$, we get a subgraph $H$ that should also be valid. But it isn't! This contradicts our assumption, so $G$ cannot be valid either.

**Lemma 1:** A cycle of any length **cannot** be a valid Destinyland map.  
**Proof:** Assume the opposite. Let $v$ be the leftmost house on the northern side. It has two neighbors on the southern side. Let the one on the left be $L$ and the other one $R$. Since $L$ must have another neighbor besides $v$, that neighbor cannot be on the southern side, so it must be on the northern side. However, since $v$ is the leftmost node, this neighbor must be to the right of $v$, and the edge between $L$ and this neighbor would cross the edge $v$—$L$. This contradiction shows that $L$ cannot have another neighbor besides $v$, which contradicts our assumption that the graph is a cycle.

**Lemma 2:** The following tree **cannot** be a valid Destinyland map:  
![ ](/predownloaded/ec/68/ec685d26ad5bed3f4580ccbc063510078b7cec17.png)  
**Proof:** Vertices $2$, $3$, and $4$ are all on the side opposite vertex $1$. If we place them in order from left to right as $u_1$, $u_2$, and $u_3$, then the neighbor of $u_2$ will necessarily create a crossing either with edge $1$—$u_1$ or $1$—$u_3$. Therefore, it is impossible to arrange the vertices of this tree in a valid Destinyland layout.  
  
From **Lemma 1** and **Lemma 2**, we conclude that:

-   $G$ must be a tree.
-   No vertex in $G$ can be connected to three or more non-leaf neighbors.

Now, remove all the leaf nodes. Since these leaves are always non-cut vertices (i.e., their removal doesn't disconnect the tree), the remaining graph, if it exists, is still connected. Since all remaining vertices have degree at most $2$. So the resulting structure must be a **path**.

**Case 1:** The graph becomes empty after removing leaves.  
In this case, the original graph was just a single edge. So the answer is simply $2$.

**Case 2:** Only one vertex remains.  
In this case, the original tree was a star. Depending on which side we place the central vertex, and how we permute the leaves, the answer is: $2\times(n−1)!$

**Case 3:** Two connected non-leaf vertices $u$ and $v$ remain.  
In this case, there are $4$ valid placements depending on which one is on the northern side and how their adjacent leaves are arranged around the other. ( **Note:** It's impossible for either $u$ or $v$ to have neighbors on both sides of the other.)  
So the answer is: $4\times(d_u−1)!\times(d_v−1)!$ where $d_u$ and $d_v$ are the degrees of $u$ and $v$, respectively.

**Case 4:** The remaining structure is a path of length at least $3$.  
In this case, we have $4$ valid ways to place it. These depend on which vertices are placed on the northern side, and how the two vertices from one side with at least two vertices are positioned. (Since the path has at least $3$ vertices, there's no conflict.)

Now, we only need to arrange the leaves adjacent to each vertex relative to each other. Because their positions relative to the other vertices depend only on the four ways to arrange the main path. The proof of that is boring, so we won’t bore you with it :)

Let $S$ be the set of vertices on the path, and let $Saha_i$ be the number of leaves connected to vertex $i$. Then the total number of valid layouts is: $4 \times \prod\limits_{r \in S} (Saha_r!)$

To implement the solution:

1.  Check if the input graph is a tree.
2.  Verify that no vertex has more than two non-leaf neighbors.
3.  Count the number of non-leaf vertices.
4.  Based on that count, determine which case applies and compute the answer accordingly.

The entire algorithm runs in $\mathcal{O}(n)$ time.

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define SZ(x) int(x.size())

const int  MOD    = 1e9  + 7;
const int MXN    = 2e5  + 5;

int n, m, fact[MXN];
vector<int> adj[MXN];

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < MXN; i++) 
        fact[i] = (1ll * fact[i-1] * i) % MOD;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long ans = 2;
        int tl = 0;
        if (m >= n) ans = 0;
        for (int u = 1; u <= n; u++) {
            if (adj[u].size() > 1) {
                int x = 0;
                for (int v : adj[u]) {
                    x += (SZ(adj[v]) == 1);
                }
                if (x >= SZ(adj[u]) - 2) (ans *= fact[x]) %= MOD;
                else ans = 0;
            } else tl ++;
        }
        if (tl < n-1) tl = 2; else tl = 1;
        cout << (ans * tl % MOD) << '\n';
    }
    return 0;
}

```

## [2127E - Ancient Tree](/contest/2127/problem/E)  
**Idea:** [Bahamin](/profile/Bahamin "Master Bahamin")  
**Preparation:** [Bahamin](/profile/Bahamin "Master Bahamin") and [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari")

**Hints**

**Hint 1**

There are some vertices that will always be _cutie_, no matter how the other vertices are colored. What are these vertices?

**Hint 2**

We can show that there exists a coloring where only the vertices mentioned in **Hint 1** become _cutie_. So, the final answer is the sum of the weights of the vertices mentioned in **Hint 1**.

**Solution**

Read the hints.

We will use a very useful and interesting technique called the **Virtual Tree** (or **Auxiliary Tree**). You can learn more here: [Virtual Tree](https://usaco.guide/plat/VT?lang=cpp). There are other solutions to this problem, but they use a similar core idea.

The **virtual tree** of a set of vertices like $S$ is defined as this set:

$A = S \cup \{\operatorname{lca}(u, v) \mid u, v \in S \}$

Now let's build this virtual tree for the vertices of each color separately. After this, all vertices fall into three categories:

1.  Vertices that are in no virtual tree.
2.  Vertices that are in exactly one virtual tree.
3.  Vertices that appear in more than one virtual tree.

Every vertex like $u$ of the third type will definitely be _cutie_, because no matter what color it is assigned, at least one of the colors of the virtual trees it belongs to will be different from $u$'s color.

So the answer is at least the sum of the weights of all type-3 vertices.

To construct an example with exactly this answer, run a $DFS$ algorithm. Every time you enter a vertex $u$, consider the following cases:

-   It's type 2. In that case, color it with the color of the virtual tree it belongs to.
-   It's type 3. In that case, color it with any color from its subtree (such a color exists by definition). This vertex is _cutie_ anyway.
-   It's type 1 and there is some colored vertex in its subtree. Then color this vertex with that color.
-   It's type 1 and its entire subtree is uncolored. In that case, color this vertex with its parent's color.

To prove this coloring is valid, observe that coloring a vertex $u$ with a color from its subtree does not make any new vertices _cutie_ (because any such vertex would already have become _cutie_ due to the same color in $u$'s subtree). Also, no vertex strictly inside $u$'s subtree changes status. And $u$ itself doesn't increase the cost based on how we chose its color.

Now, for the case where we color $u$ with its parent’s color: if any new _cutie_ vertex appears, it must be the parent. But since both have the same color, there’s no additional cost.

Also, in this constructed example, we never introduce any new colors. So all colors stay within the range $[1, k]$.

Therefore, the final answer is always the sum of the weights of **type-3 vertices**—those that appear in more than one virtual tree. These virtual trees can be constructed in $\mathcal{O}(n \log n)$.

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 2e5+1, LOG = 18;

int n, k, w[MXN], c[MXN], par[LOG][MXN], stt[MXN], timer, h[MXN], cnt[MXN], col[MXN];
vector<int> g[MXN], cols[MXN];
bool mark[MXN], cutie[MXN];

void dfs(int v) {
    stt[v] = timer++;
    for(int i=1; i<LOG; i++) par[i][v] = par[i-1][par[i-1][v]];
    for(int u : g[v])
        if(u!=par[0][v]) {
            h[u] = h[v]+1;
            par[0][u] = v;
            dfs(u);
        }
}

inline int jump(int v, int d) {
    for(int i=0; i<LOG; i++)
        if(d>>i&1)
            v = par[i][v];
    return v;
}

inline int LCA(int u, int v) {
    if(h[u]<h[v]) swap(u, v);
    u = jump(u, h[u]-h[v]);
    if(u==v) return u;
    for(int i=LOG-1; i>=0; i--)
        if(par[i][u]!=par[i][v])
            u = par[i][u], v = par[i][v];
    return par[0][u];
}

void DFS(int v, int cc) {
    if(c[v]) cc=c[v];
    else c[v]=cc;
    for(int u : g[v])
        if(u!=par[0][v])
            DFS(u, cc);
}

void Main() {
    cin >> n >> k;
    timer = 0;
    for(int i=1; i<=n; i++) {
        cnt[i] = 0;
        col[i] = 0;
        g[i].clear();
        cutie[i] = 0;
        cols[i].clear();
    }
    for(int i=1; i<=n; i++) cin >> w[i];
    for(int i=1; i<=n; i++) cin >> c[i], cols[c[i]].push_back(i);
    for(int i=1, u,v; i<n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool fnd=0;
    for(int i=1; i<=n; i++)
        fnd |= c[i];
    if(!fnd) {
        cout << "0\n";
        for(int i=1; i<=n; i++) cout << "1 ";
        cout << '\n';
        return;
    }
    dfs(1);
    for(int i=1; i<=k; i++) {
        sort(cols[i].begin(), cols[i].end(), [&](int u, int v) {
            return stt[u]<stt[v];
        });
        vector<int> V;
        for(int j=0, u, v, lca; j+1<int(cols[i].size()); j++) {
            u = cols[i][j], v = cols[i][j+1], lca = LCA(u, v);
            if(!mark[lca]) {
                if(c[lca]) {
                    if(c[lca] != i) cutie[lca] = 1;
                    continue;
                }
                mark[lca] = 1;
                cnt[lca]++;
                col[lca] = i;
                V.push_back(lca);
            }
        }
        for(int v : V) mark[v] = 0;
        cols[i].clear();
    }
    ll val=0;
    for(int i=1; i<=n; i++) {
        if(cutie[i] || cnt[i]>1) val += w[i];
        if(!c[i] && cnt[i]==1) c[i] = col[i];
    }
    cout << val << '\n';
    for(int i=1; i<=n; i++)
        if(c[i]) {
            DFS(1, c[i]);
            break;
        }
    for(int i=1; i<=n; i++) cout << c[i] << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--) Main();
    return 0;
}
```

## [2127F - Hamed and AghaBalaSar](/contest/2127/problem/F)  
**Idea:** [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari") and [\_R00T](/profile/_R00T "Master _R00T")  
**Preparation:** [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari")

**Hints**

**Hint 1**

What exactly is $f(a)$?

**Answer**

$f(a)$ is the sum of maximums minus the sum of element right after a maximum minus $a_1$.

**Hint 2**

Fix the maximum. How to count the sum of maximums?

**Hint 3**

You need to solve the following sub-problem:

You are given three integers $n$, $m$, and $x$. How many arrays $a_1,a_2,\ldots,a_n$ exists such that:

-   $0 \leq a_i \leq x$ for all $1 \leq i \leq n$
-   $a_1 + a_2 + \ldots + a_n = m$

**Hint 4**

The sub-problem can be solved in $\mathcal{O}(m/x)$ using inclusion exclusion.

**Hint 5**

How to count the sum of an specific element in the sub-problem of **Hint 3**?

**Solution**

**Observation:** $f(a)$ is the sum of maximums minus the sum of element right after a maximum minus $a_1$.

**Proof**

Suppose that $1 = i_1 \lt i_2 \lt \ldots \lt i_k = n$ is the indices that we visit in the algorithm, and $1 \leq j_1 \lt j_2 \lt \dots \lt j_t = k$ is the indices such that $a_{i_{j_p}}$ is maximum for all $1 \leq p \leq t$.

If we group the indices like below:

-   $i_1, \ldots, i_{j_1}$
    
-   $i_{j_1+1}, \ldots, i_{j_2}$
    
-   ...
    
-   $i_{j_{t-1}+1}, \ldots, i_k$
    

each group will be increasing and $f(a)$ will be:

$(a_{i_{j_1}}-a_{i_1}) + \ldots + (a_n - a_{i_{j_{t-1}+1}}) = \sum\limits_{p=1}^{t}a_{i_{j_p}} - \sum\limits_{p=1}^{t-1}a_{i_{j_p+1}} - a_1$

Let $g(n, m, x)$ be the answer of the sub-problem in **Hint 3**. We can calculate $g(n, m, x)$ is $\mathcal{O}(m/x)$ using inclusion exclusion and "Stars and bars".

$g(n, m, x) = \sum\limits_{t=0}^{\lfloor \frac{m}{x+1} \rfloor}{(-1)^t \binom{n}{t} \binom{m + n - 1 - t(x+1)}{n - 1}}$

From now we fix $a_n = x$ and calculate the sum of $f(a)$ over all _snake_ arrays with maximum equal to $x$.

**Counting the sum of maximums:**

The sum of $a_n$ over all arrays is $x \cdot g(n-1,m-x,x)$. The sum of $a_i$ for all $1 \leq i \leq n-1$ such that $a_i=x$ is $x \cdot (n-1) \cdot g(n-2, m-2x, x)$.

**Counting the sum of $a_1$:**

Let $s_i$ be the sum of $a_i$ over all _snake_ arrays with $a_n=x$ for all $1 \leq i \lt n$.

It turns out that $s_i = s_j$ for all $1 \leq i, j \lt n$, because we can swap $a_i$ and $a_j$ in every array and there is no difference between $i$ and $j$.

The sum of $a_1,a_2,\ldots,a_{n-1}$ in every _snake_ array is $m-x$, so $s_1+s_2+\ldots+s_{n-1} = (m-x)g(n-1,m-x,x) \rightarrow \space s_1 = \frac{m-x}{n-1}g(n-1,m-x,x).$

**Counting the sum of elements right after a maximum:**

This part is similar to $a_1$ part. Suppose that $a_{i-1}=x$, the sum is $(m-2x)g(n-2,m-2x,x)$ for all $1 \lt i \lt n$, and $x \cdot g(n-2, m-2x,x)$ for $i=n$.

Since for each $x$ we just need $g(n-1, m-x, x)$ and $g(n-2, m-2x, x)$, the solution runs in $\sum\limits_{x=0}^{m}{\frac{m}{x+1}} = \mathcal{O}(m\log m)$.

**Code**

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MXN = 4e5+5;
const int MOD = 1e9+7;

ll power(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b&1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return res;
}

ll F[MXN], I[MXN];

void prep() {
    F[0] = 1;
    for(int i=1; i<MXN; i++) F[i] = F[i-1]*i%MOD;
    I[0] = I[1] = 1;
    for(int i=2; i<MXN; i++) I[i] = (MOD-MOD/i)*I[MOD%i]%MOD;
    for(int i=2; i<MXN; i++) (I[i] *= I[i-1]) %= MOD;
}
ll C(int n, int r) {
    return r<0 || r>n ? 0 : F[n]*I[r]%MOD*I[n-r]%MOD;
}
ll g(int n, int m, int l) {
    if(n==0) return m==0;
    ll ans = 0;
    for(int t=0; t<=n && t*(l+1)<=m; t++)
        (ans += C(n,t)*C(m+n-1-t*(l+1), n-1)%MOD*(t%2 ? MOD-1 : 1)%MOD) %= MOD;
    return ans;
}

void solve() {
    ll n, m, ans=0;
    cin >> n >> m;
    ll inv = power(n-1, MOD-2);
    for(ll x=0; x<=m; x++) {
        ll g1 = g(n-1, m-x, x), g2 = g(n-2, m-2*x, x);
        (ans += x*(g1+g2*(n-1)%MOD)) %= MOD;
        ll bad=0;
        (bad += (m-x)*g1%MOD*inv) %= MOD;
        (bad += x*g2) %= MOD;
        (bad += (m-2*x)*g2) %= MOD;
        (ans += MOD-bad) %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    prep();
    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
```

## [2127G1 - Inter Active (Easy Version)](/contest/2127/problem/G1)  
**Idea:** [Ali\_BBN](/profile/Ali_BBN "Candidate Master Ali_BBN")  
**Preparation:** [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari") and [Ali\_BBN](/profile/Ali_BBN "Candidate Master Ali_BBN")

**Hints**

**Step 0**

Consider the following graph: $i\to p_i$. We will see the permutation as the graph.

When asking a permutation $q$, the result is sum of whether $q^{-1}(i)&lt;q^{-1}(p_i)$.

**Hint 1**

Why is there a condition about $k$? If we do not have $k$, can the permutation $[2, 1, 4, 3]$ be guessed out?

**Hint 2.1**

When we ask a permutation, what does asking the reverse of the permutation help us with?

**Hint 2.2**

If we ask the reverse of the permutation except the index $k$, how many times is each edge of the permutation graph counted in total?

**Hint 3**

How to choose $k$?

**Solution**

Let $x$ be a number that we have not yet fixed, and let $k = x + 1$.

This partitions the array into three segments:

$ \begin{aligned} A &= [1, x] \\ B &= [x + 2, n - x] \\ C &= [n - x + 1, n] \end{aligned}$ 

This tripartition helps in controlling the query behavior.

**Queries:**

Say we want to find out who maps to vertex $i$, i.e., find $j$ such that $p_j = i$.

Here's how:

1.  Construct a permutation $q$ such that $q_k = i$
2.  Query this permutation $→$ receive answer $a$
3.  Reverse all elements of $q$ **except** the position $k$
4.  Query the reversed permutation $→$ receive answer $b$

If we consider the permutation graph of p:

-   Any edge not involving $i$ contributes **once** to the total count. Why?
-   The edge where $p_j = i$:
    -   Will **not** be counted if $j = q_k$. This is not possible because it is guaranteed in the question that $p_i\neq i$.
    -   Will be counted **in only one** of the two queries if $j \in q[A \cup C]$.
    -   Will be counted **neither** if $j \in q[B]$.
-   The edge where $p_i = j$ will **not** be counted at all, because $i$ is at index $k$.

Thus, $a + b$ is one of $[n - 2, n - 1]$ and by comparing $a + b$, we can find **which segment** $j$ (the predecessor of $i$) lies in.

**Repeating the Process:**

Once you know the predecessor is in a certain half, you repeat:

-   Repartition the candidate set into two
-   Choose one half to be placed in $A \cup C$, and the other in $B$ (If we had enough capacity).
-   Place $i$ at index $k$ again.
-   Do the same query + reverse trick

**Choosing k:**

If we set $x = \lfloor \frac{n+1}{4} \rfloor,\quad k = x + 1$, with each iteration (both in the first query and in the rest of the queries) the size of the candidate set shrinks by a factor of 2.

So to find the predecessor of one number $i$, we need $2 \log (n - 1)$ queries.

To find the entire permutation of $n$ elements $2 n\log (n - 1)$ queries.

We stay well within the $15 \cdot n$ limit.

**Code**

**Bonus**

This way can also be implemented with $2 \log (n - 1) + \sum\limits_{x=1}^{n - 1}{2 \log x}\sim 12 \cdot n$ queries.
```cpp
#include <bits/stdc++.h>
using namespace std;

#define SZ(x) int(x.size())

const int MXN = 1003;

int n, k, p[MXN], q[MXN], cnt=0;

int ask() {
    cout << "? ";
    for(int i=1; i<=n; i++) cout << q[i] << ' ';
    cout << endl;
    int r;
    cin >> r;
    return r;
}

void ans() {
    cout << "! ";
    for(int i=1; i<=n; i++) cout << p[i] << ' ';
    cout << endl;
}

bool mark[MXN];

void build(int i, vector<int> opt, vector<int> optbad) {
    fill(mark+1, mark+n+1, 0);
    fill(q+1, q+n+1, 0);
    q[k] = i;
    mark[i] = 1;
    for(int j=1; j<k && !opt.empty(); j++) {
        mark[q[j] = opt.back()] = 1;
        opt.pop_back();
    }
    for(int j=n; !opt.empty(); j--) {
        mark[q[j] = opt.back()] = 1;
        opt.pop_back();
    }
    for(int j=k+1; !optbad.empty(); j++) {
        mark[q[j] = optbad.back()] = 1;
        optbad.pop_back();
    }
    for(int j=1; j<=n; j++)
        if(!mark[j])
            opt.push_back(j);
    for(int j=1; j<=n; j++)
        if(!q[j]) {
            q[j] = opt.back();
            opt.pop_back();
        }
}

void rev() {
    vector<int> vec;
    for(int i=1; i<=n; i++)
        if(i!=k)
            vec.push_back(q[i]);
    for(int i=1; i<=n; i++)
        if(i!=k) {
            q[i] = vec.back();
            vec.pop_back();
        }
}

void Main() {
    cin >> n;
    k = (n+1)/4+1;
    cout << k << endl;
    for(int i=1; i<=n; i++) {
        vector<int> opt;
        for(int j=1; j<=n; j++)
            if(j!=i)
                opt.push_back(j);
        while(opt.size()>1) {
            int sz = SZ(opt) - min((SZ(opt)+1)/2, n-(2*k-1));
            build(i,
            vector<int>(opt.begin(), opt.begin()+sz),
            vector<int>(opt.begin()+sz, opt.end()));
            int val = ask();
            rev();
            val += ask();
            if(val==n-1) opt = vector<int>(opt.begin(), opt.begin()+sz);
            else opt = vector<int>(opt.begin()+sz, opt.end());
        }
        p[opt.back()] = i;
    }
    ans();
}

int32_t main() {
    int tc;
    cin >> tc;
    while(tc--) Main();
}
```

## [2127G2 - Inter Active (Hard Version)](/contest/2127/problem/G2)  
**Solution & Analysis:** [LMydd0225](/profile/LMydd0225 "International Grandmaster LMydd0225") and [Error\_Yuan](/profile/Error_Yuan "Grandmaster Error_Yuan")  
**Preparation:** [\_R00T](/profile/_R00T "Master _R00T") and [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari")

This version used an almost completely different approach from G1. Here's the step-by-step analysis:

**Analysis (Steps & Hints)**

**Step 0**

Consider the following graph: $i\to p_i$. We will see the permutation as the graph.

When asking a permutation $q$, the result is sum of whether $q^{-1}(i)&lt;q^{-1}(p_i)$.

**Hint 1.1**

Why is there a condition about $k$? If we do not have $k$, can the permutation $[2, 1, 4, 3]$ be guessed out?

**Step 1.2**

If there is a cycle of length $2$ in the permutation graph (that is, $p_i=j$ and $p_j=i$), exactly one of the two corresponding pairs to $(p_i, p_j)$ and $(p_j,p_i)$ will be counted in any query when we do not have $k$. So we have to use $k$ for cycles of length $2$. This inspires us to do casework on cycle length $=2$ or $\ge 3$.

**Step 2.1**

If the whole permutation graph is composed only of cycles of length $2$, can you guess out the permutation in about $\frac{1}{2}n\log n$ queries?

**Hint 2.2**

You need to use the property that the permutation graph is composed **only** of cycles of length $2$.

**Step 2.3**

Let's say you want to determine what is $p_i$. Query any permutation $q$ with $q_k=i$. If $p_i$ is among $q_1, q_2, \ldots, q_{k-1}$, the response to the query will be $\frac{n}{2}$, otherwise, $p_i$ is among $q_{k+1}, q_{k+2}, \ldots, q_n$, and the response will be $\frac{n}{2}-1$. You can verify this by yourself. Note that permutation graph is composed **only** of cycles of length $2$.

Thus, we can put $k$ around $\frac{n}{2}$ and apply binary search for a single $i\to p_i$ with $\log n$ queries. Note that when we get $p_i=j$, we also get $p_j=i$. So we only need $\frac{1}{2}n\log n$ queries in total.

**Step 3.1**

How can we distinguish $i\to p_i$ is in which kind of cycle, length of $2$ or length $\ge 3$? Try to solve this for a single $i$ in $2\log n$ queries. Note that you do **not** need to determine $p_i$, you just need to tell whether $i\to p_i$ is in a cycle of length $2$.

**Hint 3.2**

If $i\to p_i$ is in a cycle of length $\ge 3$, we have $l$ and $j$ such that $l\to i\to j$ and $l\ne j$. Otherwise, $l=j$.

**Hint 3.3**

Consider bitmasks.

**Hint 3.4**

Consider cyclic shifts. Do not use $k$.

**Step 3.5**

Consider the following two queries ($m&lt;k$):

1.  $[q_1, q_2, q_3, \ldots, q_m, \ldots, q_k, \ldots]$;
2.  $[q_m, q_1, q_2, \ldots, q_{m-1}, \ldots, q_k, \ldots]$.

Only the contribution of $x\to q_m\to y$ may change: Let's say $A=\{q_1,q_2,\ldots,q_{m-1}\}$, $B=\{q_{m+1}, q_{m+2}, \ldots q_n\}$. If $x$ and $y$ are both inside $A$ or both inside $B$, responses to query **1.** and **2.** will be the same. Otherwise, answer changes by exactly $1$. If the responses are different, we can next tell whether $x_i$ is in $A$ by looking at whether the difference is $1$ or $-1$. However, if the responses are the same, we can't tell whether they are both in $A$ or both in $B$.

An idea to tell whether $x=y$ is to group numbers by their bitmasks. We can use $\log n$ times such two queries to ask for each bit (let numbers with 0 on this bit in $A$, those with 1 in $B$). In the end, we will get $x\oplus y$. Then we surely get whether $x=y$.

**Hint 3.6**

**Step 3.5** needs $2\log n$ queries for a single element. Can you use $n\log n$ queries to solve the problem in **Step 3.5** for all elements? Note that we are doing cyclic shifts.

**Step 3.7**

Note that we are doing cyclic shifts. In fact, for each $i$, we just need it to appear at $q_1$ and $q_m$ respectively, without changing the set $A$. Then, for a certain set $A$, we can do cyclic shifts $|A|$ times to get all information we need. Similar for $B$. Thus, we finished the task in **Hint 3.6** in $n\log n$ queries.

Since we will fix $k$ around $\frac{n}{2}$ for cycles with length $2$, we must ensure that $|A|$ and $|B|$ are around $\frac{n}{2}$. But this is not always true. Fortunately, we can resolve this issue by assigning each integer an unqiue number $c_i$, where $0\le c_i\le 2^{\lceil\log n\rceil}-1$, so that there will be exactly $\frac{n}{2}$ (or floor and ceil) 0s and 1s on each bit. We will group the indices by $c_i$ instead. Now we can put $k=\lceil\frac{n}{2}\rceil+1$.

**Final Steps**

Here are the final steps of this problem. First, we run the algorithm in **Step 3**. Now we get all $x_i \oplus p_i$, where $x_i\to i\to p_i$ holds.

First, we will determine all $p_i$\-s on cycles of length $\ge 3$. Note that we have determined all $x_i\oplus p_i$, so we only need to determine one edge for each cycle.

Note that in **Step 3**, when responses to two queries are different, we can know whether $p_i$ is in $A$ or $x_i$ is in $A$. Note that we can change $m$ arbitrarily, so we can apply binary search on $m$ to get one of $p_i$ and $x_i$. That finishes the task in $\log n$ queries for each cycle. On average for each element, it is at most $\frac{1}{3}\log n$ queries.

After that, we know all $p_i$\-s on cycles of length $\ge 3$, and we can calculate the response to any query $[q_1, q_2,\ldots,q_n]$ easily if we don't have $k$. Similar to **Step 2**, we can determine all $p_i$\-s on cycles of length $2$ in $\frac{1}{2}n\log n$ queries. On average for each element, it is $\frac{1}{2}\log n$ queries. Thus, in the worst case where the whole permutation graph consists only of cycles of length $2$, the total number of queries is $1.5\lceil\log n\rceil\cdot n$. When $n=100$, it is $10.5\cdot n$, a little larger than the limit. We can apply a trivial optimization when doing **Step 2**: do binary serach on possible indices instead of all indices. This will use a total of at most $n\log n+\sum\limits_{i=0}^{\lfloor(n-1)/2\rfloor} \log(n-1-2\cdot i)$ queries. When $n=100$, it is $986$, which fits the constraints well.

**Code**

```cpp
#include <bits/stdc++.h>
#define all(s) s.begin(), s.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;

int T;

void solve() {
    int n; cin >> n;
    const int k = (n + 1) / 2;
    const int M = __lg(n - 1) + 1;
    cout << k + 1 << endl;
    
    vector<int> p(n + 1);
    
    auto query = [&](vector<int> &q) -> int {
        cout << "? ";
        for (int i = 1; i <= n; i++) cout << q[i] << " \n"[i == n];
        cout.flush();
        int res; cin >> res;
        return res;
    };
    
    vector<int> c(n + 1), d(1 << M);
    auto binary_coding = [&]() {
        for (int i = 0, cnt = 1; cnt <= n; i++, cnt++) {
            c[cnt++] = i;
            if (cnt <= n) c[cnt] = (1 << M) - 1 - i;
        }
        for (int i = 1; i <= n; i++) d[c[i]] = i;
        return;
    };
    
    vector<int> xors(n + 1);
    vector<vector<int>> res1(M, vector<int>(n + 1)), res2(M, vector<int>(n + 1));
    vector<int> good, bad;
    auto getXORs = [&]() {
        for (int bit = 0; bit < M; bit++) {
            vector<int> A, B;
            for (int i = 1; i <= n; i++) {
                if (c[i] & (1 << bit)) B.emplace_back(i);
                else A.emplace_back(i);
            }
            int m = A.size(), l = B.size();
            for (int i = 0; i < m; i++) {
                vector<int> q(n + 1);
                for (int j = 0; j < m; j++) q[j + 1] = A[(j + i) % m];
                for (int j = 0; j < l; j++) q[j + m + 1] = B[j];
                int res = query(q);
                res1[bit][q[1]] = res;
                res2[bit][q[m]] = res;
            }
            for (int i = 0; i < l; i++) {
                vector<int> q(n + 1);
                for (int j = 0; j < l; j++) q[j + 1] = B[(j + i) % l];
                for (int j = 0; j < m; j++) q[j + l + 1] = A[j];
                int res = query(q);
                res1[bit][q[1]] = res;
                res2[bit][q[l]] = res;
            }
            for (int i = 1; i <= n; i++) {
                if (res1[bit][i] != res2[bit][i]) xors[i] ^= (1 << bit);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (xors[i] != 0) good.emplace_back(i);
            else bad.emplace_back(i);
        }
        return;
    };
    auto solve3 = [&]() {
        for (auto pos : good) {
            if (p[pos]) continue;
            int x = xors[pos], bit = __lg(x & (-x));
            vector<int> A, B;
            for (int i = 1; i <= n; i++) {
                if (c[i] & (1 << bit)) B.emplace_back(i);
                else A.emplace_back(i);
            }
            if (c[pos] & (1 << bit)) swap(A, B);
            int m = A.size(), l = B.size();
            int id = 0;
            for (int i = 0; i < m; i++) if (A[i] == pos) id = i;
            int L = 2, R = m;
            vector<int> base(n + 1);
            for (int j = 0; j < m; j++) base[j + 1] = A[(j + id) % m];
            for (int j = 0; j < l; j++) base[j + m + 1] = B[j];
            while (L < R) {
                int mid = (L + R) >> 1;
                vector<int> q(n + 1);
                for (int i = 1; i < mid; i++) q[i] = base[i + 1];
                q[mid] = base[1];
                for (int i = mid + 1; i <= n; i++) q[i] = base[i];
                int res = query(q);
                if (res != res1[bit][pos]) R = mid;
                else L = mid + 1;
            }
            int s = 0;
            if (res2[bit][pos] > res1[bit][pos]) p[base[L]] = pos, s = base[L];
            else p[pos] = base[L], s = pos;
            while (!p[p[s]]) {
                int X = xors[p[s]];
                p[p[s]] = d[X ^ c[s]];
                s = p[s];
            }
        }
    };
    auto solve2 = [&]() {
        for (auto pos : bad) {
            if (p[pos]) continue;
            auto calc = [&](vector<int> &q) {
                int val = count(all(p), 0) / 2;
                vector<int> inv(n + 1);
                for (int i = 1; i <= n; i++) inv[q[i]] = i;
                for (int i = 1; i <= n; i++) val += (inv[i] < inv[p[i]]);
                return val;
            };
            vector<int> cand, ok;
            for (int i = 1; i <= n; i++) {
                if (i != pos && !p[i]) cand.emplace_back(i);
                if (p[i]) ok.emplace_back(i);
            }
            while ((int)cand.size() != 1) {
                vector<int> q = { 0 }, L, R;
                int len = ((int)cand.size() + 1) / 2;
                for (int i = 0; i < len; i++) q.emplace_back(cand[i]), L.emplace_back(cand[i]);
                for (int i = len; i < k; i++) q.emplace_back(ok[i - len]);
                q.emplace_back(pos);
                for (int i = len; i < (int)cand.size(); i++) q.emplace_back(cand[i]), R.emplace_back(cand[i]);
                for (int i = k - len; i < (int)ok.size(); i++) q.emplace_back(ok[i]);
                int res = query(q);
                res -= calc(q);
                if (res != 0) swap(L, R);
                cand = L;
                for (auto x : R) ok.emplace_back(x);
            }
            p[pos] = cand[0];
            p[cand[0]] = pos;
        }
    };
    
    binary_coding();
    getXORs();
    solve3();
    solve2();
    
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << p[i] << " \n"[i == n];
    cout.flush();
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
}
```

## [2127H - 23 Rises Again](/contest/2127/problem/H)  
**Idea:** [sweetweasel](/profile/sweetweasel "International Master sweetweasel") and [eren\_\_](/profile/eren__ "Grandmaster eren__")  
**Preparation:** [Hamed\_Ghaffari](/profile/Hamed_Ghaffari "Grandmaster Hamed_Ghaffari") and [\_R00T](/profile/_R00T "Master _R00T")

**Hints**

**Hint 0**

Each connected component of a _candy graph_ is either a simple path or a simple cycle.

**Hint 1**

Try to break the problem down into smaller parts.

**Hint 2**

Take a DFS tree, at most $5$ back-edges pass through each vertex.

**Hint 3**

Choose a vertex $v$, brute force on the back-edges that pass through $v$ and appears in the subgraph with maximum number of edges, then remove $v$ and all back-edges that pass through $v$.

**Hint 4**

Now we have to solve the following sub-problem for each connected component:

You are given a simple connected graph that each vertex belongs to at most $5$ simple cycles, and an array $d_1,d_2,\ldots,d_n (0 \leq d_i \leq 2)$. What is the subgraph with maximum number of edges that degree of vertex $i$ is at most $d_i$.

**Hint 5**

The sub-problem can be solved in $\mathcal{O}(2^nnm)$ with dp bitmask.

**Hint 6**

Let $N$ be the size of the component with the maximum size after removing $v$ and back-edges that pass through $v$.

We can solve the problem in $\mathcal{O}(2^5 2^NNm)$.

**Hint 7**

Choose $v$ as the centroid of the DFS tree.

Since $N \leq n/2$ the complexity will be $\mathcal{O}(2^5 2^{n/2}nm)$.

**Hint 8**

Is the complexity really $\mathcal{O}(2^5 2^{n/2}nm)$?

**Solution**

Each connected component of a _candy graph_ is either a simple path or a simple cycle.

Take a DFS tree, at most $5$ back-edges pass through each vertex, then choose a vertex $v$, brute force on the back-edges that pass through $v$ and appears in the subgraph with maximum number of edges, then remove $v$ and all back-edges that pass through $v$.

Let $d_i$ be the maximum degree that vertex $i$ can have. Initially $d_i=2$ for each vertex. Each back-edge $(x,y)$ that you select, reduces $d_x$ and $d_y$ by $1$. If after selecting back-edges that pass through $v$, there exists a vertex with negative $d$, skip this case. Otherwise you have to solve the sub-problem in **Hint 4** for every connected component.

We can solve the sub-problem with the following dp bitmask:

Let $ans_{mask}$ be the answer for $mask$, and let $dp_{mask,u,v,l1}$ be the answer for $mask$ where the last path we selected is from $u$ to $v$ and $l1 \in \text{{0, 1}}$ means that the length of the path is $1$ or not.

Transitions:

-   Start a new path: $ans_{mask}+1 \to dp_{mask,u,v,1}$, if $(u,v)$ is an edge outside $mask$ with $d_u, d_v \geq 1$.
-   Add a vertex to the last path: $dp_{mask,u,v,l1}+1 \to dp_{mask+2^w,u,w,0}$, if $w$ is a vertex outside $mask$ and adjacent to $v$, and $d_v = 2, d_w \geq 1$.
-   Make the last path cycle: $dp_{mask,u,v,0}+1 \to ans_{mask}$, if there exists a $(u, v)$ edge, and $d_u = d_v = 2$.
-   Skip a vertex: $ans_{mask} \to ans_{mask+2^w}$, if $w$ is a vertex outside $mask$.

Also, you have to solve the sub-problem for each component twice, because you can choose a DFS tree edge connected to the vertex that you've deleted and it reduces $d$ of one vertex in that component.

It can be seen that if $N$ be the size of the component with the maximum size, the complexity will be $\mathcal{O}(2^NNm)$ for a fixed set of back-edges, and $\mathcal{O}(2^52^NNm)$ in total.

If we select $v$ as the centroid of the DFS tree $N$ will be less than or equal to $n/2$ so the complexity will be $\mathcal{O}(2^5 2^{n/2}nm)$.

It can be proven that $m \leq 3n$ in graphs that each vertex belongs to at most $5$ simple cycles. So the complexity will be $\mathcal{O}(2^52^{n/2}n^2)$.

**Proof**

We prove this by induction. suppose that $m \leq 3n$ for all graphs with $n \lt N$.

Take a DFS tree, we can prove that the degree of a leaf is at most $3$, because otherwise at least $3$ back-edges would exit that leaf and there would be at least $6$ cycles containing that leaf.

So there always exists a vertex with degree $\leq 3$, we can remove it, $m \leq 3(N-1) + 3 = 3N$.

**Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define SZ(x) int(x.size())
#define maxs(a, b) (a = max(a, b))

const int MXN = 30, MXM = MXN*(MXN-1)/2;

int n, m, U[MXM], V[MXM];
vector<int> g[MXN];
bool tedge[MXM], have_edge[MXN][MXN];
int sz[MXN];

void dfs1(int v) {
    sz[v] = 1;
    for(int i : g[v]) {
        int u = v^U[i]^V[i];
        if(!sz[u]) {
            tedge[i] = 1;
            dfs1(u);
            sz[v] += sz[u];
        }
    }
}

int centroid(int v, int p=-1) {
    for(int i : g[v]) if(tedge[i]) {
        int u = v^U[i]^V[i];
        if(u!=p && sz[u]+sz[u]>n)
            return centroid(u, v);
    }
    return v;
}

int ID[MXN], id_counter;
vector<int> vertices[MXN];
int dp[1<<(MXN>>1)][MXN>>1][MXN>>1][2], ans_tmp[1<<(MXN>>1)], ans[2];

void dfs_id(int v, int p=-1) {
    vertices[ID[v] = id_counter].push_back(v);
    for(int i : g[v]) if(tedge[i]) {
        int u = v^U[i]^V[i];
        if(u!=p) dfs_id(u, v);
    }
}

int deg[MXN], pos[MXN];

int solve_(int id) {
    int n = SZ(vertices[id]);
    for(int msk=0; msk<(1<<n); msk++) {
        ans_tmp[msk] = -1e9;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int x : {0,1})
                    dp[msk][i][j][x] = -1e9;
    }
    ans_tmp[0] = 0;
    for(int msk=0; msk<(1<<n); msk++) {
        for(int i=0; i<n; i++) if(msk>>i&1)
            for(int j=0; j<n; j++) if(i!=j && (msk>>j&1)) {
                if(deg[vertices[id][j]]==2) {
                    for(int eid : g[vertices[id][j]]) if(ID[U[eid]]==ID[V[eid]]) {
                        int u = vertices[id][j]^U[eid]^V[eid];
                        if(!(msk>>pos[u]&1) && deg[u]>=1)
                            maxs(dp[msk^(1<<pos[u])][i][pos[u]][0],
                            max(dp[msk][i][j][0], dp[msk][i][j][1])+1);
                    }
                    if(deg[vertices[id][i]]==2 && have_edge[vertices[id][i]][vertices[id][j]])
                        maxs(ans_tmp[msk], dp[msk][i][j][0]+1);
                }
                maxs(ans_tmp[msk], max(dp[msk][i][j][0], dp[msk][i][j][1]));
            }
        for(int i=0; i<n; i++) if(!(msk>>i&1)) {
            maxs(ans_tmp[msk^(1<<i)], ans_tmp[msk]);
            if(deg[vertices[id][i]]>=1)
                for(int eid : g[vertices[id][i]]) if(ID[U[eid]]==ID[V[eid]]) {
                    int u = vertices[id][i]^U[eid]^V[eid];
                    if(deg[u]>=1 && !(msk>>pos[u]&1))
                        maxs(dp[msk^(1<<i)^(1<<pos[u])][i][pos[u]][1], ans_tmp[msk]+1);
                }
        }
    }
    return ans_tmp[(1<<n)-1];
}

void solve(int id, int cent_neighbour) {
    ans[0] = solve_(id);
    if(deg[cent_neighbour]!=0) {
        deg[cent_neighbour]--;
        ans[1] = solve_(id);
    }
    else ans[1] = -1e9;
}

void Main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        g[i].clear();
        vertices[i].clear();
        sz[i] = 0;
        for(int j=0; j<n; j++)
            have_edge[i][j] = 0;
    }
    for(int i=0; i<m; i++) {
        tedge[i] = 0;
    }
    for(int i=0,u,v; i<m; i++) {
        cin >> u >> v;
        u--, v--;
        have_edge[u][v] = have_edge[v][u] = 1;
        U[i] = u;
        V[i] = v;
        g[u].push_back(i);
        g[v].push_back(i);
    }
    dfs1(0);
    int cent = centroid(0);
    
    ID[cent] = 0;
    id_counter = 0;
    for(int i : g[cent]) if(tedge[i]) {
        int u = cent^U[i]^V[i];
        id_counter++;
        dfs_id(u, cent);
        for(int j=0; j<SZ(vertices[id_counter]); j++)
            pos[vertices[id_counter][j]] = j;
    }

    vector<int> be;
    for(int i=0; i<m; i++)
        if(!tedge[i] && (ID[U[i]]^ID[V[i]])) be.push_back(i);

    int besz = SZ(be), answer = -1e9;

    for(int msk=0; msk<(1<<besz); msk++) {
        fill(deg, deg+n, 2);
        for(int i=0; i<besz; i++) if(msk>>i&1)
            deg[U[be[i]]]--, deg[V[be[i]]]--;
        bool deg3 = 0;
        for(int i=0; i<n; i++)
            if(deg[i]<0) {
                deg3 = 1;
                break;
            } 
        if(deg3) continue;
        int cur[3];
        cur[0] = cur[1] = cur[2] = -1e9;
        cur[deg[cent]] = __builtin_popcount(msk);
        for(int i : g[cent]) if(tedge[i]) {
            int u = cent^U[i]^V[i];
            solve(ID[u], u);
            cur[0] = max(cur[0]+ans[0], cur[1]+ans[1]+1);
            cur[1] = max(cur[1]+ans[0], cur[2]+ans[1]+1);
            cur[2] = cur[2]+ans[0];
        }
        answer = max({answer, cur[0], cur[1], cur[2]});
    }
    cout << answer << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--) Main();
    return 0;
}
```
**Apology**

It turns out there are some very simple randomized solutions we hadn’t anticipated, as well as approaches using matching and even unexpected ones like backtracking. Unfortunately, these are quite hard to detect and reject without knowing beforehand.

We sincerely apologize for this mistake. We hope you enjoyed the rest of the problems.