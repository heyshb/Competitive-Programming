#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
vector<int> e[200010];
int fa[200010];
int d[200010];
const int D = 20;
int anc[200100][D];

int ans[200010];
bool vis[200010];
vector<int> dfn;

int fuck(int x) {
    //printf("fuck %d\n",x);
    queue<int>q;
    for (int i = 1; i <= N; i++) {
        fa[i] = 0;
        vis[i] = false;
    }
    q.push(x);
    d[x] = 0;
    vis[x] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        anc[now][0] = fa[now];
        for (int i = 1; i < D; i++) {
            anc[now][i] = anc[anc[now][i - 1]][i - 1];
        }
        for (auto &t : e[now]) {
            if (vis[t]) continue;
            d[t] = d[now] + 1;
            fa[t] = now;
            vis[t] = true;
            q.push(t);
        }
    }
    int max_dist = -1, max_point = -1;
    for (int i = 1; i <= N; i++) {
        if (d[i] > max_dist) {
            max_dist = d[i];
            max_point = i;
        }
    }
    return max_point;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int delta = (d[u] - d[v]);
    for (int i = D - 1; i >= 0; i--) if ((delta >> i) & 1) u = anc[u][i];
    if (u == v) return u;
    for (int i = D - 1; i >= 0; i--) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
    return anc[u][0];
}

int dis(int u, int v) {
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

void dfs(int x) {
    //printf("dfs %d %d\n",x,fa[x]);
    vis[x] = true;
    dfn.push_back(x);
    for (auto &t : e[x]) {
        if (!vis[t] && t != fa[x]) {
            dfs(t);
        }
    }
    if (!vis[fa[x]]) dfs(fa[x]);
}

int main() {
    scanf("%d",&N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int p1 = fuck(1);
    int p2 = fuck(p1);
    //printf("dia %d %d\n",p1,p2);
    for (int i = 1; i <= N; i++) {
        vis[i] = false;
    }
    ans[p2] = 1;
    dfs(p2);
    ans[dfn[0]] = 1;
    for (int i = 0; i < N; i++) {
        //printf("dfn %d %d\n",i,dfn[i]);
    }
    for (int i = 1; i <= N; i++) {
        //for (int j = 0 ; j <= 1; j++) printf("anc %d %d = %d\n",i,j,anc[i][j]);
    }
    for (int i = 1; i < N; i++) {
        //printf("dis %d %d = %d\n",dfn[i - 1], dfn[i], dis(dfn[i - 1], dfn[i]));
        ans[dfn[i]] = ans[dfn[i - 1]] + dis(dfn[i - 1], dfn[i]);
    }
    for (int i = 1; i <= N; i++) {
        printf("%d%c",ans[i]," \n"[i==N]);
    }
}