#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N, M, K;
vector<pii>e[200010];
bool ok[10][10][10][10];
int in[200010][10][10];
int c[10];
int ans = 0;

bool check() {
    for (int i=1;i<=K;i++) {
        for (int j=1;j<=K;j++) {
            if (!ok[i][c[i]][j][c[j]]) return false;
        }
    }
    return true;
}

void dfs(int dep) {
    if (dep == K + 1) {
        if (check()) ans++;
        return;
    }
    for (int i=1;i<=dep;i++) {
        c[dep] = i;
        dfs(dep + 1);
    }
}

int main() {
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1;i<=K;i++) c[i] = i;
    for (int i=1;i<=M;i++) {
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(pii(w, v));
    }
    for (int i=1;i<=N;i++) {
        sort(e[i].begin(), e[i].end());
    }
    memset(ok, true, sizeof(ok));
    for (int i=1;i<=N;i++) {
        int D = e[i].size();
        for (int j=0;j<D;j++) {
            int idx = j + 1, to = e[i][j].second;
            if (++in[to][D][idx] > 1) {
                ok[D][idx][D][idx] = false;
            }
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j1=1;j1<=K;j1++) {
            for (int k1=1;k1<=j1;k1++) {
                if (in[i][j1][k1]) {
                    for (int j2=1;j2<=K;j2++) {
                        for (int k2=1;k2<=j2;k2++) {
                            if (j1 == j2 && k1 == k2) continue;
                            if (in[i][j2][k2]) {
                                ok[j1][k1][j2][k2] = false;
                            }
                        }
                    }
                }
            }
        }
    }
    dfs(1);
    printf("%d\n",ans);
}