#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int cnt[500010];
LL a[500010];
LL po[10000];
const int MOD = 1e9 + 7;
LL cnt2[100][2];
LL w[500010],w2[500100];

int main() {
    po[0] = 1;
    for (int i=1;i<10000;i++) po[i] = po[i - 1] * 2LL % MOD;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        memset(cnt2, 0, sizeof(cnt2));
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
            for (int j=0;j<64;j++) {
                cnt2[j][(a[i] >> j) & 1]++;
            }
        }
        LL ans = 0;
        for (int i=1;i<=N;i++) {
            w[i] = 0;
            w2[i] = 0;
            for (int j=0;j<64;j++) {
                if ((a[i] >> j) & 1) {
                    w[i] += po[j] * N % MOD;
                    w2[i] += po[j] * cnt2[j][1] % MOD;
                } else {
                    w[i] += po[j] * cnt2[j][1] % MOD;
                }
                w[i] %= MOD;
                w2[i] %= MOD;
            }
            ans += 1LL * w[i] * w2[i] % MOD;
            ans %= MOD;
        }
        printf("%lld\n",ans);
    }
}