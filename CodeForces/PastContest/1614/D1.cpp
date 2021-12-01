#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    const int M = 20000000;
    vector<int> cnt(M + 1);
    vector<int> prime, p(M + 1), ok(M + 1, 1);
    for (int i = 2; i <= M; i++) {
        if (ok[i]) {
            prime.push_back(i);
            p[i] = i;
        }
        for (auto &t : prime) {
            if (i * t > M) break;
            ok[i * t] = 0;
            p[i * t] = t;
            if (i % t == 0) {
                break;
            } 
        }
    }
    function<void(vector<pii>&,int, int)> dfs;
    dfs = [&](vector<pii> &pp, int dep, int mul) {
        if (dep == pp.size()) {
            cnt[mul]++;
            //printf("cnt %d++\n",mul);
            return;
        }
        for (int i = 0; i <= pp[dep].second; i++) {
            dfs(pp, dep + 1, mul);
            mul *= pp[dep].first;
        }
    };
    auto calc = [&](int x) {
        //printf("calc %d\n",x);
        vector<pii> pp;
        while(x > 1) {
            int cnt = 0;
            int fac = p[x];
            while(x % fac == 0) {
                x /= fac;
                cnt++;
            }
            pp.emplace_back(fac, cnt);
        }
        dfs(pp, 0, 1);
    };
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d",&tmp);
        calc(tmp);
    }
    vector<LL> dp(M + 1);
    for (int i = 1; i <= M; i++) {
        dp[i] = 1LL * i * cnt[i];
    }
    LL ans = 0;
    for (int i = M; i >= 1; i--) {
        if (!cnt[i]) continue;
        for (int j = 2 * i; j <= M; j += i) {
            dp[i] = max(dp[i], dp[j] + 1LL * i * (cnt[i] - cnt[j]));
        }
        ans = max(ans, dp[i]);
    }
    printf("%lld\n",ans);
}