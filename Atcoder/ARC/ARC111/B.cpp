#include <bits/stdc++.h>

using namespace std;

const int M = 400000;
int N;
int fa[M + 10], ecnt[M + 10], vcnt[M + 10];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    for (int i=1;i<=M;i++) {
        fa[i] = i;
        vcnt[i] = 1;
        ecnt[i] = 0;
    }
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        u = find(u), v = find(v);
        if (u == v) {
            ecnt[u]++;
        } else {
            ecnt[u] += ecnt[v] + 1;
            vcnt[u] += vcnt[v];
            fa[v] = u;
        }
    }
    int ans = 0;
    for (int i=1;i<=M;i++) {
        if (find(i) == i) {
            ans += min(vcnt[i], ecnt[i]);
        }
    }
    printf("%d\n",ans);
}