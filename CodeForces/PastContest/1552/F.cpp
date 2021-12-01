#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;

LL x[200010], y[200010], s[200010], sum[200010]; 
LL t[200010];
LL n;
void add(LL &x, LL y) {
    x = (x + y) % MOD;
    if (x < 0) x += MOD;
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld",&x[i],&y[i],&s[i]);
    }
    for (int i = 1; i <= n; i++) {
        t[i] = (x[i] - y[i] + MOD) % MOD;
        int id = lower_bound(x + 1, x + n + 1, y[i]) - x;
        if (id < i) {
            add(t[i], (sum[i - 1] - sum[id - 1] + MOD) % MOD);
        }
        sum[i] = sum[i - 1];
        add(sum[i], t[i]);
        //printf("t[%d]=%d\n",i,t[i]);
    }
    LL ans = (x[n] + 1) % MOD;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 1) add(ans, t[i]);
    }
    printf("%lld\n",ans);
}