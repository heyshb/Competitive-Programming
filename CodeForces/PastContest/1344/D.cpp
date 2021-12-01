#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int n;
    LL k;
    scanf("%d%lld",&n,&k);
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld",&a[i]);
    }
    auto calc_delta = [&](LL ai, LL x) {
        x--;
        return ai - 3 * x * x - 3 * x - 1;
    };
    // only use delta >= mid
    vector<LL> b(n);
    auto check = [&](LL mid) {
        for (int i = 0; i < n; i++) {
            if (calc_delta(a[i], a[i]) >= mid) {
                b[i] = a[i];
                continue;
            }
            if (calc_delta(a[i], 1LL) < mid) {
                b[i] = 0;
                continue;
            }
            LL L2 = 1, R2 = a[i];
            while(L2 < R2 - 1) {
                LL mid2 = (L2 + R2) / 2;
                if (calc_delta(a[i], mid2) >= mid) {
                    L2 = mid2;
                } else {
                    R2 = mid2;
                }
            }
            b[i] = L2;
        }
        LL ret = 0;
        for (auto &t : b) ret += t;
        return ret;
    };
    LL L = -4e18, R = 4e18;
    while(L < R - 1) {
        LL mid = (L + R) / 2;
        if (check(mid) >= k) {
            L = mid;
        } else {
            R = mid;
        }
    }
    check(R);
    /*
    printf("R = %lld\n",R);
    for (int i = 0; i < n; i++) {
        printf("%lld%c",b[i]," \n"[i==n-1]);
    }
    */
    for (auto &t : b) k -= t;
    //printf("?? %lld\n",calc_delta(5LL, 4LL));
    for (int i = 0; i < n && k; i++) {
        //printf("i=%d, %lld %lld %lld %lld\n",i,b[i],a[i],calc_delta(a[i] , b[i] + 1),L);
        if (b[i] < a[i] && calc_delta(a[i], b[i] + 1) == L) {
            k--;
            b[i]++;
        }
    }
    //printf("%lld\n",k);
    for (int i = 0; i < n; i++) {
        printf("%lld%c",b[i]," \n"[i==n-1]);
    }
}