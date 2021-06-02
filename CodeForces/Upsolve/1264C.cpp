#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 998244353;
int N, Q;
LL p[200010];
LL mp[200010],imp[200010],s[200010];
typedef pair<int,int> pii;

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

LL solve(pii p) {
    int L = p.first, R = p.second;
    LL up, down, ret;
    down = mp[R] * imp[L - 1] % MOD;
    up = (s[R] - s[L - 1]) * imp[L - 1] % MOD;
    return up * inv(down) % MOD;
}

bool save[200010];

int main() {
    scanf("%d%d",&N,&Q);
    LL inv100 = quick_pow(100, MOD - 2);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&p[i]);
        p[i] *= inv100;
        p[i] %= MOD;
    }
    mp[0] = 1;
    imp[0] = 1;
    s[0] = 0;
    for (int i=1;i<=N;i++) {
        mp[i] = mp[i - 1] * p[i] % MOD;
        imp[i] = inv(mp[i]);
        s[i] = (s[i - 1] + mp[i - 1]) % MOD;
    }
    set<pii> st;
    st.insert(pii(1,N));
    st.insert(pii(N + 1, N + 1));
    LL ans = solve(pii(1, N));
    for (int i=1;i<=N;i++) {
        save[i] = false;
    }
    save[1] = true;
    while(Q--) {
        int x;
        scanf("%d",&x);
        if (save[x]) {
            auto it = st.lower_bound(pii(x, -1));
            pii p2 = (*it);
            it--;
            pii p1 = (*it);
            ans -= solve(p1);
            ans -= solve(p2);
            pii nxt = pii(p1.first, p2.second);
            ans += solve(nxt);
            ans %= MOD;
            if (ans < 0) ans += MOD;
            st.erase(p1);
            st.erase(p2);
            st.insert(nxt);
            save[x] = false;
        } else {
            auto it = st.lower_bound(pii(x, N + 1));
            it--;
            pii now = (*it);
            pii p1 = pii(now.first, x - 1);
            pii p2 = pii(x, now.second);
            ans -= solve(now);
            ans += solve(p1);
            ans += solve(p2);
            ans %= MOD;
            if (ans < 0) ans += MOD;
            st.erase(now);
            st.insert(p1);
            st.insert(p2);
            save[x] = true;
        }
        printf("%lld\n",ans);
    }
}