#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, k;
int d[51];
int w[51][51], nd[51];
struct edge {
    int u, v, w;
};
int fa[51];
int find(int x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int W = 0;
set<pii> now_edges;
void con(int u, int v) {
    u = find(u);
    v = find(v);
    fa[u] = v;
    nd[u]++; nd[v]++;
    W += w[u][v];
    now_edges.emplace(u, v);
}
int ans;

vector<int>ee;
pii mi[51][51];
void adjust() {
    for (int i = 1; i <= n; i++) {
        ee[i].clear();
    }
    for (auto &t : now_edges) {
        ee[t.u].push_back(t.v);
        ee[t.v].push_back(t.u);
    }
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= k; i++) {
        scanf("%d",&d[i]);
    }
    vector<edge> e;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            scanf("%d",&w[i][j]);
            w[j][i] = w[i][j];
            if (i > k) e.push_back((edge){i, j, w[i][j]});
        }
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (auto &t : e) {
        if (find(t.u) == find(t.v)) continue;
        con(t.u, t.v);
    }
    for (int i = 1; i <= k; i++) {
        int mi = 1e9, pos = -1;
        for (int j = k + 1; j <= n; j++) {
            if (w[i][j] < mi) {
                mi = w[i][j];
                pos = j;
            }
        }
        con(i, pos);
    }
    ans = W;
    for (int rep = 1; rep <= 10000; rep++) {
        adjust();
    }
    printf("%d\n",ans);
}