#include <bits/stdc++.h>

using namespace std;

int N,v1,v2;
char s[200010];
bool ok1[200010];
const int MOD = 1e9 + 7;
typedef long long LL;
LL fac[200100], rev[200100];

LL C(LL N,LL M) {
    //printf("%lld %lld %lld %lld %lld\n",N,M,fac[N],rev[M],rev[N-M]);
    return fac[N] * rev[M] % MOD * rev[N - M] % MOD;
}

LL qp(LL a,LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    fac[0] = 1;
    for (int i=1;i<=200000;i++) fac[i] = fac[i - 1] * i % MOD;
    rev[200000] = qp(fac[200000], MOD - 2);
    for (int i=199999;i>=0;i--) {
        rev[i] = rev[i + 1] * (i + 1) % MOD;
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        v1 = v2 = 0;
        scanf("%s",s);
        for (int i=0;i<N;i++) {
            if (s[i] == '1') {
                v1++;
            } 
        }
        scanf("%s",s);
        for (int i=0;i<N;i++) {
            if (s[i] == '1') {
                v2++;
            } 
        }
        LL ans = 0;
        //printf("%d %d\n",v1,v2);
        int up = min(v1, v2), down = max(v1 + v2 - N, 0);
        //printf("%d %d\n",down, up);
        for (int i=down;i<=up;i++) {
            int one = 2 * i + N - v1 - v2;
            ans = (ans + C(N, one)) % MOD;
        }
        printf("%lld\n",ans);
    }
}