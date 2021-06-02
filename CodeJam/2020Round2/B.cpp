#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
vector<pii>e[1010];
int N, M;
vector<int>rk[1010];
int d[1010],val[1010];
int len[1010], nowmax;
int ev[1010],eu[1010];
bool vis[1010];
const int INF = 1e6;

void setd(int x, int D) {
    nowmax = max(nowmax, D);
    d[x] = D;
    vis[x] = true;
    for (auto t:e[x]) {
        int vid = t.first, eid = t.second;
        if (d[vid] >= D) continue;
        len[eid] = D - d[vid];
    }
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        nowmax = 0;
        scanf("%d%d",&N,&M);
        for (int i=0;i<=N;i++) rk[i].clear();
        for (int i=1;i<=N;i++) e[i].clear();
        for (int i=1;i<=M;i++) len[i] = INF;
        for (int i=1;i<=N;i++) vis[i] = false;
        vis[1] = true;
        d[1] = 0;
        for (int i=2;i<=N;i++) {
            d[i] = INF;
            scanf("%d",&val[i]);
            if (val[i] < 0) {
                rk[-val[i]+1].push_back(i);
            } else {
                d[i] = val[i];
            }
        }
        for (int i=1;i<=M;i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            eu[i] = u;
            ev[i] = v;
            e[u].push_back(pii(v, i));
            e[v].push_back(pii(u, i));
        }
        for (int i=2;i<=N;) {
            if (rk[i].empty()) {
                int mind = INF, idx = -1;
                for (int j=2;j<=N;j++) {
                    if (d[j] < mind && !vis[j]) {
                        mind = d[j];
                        idx = j;
                    }
                }
                setd(idx, mind);
                i++;
            } else {
                int maxd = nowmax;
                for (auto p:rk[i]) {
                    setd(p, maxd + 1);
                }
                i+=rk[i].size();
            }
        }
        printf("Case #%d:",T);
        for (int i=1;i<=M;i++) printf(" %d",len[i]);
        puts("");
    }
}

/*
1
6 9
-1 -1 -3 15 20
1 2
1 3
2 3
2 4
2 5
3 5
3 6
4 5
5 6
*/