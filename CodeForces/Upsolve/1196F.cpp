#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N,M,K;
pair<int,pii>ee[200010];
vector<pii> e[200010];
int vis[200010], MM = 0;
LL d[810][810];
const LL INF = 1e18;

int main() {
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1;i<=M;i++) {
        int u,v,len;
        scanf("%d%d%d",&u,&v,&len);
        ee[i].first = len;
        ee[i].second = pii(u, v);
    }
    sort(ee+1,ee+M+1);
    for (int i=1;i<=min(M,K);i++) {
        int u = ee[i].second.first;
        int v = ee[i].second.second;
        if (!vis[u]) {
            vis[u] = ++MM;
        }
        if (!vis[v]) {
            vis[v] = ++MM;
        }
        e[vis[u]].push_back(pii(vis[v], ee[i].first));
        e[vis[v]].push_back(pii(vis[u], ee[i].first));
    }
    for (int i=1;i<=MM;i++) {
        for (int j=1;j<=MM;j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
        for (auto t:e[i]) {
            int u = t.first;
            int len = t.second;
            d[i][u] = min(d[i][u], LL(len));
        }
    }
    for (int k=1;k<=MM;k++) {
        for (int i=1;i<=MM;i++) {
            for (int j=1;j<=MM;j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<LL>ds;
    for (int i=1;i<=MM;i++) {
        for (int j=i+1;j<=MM;j++) {
            ds.push_back(d[i][j]);
        }
    }
    sort(ds.begin(),ds.end());
    printf("%lld\n",ds[K - 1]);
}