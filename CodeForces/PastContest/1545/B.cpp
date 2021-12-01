#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MOD = 998244353;
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
LL fac[300010];
LL ifac[300010];

LL C(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int n;
char s[300010];

LL solve(LL n, LL k, LL r) {
    return C(n + k + r - k * r - 1, r);
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 300000; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = inv(fac[i]);
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s", s + 1);
        int fuck = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1' && s[i - 1] != '1') {
                int tmp = 0;
                for (int j = i; s[j] == '1'; j++) tmp++;
                if (tmp % 2 == 0) fuck += tmp / 2;
            }
        }
        printf("%lld\n",solve(n - 1, 2, fuck));
    }
}