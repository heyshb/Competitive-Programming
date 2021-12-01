#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    vector<int> fa(n), sz(n);
    for (int i = 0; i < n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    function<int(int)> find;
    find = [&](int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };
    int con = n;
    int mx = 1;
    auto merge = [&](int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            fa[v] = u;
            sz[u] += sz[v];
            con--;
            mx = max(mx, sz[u]);
        }
    };
    for (int e = 1; e <= m; e++) {
        int u, v;
        scanf("%d%d",&u,&v);
        --u;--v;
        merge(u, v);
        vector<int> s;
        for (int i = 0; i < n; i++) {
            if (i == find(i)) {
                s.push_back(sz[i]);
            }
        }
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        //printf("%d %d\n",mx,con);
        int extra = e - (n - con);
        int ans = s[0] - 1;
        //printf("extra = %d\n",extra);
        for (int i = 1; i <= extra && i <= s.size(); i++) {
            ans += s[i];
        }
        printf("%d\n",ans);
    }
}