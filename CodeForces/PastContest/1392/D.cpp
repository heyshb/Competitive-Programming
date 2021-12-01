#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int n;
char s[200010];
int dp[200010][2][2];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s",s + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = (s[i] == 'L' ? 0 : 1);
        }
        const int INF = 1e9;
        auto upd = [](int &x, int y){x = min(x, y);};
        int ans = 1e9;
        for (int v1 = 0; v1 < 2; v1++) {
            for (int v2 = 0; v2 < 2; v2++) {
                int bias = (s[1] != v1) + (s[2] != v2);
                for (int i = 1; i <= n; i++) {
                    dp[i][0][0] = INF;
                    dp[i][0][1] = INF;
                    dp[i][1][0] = INF;
                    dp[i][1][1] = INF;
                }
                dp[2][v2][v1] = bias;
                for (int i = 3; i <= n; i++) {
                    for (int j = 0; j < 2; j++) {
                        for (int k = 0; k < 2; k++) {
                            for (int p = 0; p < 2; p++) {
                                if (j == k && k == p) continue;
                                upd(dp[i][j][k], dp[i - 1][k][p] + (j != s[i]));
                            }
                        }
                    }
                }
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        if (j == k && j == v1) continue;
                        if (j == v1 && v1 == v2) continue;
                        upd(ans, dp[n][j][k]);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}