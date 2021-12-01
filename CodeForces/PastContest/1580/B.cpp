#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m, k, p;
int dp[110][110][110];
int C[110][110];
int fac[110];
void add(int &x, int y) {
    x += y;
    if (x >= p) x -= p;
}

int calc(int n, int m, int k) {
    if (k > n || k > n - m + 1) return 0;
    if (m > n || m == 0) {
        if (k == 0) return fac[n];
        return 0;
    }
    if (n == 0) return (k == 0);
    if (m == 1) {
        if (k == 1) return fac[n];
        return 0;
    }
    if (dp[n][m][k] != -1) return dp[n][m][k];
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int tmp = 1LL * calc(n - i, m - 1, k - j) * calc(i - 1, m - 1, j) % p;
            tmp = 1LL * tmp * C[n - 1][i - 1] % p;
            add(ret, tmp);
        }
    }
    return dp[n][m][k] = ret;
}

int main() {
    scanf("%d%d%d%d",&n,&m,&k,&p);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1LL * fac[i - 1] * i % p;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int l = 0; l <= k; l++) {
                dp[i][j][l] = -1;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1];
            add(C[i][j], C[i - 1][j]);
        }
    }
    printf("%d\n",calc(n, m, k));
}