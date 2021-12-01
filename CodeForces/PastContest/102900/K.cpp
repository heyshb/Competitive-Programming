#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m;
const int MAXN = 202020;
char col[MAXN];
vector<int>e[MAXN];
int dfn[MAXN], low[MAXN];

struct RootedTree {
    using len_type = long long;
    using pr = pair<len_type, int>;
    static const int MAXD = 21; // for LCA; (1 << (MAXD - 1)) >= N
    vector<vector<pr> >e;
    vector<int> fa;
    vector<len_type> dis_to_root; // dis from root
    vector<int> dep; // Root has a dep of 1
    vector<vector<int> > anc; // anc[i][j] is the (2^j) ancestor of i
    vector<int> dfn, dfnL, dfnR;
    vector<int> size, hson, top; // for heavy-light-decomposite

    int N, Root;
    RootedTree() {}
    RootedTree(int _N, int _Root = 1) : N(_N), Root(_Root) {
        e.assign(N + 1, vector<pr>());
        fa.assign(N + 1, 0);
        dis_to_root.assign(N + 1, 0);
        dep.assign(N + 1, 0);
        dfn.assign(N + 1, 0); // If need multiple dfn, modify to 2 * N + 1?
        dfnL.assign(N + 1, 0);
        dfnR.assign(N + 1, 0);
        size.assign(N + 1, 0);
        hson.assign(N + 1, 0);
    }
    void add_edge(int u, int v, len_type w = 1) {
        e[u].push_back(pr(w, v));
        e[v].push_back(pr(w, u));
    }
    void dfs(int x, int FA, bool calc_lca, int &time_tag) {
        dfn[++time_tag] = x;
        dfnL[x] = time_tag;
        fa[x] = FA;
        if (calc_lca) {
            anc[x][0] = FA;
            for (int i = 1; i < MAXD; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
        }
        size[x] = 1;
        hson[x] = 0;
        for (auto &t : e[x]) {
            if (t.second == FA) continue;
            dep[t.second] = dep[x] + 1;
            dis_to_root[t.second] = dis_to_root[x] + t.first;
            dfs(t.second, x, calc_lca, time_tag);
            size[x] += size[t.second];
            if (hson[x] == 0 || size[t.second] > size[hson[x]]) {
                hson[x] = t.second;
            }
        }
        dfnR[x] = time_tag;
    }
    void init(bool calc_lca = false) {
        dep[Root] = 1;
        dis_to_root[Root] = 0;
        if (calc_lca) anc.assign(N + 1, vector<int>(MAXD, 0));
        int time_tag = 0;
        dfs(Root, 0, calc_lca, time_tag);
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int delta = dep[u] - dep[v];
        for (int i = MAXD - 1; i >= 0; i--) {
            if (delta & (1 << i)) {
                u = anc[u][i];
            }
        }
        if (u == v) return u;
        for (int i = MAXD - 1; i >= 0; i--) {
            if (anc[u][i] != anc[v][i]) {
                u = anc[u][i];
                v = anc[v][i];
            }
        }
        return anc[u][0];
    }
    int K_ancestor(int x, int K) {
        for (int i = 0; i < MAXD; i++) {
            if ((K >> i) & 1) x = anc[x][i];
        }
        return x;
    }
    void hld_dfs(int x, int &time_tag) {
        dfn[++time_tag] = x;
        dfnL[x] = time_tag;
        if (fa[x] && x == hson[fa[x]]) {
            top[x] = top[fa[x]];
        } else {
            top[x] = x;
        }
        if (hson[x]) hld_dfs(hson[x], time_tag);
        for (auto &t : e[x]) {
            if (t.second != fa[x] && t.second != hson[x]) {
                hld_dfs(t.second, time_tag);
            }
        }
        dfnR[x] = time_tag;
    }
    void heavy_light_decomposite() {
        // reset dfn
        int time_tag = 0;
        hld_dfs(Root, time_tag);
    }
    int unweighted_dis(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    len_type weighted_dis(int u, int v) {
        return dis_to_root[u] + dis_to_root[v] - 2 * dis_to_root[lca(u, v)];
    }
};

struct BCCGraph {
    int N;
    vector<vector<int> > e;
    vector<int> stk;
    vector<int> in_stack;
    vector<int> dfn, low, bcc_id;
    int num_bcc;
    BCCGraph(){}
    BCCGraph(int _N) : N(_N) {
        e.assign(N + 1, vector<int>());
        in_stack.assign(N + 1, 0);
        stk.assign(N + 1, 0);
        dfn.assign(N + 1, 0);
        low.assign(N + 1, 0);
        bcc_id.assign(N + 1, 0);
    }

    void add_edge(int u, int v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }

    void tarjan(int x, int from, int &time_tag, RootedTree &T) {
        time_tag++;
        dfn[x] = low[x] = time_tag;
        for (auto &t : e[x]) {
            if (t == from) continue;
            if (!dfn[t]) {
                T.add_edge(x, t);
                tarjan(t, x, time_tag, T);
                low[x] = min(low[x], low[t]);
            } else {
                low[x] = min(low[x], dfn[t]);
            }
        }
    }

    void solve(RootedTree &T) {
        int time_tag = 0;
        for (int i = 1; i <= N; i++) {
            if (!dfn[i]) {
                tarjan(i, -1, time_tag, T);
            }
        }
    }
};

int dsu[200010];
int find(int x) {
    return x == dsu[x] ? x : dsu[x] = find(dsu[x]);
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    while(Cases--) {
        scanf("%d%d",&n,&m);
        scanf("%s",col + 1);
        vector<pii> fuck;
        RootedTree T(n);
        BCCGraph G(n);
        for (int i = 1; i <= n; i++) {
            dsu[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            u++;v++;
            if (col[u] == col[v]) {
                fuck.push_back(pii(u, v));
            } else {
                dsu[find(u)] = find(v);
                G.add_edge(u, v);
            }
        }
        G.solve(T);
        T.init(true);
        bool ans = false;
        for (auto &t : fuck) {
            int u = t.first, v = t.second;
            int du = find(u), dv = find(v), d1 = find(1);
            if (du != d1 || dv != d1) continue;
            int LCA = T.lca(u, v);
            if (u == LCA || v == LCA) {
                ans = true;
                break;
            }
            if (G.low[u] < G.dfn[LCA] || G.low[v] < G.dfn[LCA]) {
                ans = true;
                break;
            }
        }
        puts(ans ? "yes" : "no");
    }
}