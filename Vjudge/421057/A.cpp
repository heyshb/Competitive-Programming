#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
LL N, M;

LL quick_pow(LL a, LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld%lld",&N,&M);
        LL ans = quick_pow(3LL, N + M) * quick_pow(2LL, N * M) % MOD;
        printf("%lld\n",ans);
    }
}