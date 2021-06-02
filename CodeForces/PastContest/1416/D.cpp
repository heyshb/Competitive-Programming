#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int op[1000010][2];
bool del[1000010];
int L[1000010],R[1000010];
vector<int>e[1000010];
int N,M,Q;
int p[1000010];
int fa[1000010];
int treenode[1000010];
int NN;
int ttm[1000010];
const int INF = 1e9;
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void addedge(int x,int y) {
    e[x].push_back(y);
    e[y].push_back(x);
}
void merge(int x,int y,int t = INF) {
    //printf("merge %d %d %d\n",x,y,t);
    if (find(x) == find(y)) return;
    int tx = treenode[find(x)];
    int ty = treenode[find(y)];
    
    fa[find(x)] = find(y);
    ttm[++NN] = t;
    addedge(NN, tx);
    addedge(NN, ty);
    treenode[find(y)] = NN;
}
bool vis[1000010];
int anc[1000010][20];
int sL[1000010], sR[1000010];
int pos[1000100],ttmc = 0,dfn[1000010];
void dfs0(int x) {
    for (int i=1;i<20;i++) {
        anc[x][i] = anc[anc[x][i-1]][i-1];
    }
    vis[x] = true;
    dfn[++ttmc] = x;
    pos[x] = ttmc;
    sL[x] = ttmc;
    for (auto t:e[x]) {
        if (!vis[t]) {
            anc[t][0] = x;
            dfs0(t);
        }
    }
    sR[x] = ttmc;
}

int md[4000010];
void maintain(int x) {
    if (p[md[x*2]] > p[md[x*2+1]]) {
        md[x] = md[x*2];
    } else {
        md[x] = md[x*2+1];
    }
}
void build(int x,int L,int R) {
    if (L == R) {
        md[x] = dfn[L];
        return;
    }
    int mid = (L + R) / 2;
    build(x * 2, L, mid);
    build(x * 2 + 1, mid + 1, R);
    maintain(x);
}

int findmax(int x,int L,int R,int ql,int qr) {
    if (L == ql && R == qr) {
        return md[x];
    }
    int mid = (L + R) / 2;
    if (qr <= mid) return findmax(x*2,L,mid,ql,qr);
    if (ql > mid) return findmax(x*2+1,mid+1,R,ql,qr);
    int r1 = findmax(x*2,L,mid,ql,mid);
    int r2 = findmax(x*2+1,mid+1,R,mid+1,qr);
    if (p[r1] > p[r2]) return r1;
    else return r2;
}

void modify(int x,int L,int R,int pos) {
    if (L == R) return;
    int mid = (L + R) / 2;
    if (pos <= mid) modify(x*2,L,mid,pos);
    else modify(x*2+1,mid+1,R,pos);
    maintain(x);
}

int fuck_subtree(int x) {
    int id = findmax(1,1,NN,sL[x],sR[x]);
    int ret = p[id];
    p[id] = 0;
    modify(1,1,NN,pos[id]);
    return ret;
}

int main() {
    scanf("%d%d%d",&N,&M,&Q);
    NN = N;
    for (int i=1;i<=N;i++) {
        scanf("%d",&p[i]);
    }
    for (int i=1;i<=M;i++) {
        scanf("%d%d",&L[i],&R[i]);
        del[i] = false;
    }
    for (int i=1;i<=Q;i++) {
        scanf("%d%d",&op[i][0],&op[i][1]);
        if (op[i][0] == 2) del[op[i][1]] = true;
    }
    for (int i=1;i<=N;i++) {
        treenode[i] = i;
        fa[i] = i;
        ttm[i] = INF;
    }
    NN = N;
    for (int i=1;i<=M;i++) {
        if (!del[i]) {
            merge(L[i], R[i]);
        }
    }
    for (int i=Q;i>=1;i--) {
        if (op[i][0] == 2) {
            int id = op[i][1];
            merge(L[id], R[id], i);
        }
    }
    for (int i=1;i<=N;i++) {
        if (!vis[treenode[find(i)]]) {
            dfs0(treenode[find(i)]);
        }
    }
    build(1,1,NN);
    for (int i=1;i<=Q;i++) {
        if (op[i][0] == 1) {
            int v = op[i][1];
            for (int j=19;j>=0;j--) {
                if (ttm[anc[v][j]] > i) v = anc[v][j];
            }
            printf("%d\n",fuck_subtree(v));
        }
    }
}