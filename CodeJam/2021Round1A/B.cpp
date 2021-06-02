#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int M;
int P[110];
LL N[110];
LL cnt[1010];
LL fac[1010];

int main() {
    int T;
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        printf("Case #%d: ", ++Case);
        scanf("%d",&M);
        LL sum = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i=1;i<=M;i++) {
            scanf("%d%lld",&P[i],&N[i]);
            sum += N[i] * P[i];
            cnt[P[i]] = N[i];
        }
        LL ans = 0;
        for (int s=2;s<=10000;s++) {
            if (s >= sum) break;
            LL another = sum - s;
            LL another_backup = another;
            memset(fac, 0, sizeof(fac));
            for (int i=2;i<=500;i++) {
                while(another > 1 && another % i == 0) {
                    fac[i]++;
                    another /= i;
                }
            }
            if (another != 1) continue;
            LL tmp_sum = 0;
            bool ok = true;
            for (int i=1;i<=500;i++) {
                if (fac[i] > cnt[i]) ok = false;
                tmp_sum += i * fac[i];
            }
            if (tmp_sum == s && ok) {
                ans = max(ans, another_backup);
            }
        }
        printf("%lld\n",ans);
    }
}