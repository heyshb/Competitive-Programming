#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
const int MOD = 998244353;
const int D = 20;
int f[200010][D + 1];
int fac[200010], ifac[200010];
vector<int> dv[200010];

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i=1;i<=200000;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        for (int j=i*2;j<=M;j+=i) {
            dv[j].push_back(i);
        }
    }
    for (int i=1;i<=M;i++) {
        f[i][1] = 1;
        for (auto d: dv[i]) {
            for (int j=2;j<=D;j++) {
                f[i][j] = (f[i][j] + f[d][j - 1]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=M;i++) {
        for (int j=1;j<=D;j++) {
            ans = (ans + 1LL * C(N - 1, j - 1) * f[i][j] % MOD) % MOD;
        }
    }
    printf("%d\n",ans);
}