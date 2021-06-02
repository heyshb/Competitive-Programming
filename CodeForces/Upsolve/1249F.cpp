#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,K;
int f[210][210],h[210],a[210];
int g[210];
vector<int>e[210];

void dfs(int x,int ff) {
    h[x] = 0;
    f[x][0] = a[x]; 
    for (auto t:e[x]) {
        if (t == ff) continue;
        dfs(t, x);
        for (int i=0;i<=N;i++) {
            g[i] = 0;
        }
        for (int j=0;j<=h[t];j++) {
            for (int i=0;i<=h[x];i++) {
                if (i + j + 1 <= K) continue;
                int nxt = min(i, j + 1);
                g[nxt] = max(g[nxt], f[x][i] + f[t][j]);
            }
            g[j + 1] = max(g[j + 1], f[t][j]);
        }
        for (int i=0;i<=N;i++) {
            f[x][i] = max(f[x][i], g[i]);
        }
        h[x] = max(h[x], h[t] + 1);
    }
    /*
    printf("fuck %d\n",x);
    for (int i=0;i<=h[x];i++) {
        printf("%d %d\n",i,f[x][i]);
    }
    */
}

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<N;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i=0;i<=N;i++) {
        ans = max(ans, f[1][i]);
    }
    printf("%d\n",ans);
}