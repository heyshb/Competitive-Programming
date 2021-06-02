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
int T[4 * MAXN];

void flip(int node) {
    //printf("flip %d\n",node);
    int c = col[node];
    int down = c+MM-1;
    T[down] ^= 1;
    for (int i=down/2;i;i/=2) {
        T[i] = T[i*2] + T[i*2+1];
    }
}

typedef pair<int,int> pii;

int getpos(int x,int L,int R,int ql,int qr) {
    //printf("getpos %d %d %d %d %d\n",x,L,R,ql,qr);
    if (L == R) {
        if (T[x] != 0) {
            return L;
        } else {
            return -1;
        }
    }
    if (T[x] == 0) {
        return -1;
    }
    int mid = (L + R) / 2;
    if (qr <= mid) return getpos(x*2,L,mid,ql,qr);
    if (ql > mid) return getpos(x*2+1,mid+1,R,ql,qr);
    int tmp = getpos(x*2,L,mid,ql,mid);
    if (tmp != -1) return tmp;
    return getpos(x*2+1,mid+1,R,mid+1,qr);
}

int getans(int ql,int qr) {
    return getpos(1,1,MM,ql,qr);
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
    int BB = int(0.5 * int(sqrt(N * 2))) + 1;
    for (int i=1;i<=N*2;i++) {
        blk[i] = (i - 1) / BB + 1;
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