#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
struct edge {
    int u, v, w;
}e[500010];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int ans[500010];
vector<pii> ee[500010];
bool vis[500010];
const int MD = 20;
int anc[500100][MD + 1], d[500010], dep[500010];

void dfs(int x, int ff) {
    anc[x][0] = ff;
    for (int i = 1; i <= MD; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
    for (auto &t : ee[x]) {
        if (t.first != ff) {
            dep[t.first] = dep[x] + 1;
            d[t.first] = d[x] ^ e[t.second].w;
            dfs(t.first, x);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int delta = dep[u] - dep[v];
    for (int i = MD; i >= 0; i--) {
        if (delta & (1 << i)) {
            u = anc[u][i];
        }
    }
    if (u == v) return u;
    for (int i = MD; i >= 0; i--) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v;
        if (find(u) == find(v)) continue;
        fa[find(u)] = find(v);
        ans[i] = 1;
        ee[u].push_back(pii(v, i));
        ee[v].push_back(pii(u, i));
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
}