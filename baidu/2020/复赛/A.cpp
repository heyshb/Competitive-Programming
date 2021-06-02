#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int inv(int x) {
    return quick_pow(x, MOD - 2);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int m, p, q;
        scanf("%d%d%d",&m,&p,&q);
        p = 100LL * inv(p) % MOD;
        p = 1LL * p * m % MOD;
        p--;
        if (p < 0) p += MOD;
        p = 1LL * p * q % MOD;
        p = 1LL * p * inv(100) % MOD;
        p = m - p;
        if (p < 0) p += MOD;
        printf("%d\n", p);
    }
}