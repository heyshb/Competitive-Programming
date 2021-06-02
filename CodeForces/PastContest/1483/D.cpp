#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int INF = 1e9 + 10;
int d[610][610], q[610][610], W[610][610], f[610][610];
int N, M;

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (i != j) d[i][j] = INF, W[i][j] = INF;
        }
    }
    for (int i=1;i<=M;i++) {
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        W[u][v] = W[v][u] = w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }
    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    /*
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("d[%d][%d] = %d\n",i,j,d[i][j]);
        }
    }
    */
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        q[u][v] = w;
        q[v][u] = w;
    }
    for (int u=1;u<=N;u++) {
        for (int b=1;b<=N;b++) {
            f[u][b] = 0;
            for (int v=1;v<=N;v++) {
                f[u][b] = max(f[u][b], q[u][v] - d[b][v]);
            }
        }
    }
    int ans = 0;
    for (int a=1;a<=N;a++) {
        for (int b=1;b<=N;b++) {
            if (a != b && W[a][b] != INF) {
                bool ok = false;
                for (int u=1;u<=N;u++) {
                    ok |= (d[a][u] + W[a][b] <= f[u][b]);
                }
                if (ok) ans++;
            }
        }
    }
    printf("%d\n",ans / 2);
}