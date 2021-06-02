#include <bits/stdc++.h>

using namespace std;

int cost[4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char name[5] = "ULDR";
int x[110][110], y[110][110];
int N;
bool in_circle[110][110];
int pid[110][110];
int target[110][110];
int treeid[110][110];
char ans[110][110];
int mcmfid[110][110];

class Directed_MST_Solver {
public:
    static const int MAXN = 2e7 + 10;
    static const int MAXM = 2e7 + 10;
    static const int INF = 1e9;
    int used_MST[MAXM];
    int in[MAXN];
    int pre[MAXN];
    int choosen_id[MAXN];
    int add_edge[MAXN];
    int delete_edge[MAXN];
    int vis[MAXN];
    int index[MAXN];
    struct Edge {
        int u, v, w, id;
        int sx, sy, sdir;
    }E[MAXM];

    void clear(int num_V, int num_E) {
        for (int i=1;i<=num_E;i++) {
            used_MST[i] = 0;
        }
        for (int i=1;i<=num_V;i++) {
            in[i] = 0;
            pre[i] = 0;
            choosen_id[i] = 0;
        }
    }

    int Solve(int root, int num_V, int num_E) {
        //printf("solve %d %d %d\n",root,num_V,num_E);
        clear(num_V, num_E);
        int res = 0;
        int E_id = num_E;
        while(true) {
            int cnt = 0;
            for (int i=1;i<=num_V;i++) {
                in[i] = INF;
            }
            for (int i=1;i<=num_E;i++) {
                int u = E[i].u;
                int v = E[i].v;
                int w = E[i].w;
                if (v != u && in[v] > w) {
                    in[v] = w;
                    pre[v] = u;
                    choosen_id[v] = E[i].id;
                }
            }
            for (int i=1;i<=num_V;i++) {
                if (i == root) continue;
                if (in[i] == INF) return -1;
                //printf("%d %d %d %d\n",i,in[i],pre[i],choosen_id[i]);
            }

            /*
            memset(vis, -1, sizeof(vis));
            memset(index, -1, sizeof(index));
            */
            for (int i=1;i<=num_V;i++) {
                vis[i] = -1;
                index[i] = -1;
            }
            in[root] = 0;

            for (int i=1;i<=num_V;i++) {
                res += in[i];
                if (i != root) {
                    used_MST[choosen_id[i]]++;
                }
                int v = i;
                while(vis[v] != i && v != root && index[i] == -1) {
                    vis[v] = i;
                    v = pre[v];
                }
                if (v != root && index[v] == -1) {
                    ++cnt;
                    for (int u=pre[v];u!=v;u=pre[u]) {
                        index[u] = cnt;
                    }
                    index[v] = cnt;
                }
            }
            if (cnt == 0) break;
            for (int i=1;i<=num_V;i++) {
                if (index[i] == -1) {
                    index[i] = ++cnt;
                }
            }
            
            /*
            for (int i=1;i<=num_V;i++) {
                printf("index %d = %d\n",i,index[i]);   
            }
            */
            for (int i=1;i<=num_E;i++) {
                int u = E[i].u;
                int v = E[i].v;
                E[i].u = index[u];
                E[i].v = index[v];
                if (index[u] != index[v]) {
                    E[i].w -= in[v];
                    delete_edge[++E_id] = choosen_id[v];
                    add_edge[E_id] = E[i].id;
                    E[i].id = E_id;
                }
            }
            num_V = cnt;
            root = index[root];
        }
        //printf("EID = %d\n",E_id);
        for (int i=E_id;i>num_E;i--) {
            if (used_MST[i]) {
                used_MST[delete_edge[i]]--;
                used_MST[add_edge[i]]++;
            }
        }
        for (int i=1;i<=num_E;i++) {
            if (used_MST[i]) {
                int sx = E[i].sx, sy = E[i].sy, sd = E[i].sdir;
                //printf("ans %d %d = %c\n",sx,sy,name[sd]);
                ans[sx][sy] = name[sd];
            }
        }
        return res;
    }
}DMS;

class MCMF_Solver {
public:
    static const int MAXN = 100010;
    static const int MAXM = 1000010 * 2;
    static const int INF = 1e9;
    int S, T;
    int MM;
    int head[MAXN], en[MAXM], nxt[MAXM], f[MAXM], c[MAXM], st[MAXM];
    int x[MAXM], y[MAXM], dir[MAXM];
    int frome[MAXN];
    int inq[MAXN];
    int d[MAXN];
    void addedge(int u, int v, int flow, int cost, int sx, int sy, int sdir) {
        //printf("%d--->%d %d,%d\n",u,v-12,flow,cost);
        MM++;
        st[MM] = u; en[MM] = v; nxt[MM] = head[u]; head[u] = MM; f[MM] = flow; c[MM] = cost; 
        x[MM] = sx; y[MM] = sy; dir[MM] = sdir;
        MM++;
        st[MM] = v; en[MM] = u; nxt[MM] = head[v]; head[v] = MM; f[MM] = 0; c[MM] = -cost; 
    }
    void init(int NodeCnt) {
        MM = 1;
        S = NodeCnt + 1;
        T = NodeCnt + 2;
        for (int i=1;i<=T;i++) head[i] = 0;
    }
    bool spfa() {
        queue<int>q;
        for (int i=1;i<=T;i++) {
            inq[i] = false;
            d[i] = INF;
        }
        d[S] = 0;
        q.push(S);
        inq[S] = true;
        while(!q.empty()) {
            int now = q.front();
            for (int i=head[now];i;i=nxt[i]) {
                if (f[i] && d[now] + c[i] < d[en[i]]) {
                    d[en[i]] = d[now] + c[i];
                    frome[en[i]] = i;
                    if (!inq[en[i]]) {
                        inq[en[i]] = true;
                        q.push(en[i]);
                    }
                }
            }
            q.pop();
            inq[now] = false;
        }
        return d[T] < INF;
    }
    int Solve(int target_max_flow) {
        int ret = 0;
        int max_flow = 0;
        while(spfa()) {
            int fl = INF;
            int ct = 0;
            for (int i=T;i!=S;i=st[frome[i]]) {
                fl = min(fl, f[frome[i]]);
                ct += c[frome[i]];
            }
            for (int i=T;i!=S;i=st[frome[i]]) {
                f[frome[i]] -= fl;
                f[frome[i] ^ 1] += fl;
            }
            ret += fl * ct;
            max_flow += fl;
        }
        if (target_max_flow != max_flow) {
            return -1;
        }
        return ret;
    }
    void FillAns(int n) {
        for (int i=1;i<=n;i++) {
            for (int j=head[i];j;j=nxt[j]) {
                if (!f[j] && en[j] > n && en[j] <= 2 * n) {
                    ans[x[j]][y[j]] = name[dir[j]];
                }
            }
        }
    }
}MCMF;

int main() {
    scanf("%d",&N);
    for (int i=0;i<4;i++) {
        scanf("%d",&cost[i]);
    }
    
    /*
    N = 50;
    cost[0] = 2;cost[1] = 1;cost[2] = 1;cost[3] = 1;
    */
    
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            pid[i][j] = (i - 1) * N + j;
        }
    }
    int in_circle_cnt = 0;
    int min_cost = 0;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d%d",&x[i][j],&y[i][j]);
            //x[i][j] = i; y[i][j] = j;
            //if (i == 1 && j == 2) {x[i][j] = 1; y[i][j] = 2;}else {x[i][j] = y[i][j] = 1;}
            in_circle[i][j] = (i == x[i][j] && j == y[i][j]);
            if (in_circle[i][j]) {
                in_circle_cnt++;
                mcmfid[i][j] = in_circle_cnt;
            }
            target[i][j] = pid[x[i][j]][y[i][j]];
        }
    }
    MCMF.init(2 * in_circle_cnt);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (in_circle[i][j]) {
                MCMF.addedge(MCMF.S, mcmfid[i][j], 1, 0, 0, 0, 0);
                MCMF.addedge(mcmfid[i][j] + in_circle_cnt, MCMF.T, 1, 0, 0, 0, 0);
                for (int dir=0;dir<4;dir++) {
                    int ni = i + dx[dir], nj = j + dy[dir];
                    if (in_circle[ni][nj]) {
                        MCMF.addedge(mcmfid[i][j], mcmfid[ni][nj] + in_circle_cnt, 1, cost[dir], i, j, dir);
                    }
                }
                int val = pid[i][j];
                int EdgeCnt = 0;
                int VertexCnt = 0;
                int RootNode = -1;
                for (int k=1;k<=N;k++) {
                    for (int l=1;l<=N;l++) {
                        if (target[k][l] == val) {
                            treeid[k][l] = ++VertexCnt;
                            if (k == i && j == l) RootNode = VertexCnt;
                        }
                    }
                }
                if (VertexCnt == 1) continue;
                for (int k=1;k<=N;k++) {
                    for (int l=1;l<=N;l++) {
                        if (target[k][l] == val) {
                            for (int dir = 0; dir < 4; dir++) {
                                int ni = k + dx[dir], nj = l + dy[dir];
                                if (target[ni][nj] == val) {
                                    int v1 = treeid[k][l], v2 = treeid[ni][nj];
                                    EdgeCnt++;
                                    DMS.E[EdgeCnt] = (Directed_MST_Solver::Edge){v2, v1, cost[dir], EdgeCnt, k, l, dir};
                                }
                            }
                        }
                    }
                }
                int dms_ret = DMS.Solve(RootNode, VertexCnt, EdgeCnt);
                if (dms_ret == -1) {
                    puts("-1");
                    return 0;
                } else {
                    min_cost += dms_ret;
                }
            }
        }
    }
    int mcmf_ret = MCMF.Solve(in_circle_cnt);
    if (mcmf_ret == -1) {
        puts("-1");
        return 0;
    }
    min_cost += mcmf_ret;
    MCMF.FillAns(in_circle_cnt);

    printf("%d\n",min_cost);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) printf("%c",ans[i][j]);
        puts("");
    }
    return 0;
}