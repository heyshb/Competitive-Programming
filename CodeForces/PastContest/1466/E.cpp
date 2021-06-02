#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int cnt[500010];
LL a[500010];
LL po[10000];
const int MOD = 1e9 + 7;
LL cnt1[64][64][2], cnt2[64][2];

int main() {
    po[0] = 1;
    for (int i=1;i<10000;i++) po[i] = po[i - 1] * 2LL % MOD;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
            for (int j=0;j<64;j++) {
                cnt2[j][(a[i] >> j) & 1]++;
                if ((a[i] >> j) & 1) {
                    for (int k=0;k<64;k++) {
                        cnt1[j][k][(a[i] >> k) & 1]++;
                    }
                }
            }
        }
        LL ans = 0;
        for (int d1=0;d1<64;d1++) {
            for (int d2=0;d2<64;d2++) {
                LL pp = po[d1 + d2];
                LL tmp = (cnt2[d1][1] * N) % MOD - cnt1[d1][d2][0] * cnt2[d2][0] % MOD;
                tmp = (tmp + MOD) % MOD;
                tmp = tmp * cnt2[d1][1] % MOD;
                ans += tmp * pp % MOD;
                ans %= MOD;
            }
        }
        printf("%lld\n",ans);
    }
}