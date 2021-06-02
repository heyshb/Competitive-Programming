#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N, K;
LL A[100010], D[100010];
LL ps[100010];
LL pm[100010];
LL ss[100010];

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&A[i]);
    }
    for (int i=1;i<=N;i++) {
        scanf("%lld",&D[i]);
    }
    ps[0] = 0;
    pm[0] = 1e18;
    for (int i=1;i<=N;i++) {
        ps[i] = ps[i - 1] + A[i];
        pm[i] = min(pm[i - 1], D[i]);
    }
    ss[N + 1] = 0;
    for (int i=N;i>=1;i--) {
        ss[i] = max(ss[i + 1], ps[N] - ps[i - 1] - D[i]);
    }
    if (K == 0) {
        printf("%lld\n",ss[1]);
        return 0;
    } 
    if (K >= 2) {
        LL ans = ss[1];
        ans = max(ans, ps[N] - pm[N - 1]);
        printf("%lld\n",ans);
        return 0;
    }
    assert(K == 1);
    LL ans = ss[2];
    LL tmp = -D[1];
    LL minA = 1e18;
    for (int i=2;i<N;i++) {
        minA = min(minA, A[i]);
    }
    tmp += ps[N] - minA;
    ans = max(ans, tmp);
    for (int i=1;i<N;i++) {
        ans = max(ans, max(0LL, ps[i] - pm[i]) + ss[i + 1]);
    }
    printf("%lld\n",ans);
}