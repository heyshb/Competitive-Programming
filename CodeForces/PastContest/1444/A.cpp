#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    LL T, P, Q;
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld%lld",&P,&Q);
        if (P % Q != 0) {
            printf("%lld\n",P);
            continue;
        }
        vector<LL>fac;
        LL tq = Q;
        for (LL i=2;i*i<=Q;i++) {
            if (tq % i == 0) {
                fac.push_back(i);
                while(tq % i == 0) tq /= i;
                if (tq == 1) break;
            }
        }
        if (tq > 1) fac.push_back(tq);
        LL mind = 1e18;
        for (auto t:fac) {
            LL tmp = P / Q;
            LL fuck = 1;
            while(tmp % t == 0) {
                tmp /= t;
                fuck *= t;
            }
            fuck *= t;
            mind = min(mind, fuck);
        }
        printf("%lld\n",P/mind);
    }
}