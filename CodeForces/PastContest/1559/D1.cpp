#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m1, m2;
struct uno {
    vector<int> fa;
    uno(){}
    uno(int _n) {
        fa.resize(_n + 1);
        for (int i = 1; i <= _n; i++) fa[i] = i;
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool con(int u, int v) {
        return find(u) == find(v);
    }
    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        fa[u] = v;
        return true;
    }
};

int main() {
    scanf("%d%d%d",&n,&m1,&m2);
    uno u1(n), u2(n);
    for (int i = 1; i <= m1; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        u1.merge(u, v);
    }
    for (int i = 1; i <= m2; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        u2.merge(u, v);
    }
    vector<pii> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!u1.con(i, j) && !u2.con(i, j)) {
                u1.merge(i, j);
                u2.merge(i, j);
                ans.emplace_back(i, j);
            }
        }
    }
    printf("%d\n",ans.size());
    for (auto &t : ans) printf("%d %d\n",t.first,t.second);
}