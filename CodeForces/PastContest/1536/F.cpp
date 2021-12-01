#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
LL quick_pow(LL a,LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

LL inv(LL x) {
    return quick_pow(x, MOD - 2);
}

int n;
LL fac[1000010], ifac[1000010];

int C(int m, int k) {
    if (k > m || k < 0) return 0;
    return fac[m] * ifac[k] % MOD * ifac[m - k] % MOD;
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int way(int m, int k) {
    int ret = C(m - k, k);
    add(ret, C(m - 1 - k, k - 1));
    return ret;
}

LL po2[1000010];

int main() {
    scanf("%d",&n);
    fac[0] = ifac[0] = po2[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = inv(fac[i]);
        po2[i] = 2LL * po2[i - 1] % MOD;
    }
    int ans = 0;
    // how many empty
    for (int d = n % 2; d <= n; d += 2) {
        int w = way(n, d);
        LL tmp = (d ? po2[d] : 2LL);
        tmp = tmp * w % MOD;
        tmp = tmp * fac[n - d] % MOD;
        //printf("%d %d %lld\n",d,w,tmp);
        add(ans, tmp);
    }
    printf("%d\n",ans);
}