#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
int fac[1000010];
int ifac[1000010];

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int n, k;

int C(LL n, LL m) {
    if (n < 0 || m < 0 || m > n) return 0;
    return 1LL * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

void add(int &x, int y) {
    x = (x + y) % MOD;
}

int mul(int x, int y) {
    return 1LL * x * y % MOD;
}

int fuck(int r) {
    return C(n + k + r - 1LL * k * r - 1, r);
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            //printf("%d %d\n",i,fuck(i));
            int tmp = fuck(i);
            tmp = mul(tmp, fac[i]);
            tmp = mul(tmp, fac[n - i]);
            add(ans, tmp);
        }
        ans = mul(ans, ifac[n]);
        add(ans, 1);
        printf("%d\n",ans);
    }
}