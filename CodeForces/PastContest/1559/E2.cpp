#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;


LL n, m;
LL dp[81][110010], s[81][110010];
LL l[151], r[151];
LL ul[151], ur[151];
LL mu[200010];
const LL MOD = 998244353;
void add(LL &x, LL y){x += y; if (x >= MOD) x -= MOD;}
void sub(LL &x, LL y){x -= y; if (x < 0) x += MOD;}

LL quick_pow(LL a, LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % MOD;
        x >>= 1;
        a = a * a % MOD;
    }
    return ret;
}
LL fc[1000010], ifc[1000010];

LL get_mu(LL x) {
    LL nx = x;
    LL num = 0;
    for (LL i = 2; i * i <= nx; i++) {
        if (x % i == 0) {
            num++;
            LL cnt = 0;
            while(x % i == 0) {
                x /= i;
                cnt++;
            }
            if (cnt > 1) return 0;
        }
    }
    return num % 2 == 1 ? 1 : -1;
}

LL C(int n, int k) {
    if (k > n || k < 0) return 0;
    return fc[n] * ifc[k] % MOD * ifc[n - k] % MOD;
}

int main() {
    fc[0] = ifc[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fc[i] = fc[i - 1] * i % MOD;
        ifc[i] = quick_pow(fc[i], MOD - 2);
    }
    mu[1] = 1;
    for (LL i = 2; i <= 100000; i++) {
        mu[i] = get_mu(i);
    }

    scanf("%lld%lld",&n,&m);
    for (LL i = 1; i <= n; i++) {
        scanf("%lld%lld",&l[i],&r[i]);
    }
    LL ans = 0;
    for (LL fac = 1; fac <= m; fac++) {
        if (mu[fac] == 0) continue;
        LL up = m / fac;
        bool ok = true;
        for (LL i = 1; i <= n; i++) {
            ul[i] = (l[i] + fac - 1) / fac;
            ur[i] = (r[i]) / fac;
            if (ul[i] > ur[i]) ok = false;
        }
        if (!ok) continue;
        for (LL i = 0; i <= n; i++) {
            for (LL j = 0; j <= up; j++) {
                dp[i][j] = s[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (LL j = 0; j <= up; j++) {
            s[0][j] = 1;
        }
        for (LL i = 1; i <= n; i++) {
            for (LL j = 0; j <= up; j++) {
                LL U = j - ul[i];
                LL D = j - ur[i];
                if (U < 0) dp[i][j] = 0;
                else {
                    dp[i][j] = s[i - 1][U];
                    if (D - 1 >= 0) {
                        sub(dp[i][j], s[i - 1][D - 1]);
                    }
                }
                if (j == 0) s[i][j] = dp[i][j];
                else {
                    s[i][j] = s[i][j - 1];
                    add(s[i][j], dp[i][j]);
                }
            }
        }
        //prLLf("ans %d = %d\n",fac,s[n][up]);
        if (mu[fac] == -1) {
            sub(ans, s[n][up]);
        } else {
            add(ans, s[n][up]);
        }
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%lld\n",ans);
}