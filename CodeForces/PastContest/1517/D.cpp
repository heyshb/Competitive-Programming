#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m, K;
int hor[510][510], ver[510][510];
LL dp[11][510][510];
void upd(LL &x, LL y) {
    x = min(x, y);
}

int main() {
    scanf("%d%d%d",&n,&m,&K);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d",&hor[i][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d",&ver[i][j]);
        }
    }
    if (K % 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d%c",-1," \n"[j==m]);
            }
        }
        return 0;
    }
    K /= 2;
    for (int r = 1; r <= K; r++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int w;
                LL &ndp = dp[r][i][j];
                ndp = 1e15;
                // left
                w = hor[i][j - 1];
                if (j - 1 > 0) upd(ndp, w + dp[r - 1][i][j - 1]);
                // right
                w = hor[i][j];
                if (j + 1 <= m) upd(ndp, w + dp[r - 1][i][j + 1]);
                // up
                w = ver[i - 1][j];
                if (i - 1 > 0) upd(ndp, w + dp[r - 1][i - 1][j]);
                // down
                w = ver[i][j];
                if (i + 1 <= n) upd(ndp, w + dp[r - 1][i + 1][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%lld%c", dp[K][i][j] * 2, " \n"[j == m]);
        }
    }
}