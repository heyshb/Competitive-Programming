#include <bits/stdc++.h>

using namespace std;

const int MM = 20;
double dp[MM + 1][MM + 1][MM + 1][MM + 1], mi[MM + 1][MM + 1][MM + 1][MM + 1];
double len[MM + 1][MM + 1];
void upd(double &x, double y) {
    x = min(x, y);
}

int main() {
    for (int i = 0; i <= MM; i++) {
        for (int j = 0; j <= MM; j++) {
            len[i][j] = sqrt(i * i + j * j);
        }
    }
    const double INF = 1e10;
    for (int i = 0; i <= MM; i++) {
        for (int j = 0; j <= MM; j++) {
            for (int k = 0; k <= MM; k++) {
                for (int l = 0; l <= MM; l++) {
                    dp[i][j][k][l] = INF;
                    mi[i][j][k][l] = INF;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for (int i = 0; i <= MM; i++) {
        for (int j = 0; j <= MM; j++) {
            for (int k = 0; k <= MM; k++) {
                for (int l = 0; l <= MM; l++) {
                    if (dp[i][j][k][l] > INF / 2) continue;
                    for (int dx = 0; dx <= MM; dx++) {
                        for (int dy = 0; dy <= MM; dy++) {
                            if (dx == 0 && dy == 0) continue;
                            if (__gcd(dx, dy) != 1) continue;
                            if (dx == k && dy == l) continue;
                            if (i + dx > MM || j + dy > MM) continue;
                            upd(dp[i + dx][j + dy][dx][dy], dp[i][j][k][l] + len[dx][dy]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= MM; i++) {
        for (int j = 0; j <= MM; j++) {
            for (int k = 0; k <= MM; k++) {
                for (int l = 0; l <= MM; l++) {
                    for (int dx = 0; dx <= MM; dx++) {
                        for (int dy = 0; dy <= MM; dy++) {
                            if (dx == k && dy == l) continue;
                            upd(mi[i][j][k][l], dp[i][j][dx][dy]);
                        }
                    }
                }
            }
        }
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, m;
        scanf("%d%d",&n,&m);
        //printf("%.10lf\n",mi[n][m][0][0]);
        double ans = INF;
        for (int dx = 0; dx <= MM; dx++) {
            if (n - dx < 0) break;
            for (int dy = 0; dy <= MM; dy++) {
                if (n - dy < 0) break;
                int x = n - dx;
                int y = m - dy;
                if (__gcd(x, y) != 1) continue;
                double ret = sqrt(1.0 * x * x + 1.0 * y * y);
                if (x <= MM && y <= MM) ret += mi[dx][dy][x][y];
                else ret += mi[dx][dy][0][0];
                upd(ans, ret);
            }
        }
        printf("%.10lf\n",ans);
    }
}