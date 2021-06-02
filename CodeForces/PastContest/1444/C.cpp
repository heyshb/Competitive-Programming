#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M, K;
int c[500010], sz[500010];
int fa[500010], dd[500010];
set<pii> cant, vis;
map<pii, vector<pii> >edges;
int L[500010], R[500010];
bool ok[500010];

pii find(int x) {
    int d = 0;
    while(x != fa[x]) d ^= dd[x], x = fa[x];
    return pii(x, d);
}

// return -1  not bip
// return 0   connected
// return v > 0   whose fa is modified
int merge(int x,int y) {
    //printf("MERGE %d %d\n",x,y);
    auto p1 = find(x);
    auto p2 = find(y);
    //printf("?? %d %d %d %d\n",p1.first,p1.second,p2.first,p2.second);
    if (p1.first == p2.first) {
        if (p1.second == p2.second) return -1;
        return 0;
    }
    if (sz[p1.first] > sz[p2.first]) swap(p1, p2);
    //printf("fa[%d]=%d\n",p1.first,p2.first);
    fa[p1.first] = p2.first;
    dd[p1.first] = p1.second ^ p2.second ^ 1;
    sz[p2.first] += sz[p1.first];
    return p1.first;
}

int pre_ok[500010];

LL C2(LL x) {
    return x * (x - 1) / 2;
}

int main() {
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1;i<=N;i++) {
        scanf("%d",&c[i]);
        fa[i] = i;
        sz[i] = 1;
        dd[i] = 0;
    }
    for (int i=1;i<=K;i++) {
        ok[i] = true;
    } 
    LL ans = C2(K);
    int not_ok_cnt = 0;
    for (int i=1;i<=M;i++) {
        scanf("%d%d",&L[i],&R[i]);
        if (c[L[i]] == c[R[i]]) {
            if (merge(L[i], R[i]) == -1) {
                ok[c[L[i]]] = false;
            }
        } else {
            int c1 = c[L[i]], c2 = c[R[i]];
            if (c1 > c2) swap(c1, c2);
            edges[pii(c1, c2)].push_back(pii(L[i], R[i]));
        }
    }
    for (int i=1;i<=K;i++) {
        if (!ok[i]) not_ok_cnt++;
    }
    ans -= (1LL * not_ok_cnt * (K - 1) - C2(not_ok_cnt));

    //for (int i=1;i<=N;i++) printf("%d %d\n",i,fa[i]);
    for (auto t:edges) {
        int c1 = t.first.first, c2 = t.first.second;
        //printf("color: %d %d\n",c1,c2);
        if (!ok[c1] || !ok[c2]) continue;
        vector<int> stk;
        bool pair_ok = true;
        // merge
        for (auto e:t.second) {
            int u = e.first, v = e.second;
            int merge_ret = merge(u, v);
            //printf("merge %d %d %d\n",u,v,merge_ret);
            if (merge_ret == -1) pair_ok = false;
            if (merge_ret > 0) {
                stk.push_back(merge_ret);
            }
        }
        // erase
        for (int i=stk.size()-1;i>=0;i--) {
            int u = stk[i];
            assert(fa[u] != u);
            sz[fa[u]] -= sz[u];
            fa[u] = u; 
            dd[u] = 0;
        }
        stk.clear();
        if (!pair_ok) ans--;
    }
    printf("%lld\n",ans);
}