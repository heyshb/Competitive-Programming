#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL quick_pow(LL a,LL x,LL MOD) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    LL N, M;
    scanf("%lld%lld",&N,&M);
    LL tmp = quick_pow(10LL, N, M * M);
    printf("%lld\n",tmp / M);
}