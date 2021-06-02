class NetworkFlow {
public:
    int head[MAXN], en[MAXM], nxt[MAXM], f[MAXM], cur[MAXN], d[MAXN];
    int S, T, MM;
    const int INF = 1e9;
    queue<int>q;

    void init(int N) {
        MM = 1;
        S = N + 1;
        T = N + 2;
        for (int i=1;i<=T;i++) {
            head[i] = 0;
        }
    }

    void addedge(int u,int v,int ff) {  
        //printf("add %d %d %d\n",u,v,ff);
        MM++;
        en[MM] = v;
        nxt[MM] = head[u];
        f[MM] = ff;
        head[u] = MM;

        MM++;
        en[MM] = u;
        nxt[MM] = head[v];
        f[MM] = 0;
        head[v] = MM;
    }

    bool bfs() {
        for (int i=1;i<=T;i++) {
            cur[i] = head[i];
            d[i] = INF;
        }
        d[S] = 0;
        q.push(S);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i=head[now];i;i=nxt[i]) {
                if (d[en[i]] != INF || !f[i]) {
                    continue;
                }
                d[en[i]] = d[now] + 1;
                q.push(en[i]);
            }
        }
        return (d[T] != INF);
    }

    int dfs(int x,int a) {
        if (x == T || a == 0) {
            return a;
        }
        int ret = 0;
        for (int &i=cur[x];i;i=nxt[i]) {
            if (!f[i] || d[en[i]] != d[x] + 1) {
                continue;
            }
            int tmp = dfs(en[i], min(a, f[i]));
            a -= tmp;
            f[i] -= tmp;
            f[i ^ 1] += tmp;
            ret += tmp;
        }
        return ret;
    }

    int dinic() {
        int ret = 0;
        while(bfs()) {
            ret += dfs(S, INF);
        }
        return ret;
    }
}NF;