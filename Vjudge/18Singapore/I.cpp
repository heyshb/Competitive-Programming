#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
int N, R, C, K;
int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    } 
    return ret;
}
LL po[5010];
LL way1[5010], way2[5010];

int main() {
    scanf("%d%d%d%d",&N,&R,&C,&K);
    for (int i=1;i<=max(R, C);i++) {
        po[i] = quick_pow(i, N);
    }
    LL ans = 0;
    for (int len=1;len<=R;len++) {
        for (int i=1;i+len-1<=R;i++) {
            int l = i, r = R - (i + len - 1) + 1;
            //printf("%d %d %d\n",i,l,r);
            way1[len] = (way1[len] + (po[l] - po[l - 1] + MOD) * (po[r] - po[r - 1] + MOD)) % MOD;
        }
        //printf("%d %lld\n",len,way1[len]);
    }
    for (int len=1;len<=C;len++) {
        for (int i=1;i+len-1<=C;i++) {
            int l = i, r = C - (i + len - 1) + 1;
            way2[len] = (way2[len] + (po[l] - po[l - 1] + MOD) * (po[r] - po[r - 1] + MOD)) % MOD;
        }
        //printf("%d %lld\n",len,way2[len]);
    }
    for (int i=1;i<=R;i++) {
        for (int j=1;j<=C;j++) {
            if (i * j < K) continue;
            ans = (ans + way1[i] * way2[j] % MOD) % MOD;
        }
    }
    printf("%d\n",ans);
}