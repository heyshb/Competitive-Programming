#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const LL INF = 1e12;
int id[100010][51];
LL d[5100010];
vector<pii>e[100010];
vector<pii>e2[5100010];
typedef pair<LL,int> pli;
int N, M;

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(pii(v, w));
        e[v].push_back(pii(u, w));
    }
    for (int i=1;i<=N;i++) {
        for (int j=0;j<=50;j++) {
            f[i][j] = INF;
            id[i][j] = j * N + i;
            d[id[i][j]] = INF;
            for (auto &t: e[i]) {
                int v = t.first;
                int w = t.second;
            }
        }
    }
    int NN = id[N][50];
    d[1] = 0;
    priority_queue<pli> heap;
    for ()
    q.push(pii(1, 0));
    inq[1][0] = true;
    while(!q.empty()) {
        auto pp = q.front();
        q.pop();
        int u = pp.first, w = pp.second;
        for (auto &t: e[u]) {
            int v = t.first, w2 = t.second;
            int neww;
            LL cost;
            if (w == 0) {
                neww = w2;
                cost = 0;
            } else {
                neww = 0;
                cost = (w + w2) * (w + w2);
            }
            if (f[u][w] + cost < f[v][neww]) {
                f[v][neww] = f[u][w] + cost;
                if (!inq[v][neww]) {
                    inq[v][neww] = true;
                    q.push(pii(v, neww));
                }
            }
        }
        inq[u][w] = false;
    }
    for (int i=1;i<=N;i++) {
        if (f[i][0] == INF) f[i][0] = -1;
        printf("%lld%c",f[i][0]," \n"[i==N]);
    }
}