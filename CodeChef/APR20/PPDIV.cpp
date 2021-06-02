#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;
const LL rev6 = 166666668;
const LL INF = 1e18;
LL N;
const LL ub[65] = {
    -1, -1, 1000000000, 1259921, 37606, 4573, 1122, 411, 193, 108, 67, 46, 33, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 6, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1
};
int sgn[65]; 

// calculate mu
void prework() {
    for (int i=2;i<=64;i++) {
        sgn[i] = -1;
        int tmp = i;
        for (int j=2;j<=64;j++) {
            if (tmp % j == 0) {
                sgn[i] = -sgn[i];
                tmp /= j;
                if (tmp % j == 0) {
                    sgn[i] = 0;
                    break;
                }
            }
        }
        //printf("%d %d\n",i, sgn[i]);
    }
}

// get the maximum r, r * r <= x
LL my_sqrt(LL x) {
    LL r = sqrt(x) - 0x1p-20;
    if (2 * r < x - r * r) {
        ++r;
    }
    return r;
}

// return \sum_{i*i<=x}{i*i}
LL get_square_sum(LL x) {
    LL r = my_sqrt(x);
    LL ret = r * (r + 1) % MOD * (2 * r + 1) % MOD;
    return ret * rev6 % MOD;
}

// return \sum_{L<=i*i<=R}{i*i}
LL get_square_sum_between(LL L, LL R) {
    return (get_square_sum(R) - get_square_sum(L - 1) + MOD) % MOD;
}

LL my_pow(LL a,LL b) {
    LL ret = 1;
    while(b--) {
        ret *= a;
    }
    return ret;
}

LL solve(int y) {
    if (!sgn[y]) {
        return 0;
    }
    LL ret = 0;
    if (y == 2) {
        LL B = pow(N, 0.33333);
        for (LL x=2;x<=B;x++) {
            if (x * x > N) {
                break;
            }
            ret = (ret + N / (x * x) * (x * x)) % MOD;
        }
        LL L = B * B + 1;
        while(L <= N) {
            LL R = N / (N / L);
            ret = (ret + get_square_sum_between(L, R) * (N / L)) % MOD;
            L = R + 1; 
        }
    } else {
        LL max_x = -1;
        if (my_pow(ub[y], y) <= N) {
            max_x = ub[y];
        } else {
            LL L = 1, R = ub[y];
            while(L < R - 1) {
                LL mid = (L + R) / 2;
                if (my_pow(mid, y) <= N) {
                    L = mid;
                } else {
                    R = mid;
                }
            } 
            max_x = L;
        }
        for (LL i=2;i<=max_x;i++) {
            LL tmp = my_pow(i, y);
            ret = (ret + N / tmp * tmp) % MOD;
        }
    }
    return (ret * sgn[y] + MOD) % MOD;
}

int main() {
    prework();
    LL ss = 0;
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &N);
        LL ans = N;
        for (int y=2;y<=64;y++) {
            ans += solve(y);
            ans %= MOD;
        }
        printf("%lld\n",ans);
    }
}