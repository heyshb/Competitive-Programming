#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;
const int N = 100000000;
int fac[N + 10];
int ifac[N + 10];
int cache[N + 10];

int range_mul(int L,int R) {
    return 1LL * fac[R] * ifac[L - 1] % MOD;
}

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

// f(n) = \prod_{i=1...n}{f(n / i) * i ^ (phi(n / i))}?
int solve(int n) {
    if (cache[n] != -1) return cache[n];
    int ans = 0;
    for (int l=1,r=0;l<=n;l=r+1) {
        r = n / (n / l);
        //printf("%d %d\n",l,r);
        int fuck = n / l;
        int f_fuck = solve(fuck);
    } 
    return cache[n] = ans;
}

int main() {
    fac[0] = 1;
    for (int i=1;i<=N;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        cache[i] = -1;
    }
    cache[1] = 1;
    ifac[N] = quick_pow(fac[N], MOD - 2);
    for (int i=N-1;i>=0;i--) {
        ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
    }
    printf("%d\n",solve(10));
    //printf("%d\n",solve(10000000));
}

// 10 23044331520000 331358692