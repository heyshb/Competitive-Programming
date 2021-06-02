#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
typedef long long LL;
 
struct edge {
    int x, y;
    LL l;
    edge(int x, int y, LL l): x(x), y(y), l(l) {}
};
 
bool operator < (const edge& a, const edge& b) {
    return a.l < b.l;
}
 
const int N = 1111;
vector<edge> e;
vector<int> G[N];
int n;
LL x[N], y[N];
int f[N], vis[N];
 
template<typename T> T sqr(T x) { return x * x; }
 
int fd(int x) { return x == f[x] ? x : f[x]; }
 
void dfs(int x, int f) {
    vis[x] = 1;
    int cnt = 0;
    for(auto v : G[x]) {
        if (v == f || vis[v]) continue;
        printf("%d ", v + 1);
        dfs(v, x);
        printf("%d ", x + 1);
    }
    return;
}
 
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
        f[i] = i;
    }    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            e.push_back(edge(i, j, sqr(x[i] - x[j]) + sqr(y[i] - y[j])));
        }
    }
    sort(e.begin(), e.end());
    for(auto ed : e) {
        int fx = fd(ed.x), fy = fd(ed.y);
        if (fx == fy) continue;
        f[fx] = fy;
        G[ed.x].push_back(ed.y);
        G[ed.y].push_back(ed.x);
    }
 
    printf("%d\n", n * 2 - 1);
    memset(vis, 0, sizeof(vis));
    printf("1 ");
    dfs(0, -1);
    return 0;
}