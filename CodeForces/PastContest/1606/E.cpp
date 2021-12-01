#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, x;
const int MOD = 998244353;
const int M = 501;
int fac[M + 10], ifac[M + 10];

int quick_pow(int a, int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int dp[M + 10][M + 10];
int po[M + 10][M + 10];

int main() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= M; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    for (int i = 0; i <= M; i++) {
        po[i][0] = 1;
        for (int j = 1; j <= M; j++) {
            po[i][j] = 1LL * po[i][j - 1] * i % MOD;
        }
    }
    scanf("%d%d",&n,&x);
    for (int i = 1; i <= x; i++) dp[1][i] = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = i; k <= n; k++) {
                if (i == 1 && k == 1) continue;
                if (j + k - 1 > x) break;
                int extra = k - i;
                int way = 1LL * C(n - i, extra) * po[k - 1][extra] % MOD;
                upd(dp[k][j + k - 1], 1LL * way * dp[i][j] % MOD);
            }
        }
    }
    int ans = po[x][n];
    for (int i = 1; i <= x; i++) {
        upd(ans, MOD - dp[n][i]);
    }
    printf("%d\n",ans);
}