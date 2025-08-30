void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (tr[0].son[i])
            q.push(tr[0].son[i]);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (tr[u].son[i]) {
                tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                q.push(tr[u].son[i]);
            } else
                tr[u].son[i] = tr[tr[u].fail].son[i];
        }
    }
}