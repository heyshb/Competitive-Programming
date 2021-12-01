#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    const int MOD = 1e9 + 7;
    const int M = 1000001;
    vector<int> po(M);
    po[0] = 1;
    for (int i = 1; i < M; i++) {
        po[i] = 2 * po[i - 1] % MOD;
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, m;
        scanf("%d%d",&n,&m);
        vector<pair<pii, int>> s(m);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d",&s[i].X.X,&s[i].X.Y,&s[i].Y);
            s[i].X.X--;
            s[i].X.Y--;
        }
        LL ans = 0;
        for (int i = 0; i < 30; i++) {
            vector<int> b(n), sum(n + 1, 0);
            for (auto &t : s) {
                int L = t.X.X, R = t.X.Y, v = ((t.Y >> i) & 1);
                if (v) continue;
                sum[L]++;
                sum[R + 1]--;
            }
            int S = 0;
            int cnt[2] = {0, 0};
            for (int j = 0; j < n; j++) {
                S += sum[j];
                if (S == 0) {
                    cnt[1]++;
                } else {
                    cnt[0]++;
                }
            }
            if (cnt[1] > 0) {
                ans = (ans + po[cnt[1] - 1 + cnt[0] + i]) % MOD;
            }
        }
        printf("%lld\n",ans);
    }
    
}