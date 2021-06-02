#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N, E, H, A, B, C;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld%lld%lld%lld%lld%lld",&N,&E,&H,&A,&B,&C);
        const LL INF = 1e18;
        LL ans = INF;
        LL e, h, a, b;
        for (LL c=0;c<=N;c++) {
            if (c > E || c > H) break;
            e = E - c;
            h = H - c;
            LL need = N - c;
            // most a
            a = min(need, e / 2);
            b = need - a;
            if (3 * b <= h) {
                //printf("?? %d %d %d\n",a,b,c);
                ans = min(ans, a * A + b * B + c * C);
            }
            // most b
            b = min(need, h / 3);
            a = need - b;
            if (2 * a <= e) {
                //printf("?? %d %d %d\n",a,b,c);
                ans = min(ans, a * A + b * B + c * C);
            }
        }
        if (ans == INF) ans = -1;
        printf("%lld\n",ans);
    }
}