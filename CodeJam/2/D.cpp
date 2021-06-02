#include <bits/stdc++.h>

using namespace std;

int R, C, F, S;
char A[110][110], B[110][110];
typedef long long LL;
const int MAXN = 210;
const int MAXM = 1000010;
const int INF = 1e9 + 10;
class CostFlow {
    public:
    int M, S, T;
    bool inq[MAXN];
    int head[MAXN], en[MAXM], nxt[MAXM], f[MAXM], c[MAXM];
    int pre[MAXN], from[MAXN];
    LL d[MAXN];
    void init(int _T) {
        T = _T;
        S = T - 1;
        for (int i = 1; i <= T; i++) {
            head[i] = 0;
        }
        M = 1;
    }
    void addedge(int u, int v, int ff, int cc) {
        //printf("add %d %d %d %d\n",u,v,ff,cc);
        M++;
        en[M] = v; nxt[M] = head[u]; head[u] = M; f[M] = ff; c[M] = cc;
        M++;
        en[M] = u; nxt[M] = head[v]; head[v] = M; f[M] = 0; c[M] = -cc;
    }
    bool spfa() {
        for (int i = 1; i <= T; i++) {
            inq[i] = false;
            d[i] = INF;
        }
        inq[S] = true;
        d[S] = 0;
        queue<int> q;
        q.push(S);
        while(!q.empty()) {
            int now = q.front();
            //printf("now = %d\n",now);
            for (int i = head[now]; i; i = nxt[i]) {
                //printf("%d %d\n",now,en[i]);
                if (f[i] && d[now] + c[i] < d[en[i]]) {
                    d[en[i]] = d[now] + c[i];
                    pre[en[i]] = now;
                    from[en[i]] = i;
                    if (!inq[en[i]]) {
                        inq[en[i]] = true;
                        q.push(en[i]);
                    }
                }
            }
            q.pop();
            inq[now] = false;
        }
        return (d[T] != INF);
    }
    LL flow() {
        LL ret = 0;
        while(spfa()) {
            int fl = 1e9;
            LL ct = 0;
            for (int i = T; i != S; i = pre[i]) {
                fl = min(fl, f[from[i]]);
                ct += c[from[i]];
            }
            ret += ct * fl;
            for (int i = T; i != S; i = pre[i]) {
                f[from[i]] -= fl;
                f[from[i] ^ 1] += fl;
            }
        }
        return ret;
    }
}CF;

int main() {
    int T;
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        scanf("%d%d%d%d",&R,&C,&F,&S);
        for (int i = 1; i <= R; i++) {
            scanf("%s", A[i] + 1);
        }
        for (int i = 1; i <= R; i++) {
            scanf("%s", B[i] + 1);
        }
        CF.init(2 * R * C + 2);
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, -1, 0, 1};
        int SS = 2 * R * C + 1, TT = 2 * R * C + 2;
        //printf("?? %d %d\n",SS,TT);
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                int id = (i - 1) * C + j;
                for (int u = 1; u <= R; u++) {
                    for (int v = 1; v <= C; v++) {
                        int nid = (u - 1) * C + v;
                        int newf = F * (int(A[i][j] != B[u][v]) + (B[i][j] != A[u][v]));
                        CF.addedge(2 * id - 1, 2 * nid, 1, newf + S * (abs(i - u) + abs(v - j)));
                    }
                } 
                CF.addedge(SS, 2 * id - 1, 1, 0);
                CF.addedge(2 * id - 1, 2 * id, 1, 2 * F);
                CF.addedge(2 * id, TT, 1, 0);
            }
        }
        LL ans = CF.flow();
        ans /= 2;
        printf("Case #%d: %lld\n",++Case,ans);
    }
}