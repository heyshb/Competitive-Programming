#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
vector<int>e[500010],e2[500010],e3[500010];
int p[500010], q[500010];
int L[500010], R[500010];
int node;
int fa[500010], tag[500010];
vector<int>com;
bool f[500010][3];
int g[500010];

void dfs(int x) {
    for (auto t:e2[x]) {
        dfs(t);
        if (!f[t][1] && !f[t][2] && !f[t][0]) {
            return;
        }
    }
    // 2
    f[x][2] = true;
    f[x][1] = false;
    f[x][0] = false;
    for (auto t:e2[x]) {
        if (!f[t][0] && !f[t][1]) f[x][2] = false;
        if (f[t][2]) f[x][1] = true;
        if (f[t][1]) f[x][0] = true, g[x] = t;
    }
}

void dfs2(int x, int idx) {
    if (idx == 0) {
        e3[g[x]].push_back(x);
        dfs2(g[x], 1);
        for (auto t:e2[x]) {
            if (t != g[x]) {
                dfs2(t, -1)
            }
        }
        return;
    }
    if (idx == 1) {
        for (auto t:e2[x]) {
            if (f[t][])
        }
    }
}

void fuck(int src) {
    queue<int>q;
    q.push(src);
    com.clear();
    com.push_back(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto t:e[u]) {
            tag[t] = u;
        }
        for (int i=R[0];i<=N;i=R[i]) {
            if (i != src && tag[i] != u) {
                q.push(i);
                fa[i] = u;
                e2[u].push_back(i);
                R[L[i]] = R[i];
                L[R[i]] = L[i];
            }
        }
    }
    if (com.size() == 1) return;
    dfs(src);
    for (int i=0;i<3;i++) {
        if (f[src][i]) {
            dfs2(src, i);
            break;
        }
    }
    for (auto t:com) {
        if (e3[t].size()) {
            int MM = e3[t].size();
            p[t] = node + 1;
            q[t] = node + MM + 1;
            for (int i=0;i<MM;i++) {
                p[e3[t][i]] = node + 2 + i;
                q[e3[t][i]] = node + 1 + i;
            }
            node += MM + 1;
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++) {
            e[i].clear();
            e2[i].clear();
            e3[i].clear();
            L[i] = i - 1;
            R[i] = i + 1;
            p[i] = q[i] = 0;
            tag[i] = 0;
            f[i][0] = f[i][1] = f[i][2] = false;
        }
        R[0] = 1;
        L[N + 1] = N;
        for (int i=1;i<=M;i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i=R[0];i<=N;) {
            fuck(i);
            int tmp = R[i];
            R[L[i]] = R[i];
            L[R[i]] = L[i];
            i = tmp;
        }
        node = 0;
        for (int i=1;i<=N;i++) {
            if (!p[i]) {
                p[i] = q[i] = ++node;
            }
        }
        for (int i=1;i<=N;i++) {
            printf("%d%c",p[i]," \n"[i==N]);
        }
        for (int i=1;i<=N;i++) {
            printf("%d%c",q[i]," \n"[i==N]);
        }
    }
}