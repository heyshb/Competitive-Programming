#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
const int MAXN = 200010;
const int D = 20;
int anc[MAXN][D], dep[MAXN];
int sz[MAXN];
LL ans[MAXN];
vector<int> e[MAXN];
int n;
int time_tag;
int dfnL[MAXN], dfnR[MAXN];
 
void dfs0(int x, int fa) {
    dfnL[x] = ++time_tag;
    anc[x][0] = fa;
    for (int i = 1; i < D; i++) {
        anc[x][i] = anc[anc[x][i - 1]][i - 1];
    }
    sz[x] = 1;
    for (auto &t : e[x]) {
        if (t != fa) {
            dep[t] = dep[x] + 1;
            dfs0(t, x);
            sz[x] += sz[t];
        }
    }
    dfnR[x] = time_tag;
}
 
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int delta = dep[u] - dep[v];
    for (int i = D - 1; i >= 0; i--) {
        if (delta & (1 << i)) u = anc[u][i];
    }
    if (u == v) return u;
    for (int i = D - 1; i >= 0; i--) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}
 
int get_anc(int u, int delta) {
    for (int i = D - 1; i >= 0; i--) {
        if (delta & (1 << i)) u = anc[u][i];
    }
    return u;
}
 
int L, R;
 
bool add(int u) {
    if (L == R) {
        L = u;
        return true;
    }
    if (dep[L] < dep[R]) swap(L, R);
    int LCA = lca(L, R);
    int t = dfnL[u];
    if (t >= dfnL[L] && t <= dfnR[L]) {
        L = u;
        return true;
    }
    if (R == LCA) {
        if (t < dfnL[R] || t > dfnR[R]) {
            R = u;
            return true;
        }
        int g = lca(u, L);
        if (g == R) {
            R = u;
            return true;
        }
        return false;
    } else {
        if (t >= dfnL[R] && t <= dfnR[R]) {
            R = u;
            return true;
        }
        return false;
    }
}
 
typedef pair<int,int> pii;
 
pii get_sizes() {
    if (dep[L] < dep[R]) swap(L, R);
    int LCA = lca(L, R);
    int s1 = sz[L], s2;
    if (R == LCA) {
        int fuck = dep[L] - dep[R] - 1;
        fuck = get_anc(L, fuck);
        s2 = n - sz[fuck];
    } else {
        s2 = sz[R];
    }
    return pii(s1, s2);
}
 
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        time_tag = 0;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            e[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            u++;v++;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dep[1] = 1;
        dfs0(1, 0);
        for (int i = 0; i <= n; i++) ans[i] = 0;
        ans[0] = 1LL * n * (n - 1) / 2;
        ans[1] = 0;
        for (auto &t : e[1]) {
            ans[1] += 1LL * sz[t] * (n - sz[t] - 1);
        }
        ans[1] /= 2;
        ans[1] += n - 1;
        L = R = 1;
        for (int i = 2; i <= n; i++) {
            //printf("i = %d\n",i);
            if (!add(i)) break;
            //printf("%d %d\n",L,R);
            pii fuck = get_sizes();
            //printf("%d %d\n",fuck.first,fuck.second);
            ans[i] = 1LL * fuck.first * fuck.second;
        }
        ans[n + 1] = 0;
        for (int i = 0; i <= n; i++) {
            printf("%lld%c",ans[i] - ans[i + 1], " \n"[i==n]);
        }
    }
}
