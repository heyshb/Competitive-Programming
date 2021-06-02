#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
struct edge {
    int L, R;
    int v;
}e[300010];
bool cmp(edge e1, edge e2) {
    return e1.v > e2.v;
}

int N, M;
int fa[300010],sz[300010];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

LL merge(int x,int y) {
    x = find(x);
    y = find(y);
    LL ret = 1LL * sz[x] * sz[y];
    sz[x] += sz[y];
    fa[y] = x;
    
    //printf("merge %d %d = %lld\n",x,y,ret);
    return ret;
}

LL C(LL x) {
    return x * (x - 1) / 2;
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        scanf("%d%d%d",&e[i].L, &e[i].R, &e[i].v);
    }
    sort(e+1, e+M+1, cmp);
    for (int i=1;i<=N;i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    int L = 1, R;
    bool ok = true;
    LL ans = 0;
    while(L <= M) {
        R = L;
        while(R + 1 <= M && e[R + 1].v == e[L].v) R++;
        for (int i=L;i<=R;i++) {
            if (find(e[i].L) == find(e[i].R)) ok = false;
        }
        for (int i=L;i<=R;i++) {
            if (find(e[i].L) != find(e[i].R)) {
                LL fuck = merge(e[i].L, e[i].R);
                ans += fuck * e[i].v;
                //printf("%lld %lld %lld\n",fuck,e[i].v,ans);
            }
        }
        L = R + 1;
    }
    ans += C(N);
    for (int i=1;i<=N;i++) {
        if (i == find(i)) {
            ans -= C(sz[i]);
        }
    }
    if (!ok) {
        puts("-1");
    } else {
        printf("%lld\n",ans);
    }
}