#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, MOD = 1e9 + 7;
int N;
int M = 5;
LL po[4000100];
LL fac[2010], inv[2010];
LL quick_pow(LL a, LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

LL g[2010][2010];
LL s[4010];
LL C(LL N, LL K) {
    return fac[N] * inv[K] % MOD * inv[N - K] % MOD;
}

int main() {
    scanf("%d%d",&T,&MOD);
    po[0] = 1;
    for (int i=1;i<=4000000;i++) {
        po[i] = po[i - 1] * 2LL % MOD;
    }
    fac[0] = inv[0] = 1;
    for (int i=1;i<=2000;i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = quick_pow(fac[i], MOD - 2);
    }
    for (int j=0;j<=2000;j++) {
        for (int k=0;k<=2000;k++) {
            g[j][k] = inv[j] * inv[k] % MOD;
            g[j][k] = g[j][k] * po[j * k] % MOD;
            s[j + k] += g[j][k];
            s[j + k] %= MOD;
        }
    }
    while(T--) {
        scanf("%d",&N);
        LL ans = 0;
        for (int i=0;i<=N;i++) {
            LL tmp = C(N, i);
            tmp = tmp * po[i * (N - i)] % MOD;
            tmp = tmp * fac[N - i] % MOD;
            tmp = tmp * s[N - i] % MOD;
            ans = (ans + tmp) % MOD;
        }
        printf("%lld\n",ans);
    }
}