#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

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

LL n, m, k, r, c;
LL ax, ay, bx, by;
LL freedom;

//[lo1, hi1] [lo2, hi2]
pii intersect(pii p1, pii p2) {
    if (p1.first == -1 || p2.first == -1) return pii(-1, -1);
    int lo = max(p1.first, p2.first);
    int hi = min(p1.second, p2.second);
    if (lo > hi) return pii(-1, -1);
    return pii(lo, hi);
}

int main() {
    scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&r,&c);
    scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
    freedom = n * m;

}