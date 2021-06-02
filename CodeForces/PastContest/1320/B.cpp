#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

int N, M;
int d[200010];
vector<int>e[200010], e2[200010];
int K, a[200010];

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[v].push_back(u);
        e2[u].push_back(v);
    }
    scanf("%d",&K);
    for (int i=1;i<=K;i++) {
        scanf("%d",&a[i]);
    }
    int S, T;
    S = a[1];
    T = a[K];
    const int INF = 1e9;
    for (int i=1;i<=N;i++) {
        d[i] = INF;
    }
    d[T] = 0;
    queue<int>q;
    q.push(T);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto t:e[now]) {
            if (d[t] == INF) {
                d[t] = d[now] + 1;
                q.push(t);
            }
        }
    }
    /*
    for (int i=1;i<=N;i++) {
        printf("%d %d\n",i,d[i]);
    }
    */
    int ma = 0, mi = 0;
    for (int i=1;i<K;i++) { 
        if (d[a[i + 1]] != d[a[i]] - 1) {
            mi++;
            ma++;
        } else {
            int cnt = 0;
            for (auto t:e2[a[i]]) {
                if (d[t] == d[a[i]] - 1) {
                    cnt++;
                }
            }
            if (cnt > 1) {
                ma++;
            }
        }
    }
    printf("%d %d\n",mi,ma);
}