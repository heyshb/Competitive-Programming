#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL L, R;

LL getsum(LL L, LL R) {
    if (L > R) return 0;
    if (R % 2 != L % 2) R--;
    return (L + R) * ((R - L) / 2 + 1) / 2;
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%lld%lld",&L,&R);
        bool swp = false;
        if (L < R) {
            swap(L, R);
            swp = true;
        }
        LL delta = L - R;
        LL xl = 0, xr = 2e9;
        while(xl < xr - 1) {
            LL mid = (xl + xr) / 2;
            if (mid * (mid + 1) / 2 <= delta) {
                xl = mid;
            } else {
                xr = mid;
            }
        }
        L -= xl * (xl + 1) / 2;
        if (L == R && swp) {
            swp = false;
        }
        xl++;
        LL yl = -1, yr = 2e9;
        while(yl < yr - 1) {
            LL mid = (yl + yr) / 2;
            LL dl = getsum(xl, xl + mid);
            LL dr = getsum(xl + 1, xl + mid);
            if (dl > L || dr > R) yr = mid;
            else yl = mid;
        }
        LL dl = getsum(xl, xl + yl);
        LL dr = getsum(xl + 1, xl + yl);
        L -= dl;
        R -= dr;
        if (swp) swap(L, R);
        printf("Case #%d: %lld %lld %lld\n",T, xl + yl, L, R);
    }
}