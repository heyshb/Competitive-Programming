#include <bits/stdc++.h>

using namespace std;

int MOD;
int N, M;
typedef long long LL;
LL fac[510], inv[510];

LL quick_pow(LL a, LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

LL C(LL N, LL M) {
    if (N < M || M < 0) return 0;
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

LL dp1[510];// ways to put i people as a continuous segment
LL dp2[510];
LL f[510][510], g[510][510];

void upd(LL &x, LL y) {
    x += y;
    x %= MOD;
}

int main() {
    scanf("%d%d%d",&N,&M,&MOD);
    fac[0] = 1;
    inv[0] = 1;
    const int MM = 500;
    for (int i=1;i<=MM;i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = quick_pow(fac[i], MOD - 2);
    }
    dp1[0] = 1;
    dp1[1] = 2;
    dp2[0] = 0;
    dp2[1] = 0;
    for (int i=2;i<=MM;i++) {
        //dp1[i] = 2LL * (i - 1 + 2) * dp1[i - 1] % MOD;
        for (int j=0;j<i;j++) {
            dp1[i] += dp1[j] * dp1[i - 1 - j] % MOD * C(i - 1, j) % MOD * (i + 1) % MOD;
            dp1[i] %= MOD;
            dp2[i] += C(i - 1, j) * ((dp2[j] * dp1[i - 1 - j] % MOD + dp2[i - 1 - j] * dp1[j] % MOD) * (i + 1) % MOD
                      + dp1[j] * dp1[i - 1 - j] % MOD * 
                      (1LL * j * (j + 1) / 2 + 1LL * (i - 1 - j) * (i - 1 - j + 1) / 2) % MOD) % MOD;
            dp2[i] %= MOD;
            /*
            printf("?? %lld %lld\n",dp1[j],dp1[i-1-j]);
            printf("ooo %lld %lld %lld %lld\n",dp2[j],dp1[i-1-j],dp2[i-1-j],dp1[j]);
            printf("delta %d %d = %lld\n",i,j,C(i - 1, j) * (dp2[j] * dp1[i - 1 - j] % MOD + dp2[i - 1 - j] * dp1[j] % MOD + 
                      dp1[j] * dp1[i - 1 - j] % MOD * 
                      (1LL * j * (j + 1) / 2 + 1LL * (i - 1 - j) * (i - 1 - j + 1) / 2)) % MOD);
            */
        } 
        if (i >= 390)
        printf("%d %lld %lld\n",i,dp1[i],dp2[i]);
    }
    f[0][0] = 0;
    g[0][0] = 1;
    for (int i=1;i<=N;i++) {
        for (int j=0;j<=min(i,M);j++) { // put j
            for (int k=0;k<=j;k++) { // last seg = k
                /*
                if (i == 3 && j == 2) {
                    printf("%d %d %lld %lld %lld\n",i-k-(k<i),j-k,f[i-k-(k<i)][j-k],C(j, k),dp2[k]);
                }
                */
                upd(f[i][j], C(j, k) * (f[i-k-(k<i)][j-k] * dp1[k] % MOD + dp2[k] * g[i-k-(k<i)][j-k] % MOD) % MOD);
                upd(g[i][j], C(j, k) * g[i-k-(k<i)][j-k] % MOD * dp1[k] % MOD);
            }
            printf("f[%d][%d]=%lld\n",i,j,f[i][j]);
        }
    }
    printf("%lld\n",f[N][M]);
} 