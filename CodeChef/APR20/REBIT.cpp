#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
char s[100010];
int N;
int match[100010];
int tp, stk[100010];
const LL MOD = 998244353;
const LL R2 = (MOD + 1) / 2;
typedef pair<LL,LL> pll;

// probability of result = 1 when a = 0 / 1 
pll solve(int L) {
    if (s[L] == '#') {
        return pll(R2, R2);
    }
    assert(s[L] == '(');
    int R = match[L];
    int L1, L2;
    L1 = L + 1;
    if (s[R - 1] == ')') {
        L2 = match[R - 1];
    } else {
        L2 = R - 1;
    }
    int split = L2 - 1;
    auto ret1 = solve(L1), ret2 = solve(L2);
    if (s[split] == '&') {
        return pll(ret1.first * ret2.first % MOD, ret1.second * ret2.second % MOD);
    } else if (s[split] == '|') {
        return pll((1 - (1 - ret1.first + MOD) * (1 - ret2.first + MOD) % MOD + MOD) % MOD, 
                   (1 - (1 - ret1.second + MOD) * (1 - ret2.second + MOD) % MOD + MOD) % MOD);
    } else if (s[split] == '^') {
        return pll((ret1.first * (1 - ret2.first + MOD) + (1 - ret1.first + MOD) * ret2.first) % MOD,
                   (ret1.second * (1 - ret2.second + MOD) + (1 - ret1.second + MOD) * ret2.second) % MOD);
    }
    assert(false);
    return pll(-1, -1);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s + 1);
        N = strlen(s + 1);
        tp = 0;
        for (int i=1;i<=N;i++) {
            match[i] = -1;
            if (s[i] == '(') {
                stk[++tp] = i;
            } else if (s[i] == ')') {
                match[stk[tp]] = i;
                match[i] = stk[tp];
                tp--;
            }
        }
        assert(tp == 0);
        auto ret = solve(1);
        LL g0 = ret.first, g1 = ret.second;
        LL ans0, ans1, ansa, ansA;
        ans0 = (1 - g0 + MOD) * (1 - g1 + MOD) % MOD; 
        ans1 = g0 * g1 % MOD;
        ansa = (1 - g0 + MOD) * g1 % MOD;
        ansA = g0 * (1 - g1 + MOD) % MOD;
        assert(ansa == ansA);
        printf("%lld %lld %lld %lld\n",ans0, ans1, ansa, ansA);
    }
}