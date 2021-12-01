#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    const int M = 1000000;
    vector<int> is_prime(M + 1, 1);
    for (int i = 2; i <= M; i++) {
        for (int j = 2 * i; j <= M; j += i) {
            is_prime[j] = 0;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, e;
        scanf("%d%d",&n,&e);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            if (a[i] == 1) {
                a[i] = 0;
            } else if (is_prime[a[i]]) {
                a[i] = 1;
            } else {
                a[i] = 2;
            }
        }
        vector<vector<LL>> dp(n, vector<LL>(2, 0));
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 2) continue;
            dp[i][a[i]] = 1;
            if (a[i] == 1) ans--;
            if (i - e >= 0) {
                for (int j = 0; j < 2; j++) {
                    int last = j - a[i];
                    if (last >= 0 && last <= 1) {
                        dp[i][j] += dp[i - e][last];
                    }
                }
            }
            ans += dp[i][1];
            //printf("%d: %lld %lld\n",i,dp[i][0],dp[i][1]);
        }
        printf("%lld\n",ans);
    }
    
}