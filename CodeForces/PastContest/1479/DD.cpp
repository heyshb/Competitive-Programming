#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 600010;
int N, Q;
int col[MAXN];
vector<int>e[MAXN];
struct Query {
    int l, r, z, id;
    int ql, qr;
}q[MAXN];

int dep[MAXN], st[MAXN], en[MAXN], loc[MAXN];
int blk[MAXN];
int S[MAXN], lft[MAXN], rgt[MAXN];
int tmc = 0;
int ans[MAXN];
const int D = 20;
int anc[MAXN][D];
void dfs(int x) {
    st[x] = ++tmc;
    loc[tmc] = x;
    for (int i=1;i<D;i++) anc[x][i] = anc[anc[x][i-1]][i-1];
    for (auto t:e[x]) {
        if (t != anc[x][0]) {
            dep[t] = dep[x] + 1;
            anc[t][0] = x;
            dfs(t);
        }
    }
    en[x] = ++tmc;
    loc[tmc] = x;
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i=D-1;i>=0;i--) {
        if (dep[anc[x][i]] >= dep[y]) {
            x = anc[x][i];
        }
    }
    if (x == y) return x;
    for (int i=D-1;i>=0;i--) {
        if (anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0]; 
}

int MM;
int val[MAXN];
int bsum[MAXN];
int blk2[MAXN];

void flip(int node) {
    int c = col[node];
    if (val[c] == 0) {
        val[c] = 1;
        bsum[blk2[c]]++;
    } else {
        val[c] = 0;
        bsum[blk2[c]]--;
    }
}

typedef pair<int,int> pii;

int getans(int ql,int qr) {
    int b1 = blk2[ql], b2 = blk2[qr];
    if (b1 == b2) {
        for (int i=ql;i<=qr;i++) {
            if (val[i]) return i;
        }
        return -1;
    }
    for (int i=b1+1;i<=b2-1;i++) {
        if (bsum[i] > 0) {
            for (int j=lft[i];j<=rgt[i];j++) {
                if (val[j]) return j;
            }
            assert(false);
        }
    }
    for (int i=ql;i<=rgt[b1];i++) if (val[i]) return i;
    for (int i=lft[b2];i<=qr;i++) if (val[i]) return i;
    return -1;
}


int main() {
    scanf("%d%d",&N,&Q);
    MM = 1;
    while(MM < N) MM <<= 1;
    for (int i=1;i<=N;i++) scanf("%d",&col[i]);
    for (int i=1;i<N;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1);
    int BB = int(int(sqrt(N * 2))) + 1;
    for (int i=1;i<=N*2;i++) {
        blk[i] = (i - 1) / BB + 1;
    }
    int BB2 = int(sqrt(N)) + 1;
    for (int i=1;i<=N;i++) {
        blk2[i] = (i - 1) / BB2 + 1;
        if (!lft[blk2[i]]) lft[blk2[i]] = i;
        rgt[blk2[i]] = i;
    }
    for (int i=1;i<=Q;i++) {
        int p1, p2, L, R;
        scanf("%d%d%d%d",&p1,&p2,&q[i].ql,&q[i].qr);
        if (st[p1] > st[p2]) swap(p1, p2);
        q[i].id = i;
        int LCA = lca(p1, p2);
        if (LCA == p1) {
            q[i].l = st[p1];
            q[i].r = st[p2];
            q[i].z = 0;
        } else {
            q[i].l = en[p1];
            q[i].r = st[p2];
            q[i].z = LCA;
        }
        //assert(q[i].l >= 1 && q[i].l <= 2*N && q[i].r >= 1 && q[i].r <= 2 * N);
    }
    sort(q+1, q+Q+1, [&](Query q1, Query q2) {
        if (blk[q1.l] == blk[q2.l]) {
            return q1.r < q2.r;
        }
        return blk[q1.l] < blk[q2.l];
    });
    int l, r;
    l = 1;
    r = 0;
    for (int _=1;_<=Q;_++) {
        while(l > q[_].l) flip(loc[--l]);
        while(r < q[_].r) flip(loc[++r]);
        while(l < q[_].l) flip(loc[l++]);
        while(r > q[_].r) flip(loc[r--]);
        if (q[_].z) flip(q[_].z);
        /*
        printf("solve %d\n",q[_].id);
        if (q[_].id==1)
        for (int i=1;i<2*MM;i++) {
            printf("T[%d]=%d\n",i,T[i]);
        }
        */
        ans[q[_].id] = getans(q[_].ql, q[_].qr);
        if (q[_].z) flip(q[_].z);
    }
    for (int i=1;i<=Q;i++) {
        printf("%d\n",ans[i]);
    }
}