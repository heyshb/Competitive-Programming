#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pll;
int n, m;
LL a[200010];
pll seg[200010], s[200010];
int M;
LL dp[200010][3];
LL L[200010], R[200010];

LL mm(int idx) {
    return min(min(dp[idx][0], dp[idx][1]), dp[idx][2]);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        set<LL>p;
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
            p.insert(a[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%lld%lld",&seg[i].first, &seg[i].second);
        }
        sort(seg + 1, seg + m + 1, [](pll &p1, pll &p2) {
            if (p1.second == p2.second) return p1.first > p2.first;
            return p1.second < p2.second;
        });
        const LL INF = 1e18;
        LL mx = -INF; // max left
        M = 0;
        for (int i = 1; i <= m; i++) {
            if (mx >= seg[i].first) {
                continue;
            }
            mx = seg[i].first;
            auto it = p.lower_bound(seg[i].first);
            if (it != p.end() && (*it) <= seg[i].second) {
                continue;
            }
            //printf("add %lld %lld\n",seg[i].first,seg[i].second);
            s[++M] = seg[i];
        }
        for (int i = 1; i <= M; i++) {
            auto tmp = p.lower_bound(s[i].first);
            if (tmp == p.begin()) {
                L[i] = INF;
            } else {
                --tmp;
                L[i] = *tmp;
            }
            tmp = p.upper_bound(s[i].second);
            if (tmp == p.end()) {
                R[i] = INF;
            } else {
                R[i] = *tmp;
            }
            //printf("%d: %lld %lld\n",i,L[i],R[i]);
        }
        auto cmin = [](LL &x, LL y) {
            if (y < x) x = y;
        };
        dp[1][0] = dp[1][1] = dp[1][2] = INF;
        if (L[1] != INF) dp[1][0] = s[1].first - L[1];
        if (R[1] != INF) dp[1][1] = R[1] - s[1].second;
        for (int i = 2; i <= M; i++) {
            //printf("? %lld,%lld\n",s[i].first,s[i].second);
            dp[i][0] = dp[i][1] = dp[i][2] = INF;
            cmin(dp[i][1], dp[i - 1][1] + s[i].second - s[i - 1].second);
            cmin(dp[i][0], dp[i - 1][1] + abs(s[i].first - s[i - 1].second));
            cmin(dp[i][0], dp[i - 1][0] + s[i].first - s[i - 1].first);
            cmin(dp[i][1], dp[i - 1][0] + s[i].second - s[i - 1].first);
            if (R[i] != INF) {
                if (R[i] == R[i - 1]) {
                    cmin(dp[i][2], min(dp[i - 1][1], dp[i - 1][2]));
                } else {
                    cmin(dp[i][1], mm(i - 1) + R[i] - s[i].second);
                }
            }
            if (L[i] != INF) {
                if (L[i] == R[i - 1]) {
                    cmin(dp[i][2], 2LL * (s[i].first - L[i]) + min(dp[i - 1][1], dp[i - 1][2]));
                } else if (L[i] == L[i - 1]) {
                    cmin(dp[i][2], 2LL * (s[i].first - s[i - 1].first) + min(dp[i - 1][0], dp[i - 1][2]));
                } else {
                    cmin(dp[i][0], mm(i - 1) + s[i].first - L[i]);
                }
            }
            //printf("dp[%d] = %lld,%lld,%lld\n",i,dp[i][0],dp[i][1],dp[i][2]);
        }
        printf("%lld\n",mm(M));
    }
}
