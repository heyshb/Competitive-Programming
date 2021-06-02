#include <bits/stdc++.h>

using namespace std;

int N, a[3010], b[3010];
vector<int>e[3010];
bool vis[110];
int S, T, M = 1;
const int MAXM = 3010 * 100 * 2;
int head[3010], en[MAXM], nxt[MAXM], f[MAXM], cur[3010];

void addedge(int x,int y,int cap) {
    //printf("add %d %d %d\n",x,y,cap);
    M++; en[M] = y; nxt[M] = head[x]; f[M] = cap; head[x] = M;
    M++; en[M] = x; nxt[M] = head[y]; f[M] = 0; head[y] = M;
}

queue<int>q;
int d[3010];
bool bfs() {
    for (int i=1;i<=T;i++) d[i] = -1;
    d[S] = 0;
    q.push(S);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i=head[now];i;i=nxt[i]) {
            if (!f[i]) continue;
            if (d[en[i]] == -1) {
                d[en[i]] = d[now] + 1;
                q.push(en[i]);
            }
        }
    }
    return d[T] != -1;
}

int dfs(int x,int a) {
    if (a == 0 || x == T) return a;
    int ret = 0;
    for (int &i=cur[x];i;i=nxt[i]) {
        if (f[i] && d[en[i]] == d[x] + 1) {
            int tmp = dfs(en[i], min(a, f[i]));
            f[i] -= tmp;
            f[i ^ 1] += tmp;
            a -= tmp;
            ret += tmp;
            if (!a) break;
        }
    }
    return ret;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=N;i++) {
        scanf("%d",&b[i]);
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=100;j++) vis[j] = false;
        for (int j=i-1;j>=1;j--) {
            if (!vis[a[j]] && a[i] % a[j] == 0) {
                e[i].push_back(j);
                vis[a[j]] = true;
            }
        }
    }
    S = N + 1;
    T = N + 2;
    int ans = 0;
    const int INF = 1e9;
    for (int i=1;i<=N;i++) {
        if (b[i] > 0) addedge(S, i, b[i]), ans += b[i];
        else addedge(i, T, -b[i]);
        for (auto t:e[i]) addedge(i, t, INF);
    }
    while(bfs()) {
        for (int i=1;i<=T;i++) cur[i] = head[i];
        ans -= dfs(S, INF);
    }
    printf("%d\n",ans);
}