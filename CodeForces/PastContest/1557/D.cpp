#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n, m, M;
vector<pii> seg[300010];
pii mi[3200010], tag[3200010];
const int INF = 1e9 + 10;
#define mid (((L) + (R)) / 2)

void upd(int x) {
    mi[x] = min(mi[x * 2], mi[x * 2 + 1]);
    mi[x] = min(mi[x],tag[x]);
}

pii get_min(int x, int L, int R, int ql, int qr) {
    if (L == ql && R == qr) {
        return mi[x];
    }
    if (qr <= mid) return min(tag[x],get_min(x * 2, L, mid, ql, qr));
    else if (ql > mid) return min(tag[x],get_min(x * 2 + 1, mid + 1, R, ql, qr));
    else return min(tag[x],min(get_min(x * 2, L, mid, ql, mid), get_min(x * 2 + 1, mid + 1, R, mid + 1, qr)));
}

void modify(int x, int L, int R, int ql, int qr, pii val) {
    printf("modify %d %d %d %d\n",L,R,ql,qr);
    if (qr < L || ql > R) return;
	if (ql <= L && R <= qr) {
        mi[x] = tag[x] = val;
        return;
    }
    modify(x * 2, L, mid, ql, qr, val);
    modify(x * 2 + 1, mid + 1, R,ql,qr,val);
    upd(x);
}

int from[300010];

bool vis[300010];

int main() {
    scanf("%d%d",&n,&m);
    vector<int> val;
    for (int i = 1; i <= m; i++) {
        int u, l, r;
        scanf("%d%d%d",&u,&l,&r);
        seg[u].emplace_back(l, r);
        val.push_back(l);
        val.push_back(r);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    M = val.size();
    //assert(M <= 2 * n);
    for (int i = 1; i <= n; i++) {
        for (auto &t : seg[i]) {
            t.first = lower_bound(val.begin(), val.end(), t.first) - val.begin() + 1;
            t.second = lower_bound(val.begin(), val.end(), t.second) - val.begin() + 1;
            //printf("%d %d %d\n",i,t.first,t.second);
        }
    }
    for (int i = 1; i <= 4 * M; i++) {
        mi[i] = pii(INF, -1);
        tag[i] = pii(INF, -1);
    }
    int ans = INF;
    int best_fuck = 0;
    for (int i = 1; i <= n; i++) {
        if (seg[i].empty()) {
            continue;
        }
        pii best(0, 0);
        int best_val = 0, best_from = 0;
        for (auto &t : seg[i]) {
            int u = t.first;
            int v = t.second;
            auto tmp = get_min(1, 1, M, u, v);
            printf("get(%d,%d) = (%d,%d)\n",u,v,tmp.first,tmp.second);
            best = min(best, tmp);
        }
        int dp = i - 1 + best.first;
        printf("dp[%d]=%d\n",i,dp);
        from[i] = best.second;
        for (auto &t : seg[i]) {
            int u = t.first;
            int v = t.second;
            printf("upd %d %d %d %d\n",u,v,dp-i,i);
            modify(1, 1, M, u, v, pii(dp - i, i));
        }
        if (dp + n - i < ans) {
            ans = dp + n - i;
            best_fuck = i;
        }
    }
    printf("%d\n",ans);
    vector<int> p;
    for (int i = best_fuck; i; i = from[i]) {
        vis[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) printf("%d ",i);
    }
}