#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;
const int M = 1e7 + 10;
vector<int>prime;
bool ok[M + 10];
int mu[M + 10];

void sieve() {
    prime.reserve(M);
    for (int i=1;i<=M;i++) {
        ok[i] = true;
    }
    mu[1] = 1;
    for (int i=2;i<=M;i++) {
        if (ok[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (auto &t: prime) {
            if (i * t > M) break;
            ok[i * t] = false;
            if (i % t == 0) {
                mu[i * t] = 0;
                break;
            } else {
                mu[i * t] = -mu[i];
            }
        }
    }
}

LL sqf(LL n) {
    LL ret = 0;
    for (LL k = 1; k * k <= n; k++) {
        ret += (n / (k * k)) * mu[k];
    }
    return ret;
}

LL solve(LL n) {
    LL ret = 0;
    for (LL s = 1; s * s <= n; s++) {
        ret += s * s * sqf(n / (s * s));
        ret %= MOD;
    }
    return ret;
}

int main() {
    sieve();
    printf("%lld\n",solve(10));
    printf("%lld\n",solve(100));
    printf("%lld\n",solve(1e14));
}