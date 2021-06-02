#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n;
int a[200010];
const int MAX_NODE = 200010 * 31;
const int D = 29;
int ch[MAX_NODE][2];
int sz[MAX_NODE];

int M = 1;
void insert(int val) {
    int now = 1;
    sz[1]++;
    for (int i=D;i>=0;i--) {
        int &nxt = ch[now][(val >> i) & 1];
        if (!nxt) nxt = ++M;
        now = nxt;
        sz[now]++;
    }
}

LL dfs(int u, int v, LL dd) {
    int u0 = ch[u][0], u1 = ch[u][1], v0 = ch[v][0], v1 = ch[v][1];
    if (!u0 && !u1) return dd;
    LL ret = 1e18;
    if (sz[u0]) {
        if (sz[v0]) {
            ret = min(ret, dfs(u0, v0, dd * 2));
        } else {
            ret = min(ret, dfs(u0, v1, dd * 2 + 1));
        }
    }
    if (sz[u1]) {
        if (sz[v1]) {
            ret = min(ret, dfs(u1, v1, dd * 2));
        } else {
            ret = min(ret, dfs(u1, v0, dd * 2 + 1));
        }
    }
    return ret;
}

LL calc(int u, int v) {
    return dfs(u, v, 1);
}

LL solve(int now) {
    if (now == 0 || !sz[now]) return 0;
    int c0 = ch[now][0], c1 = ch[now][1];
    LL ans = 0;
    if (sz[c0] && sz[c1]) ans += calc(c0, c1);
    ans += solve(c0);
    ans += solve(c1);
    return ans;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        insert(a[i]);
    }
    printf("%lld\n",solve(1));
}