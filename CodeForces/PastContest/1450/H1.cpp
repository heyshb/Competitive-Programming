#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
int N, M;
typedef long long LL;

LL quick_pow(LL a,int x) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

char s[200010];
LL fac[200010], inv[200010];

LL C(int N, int M) {
    if (M < 0 || M > N) return 0;
    return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

int main() {
    scanf("%d%d",&N, &M);
    scanf("%s",s);
    int cnt1 = 0, cnt2 = 0, q = 0;
    for (int i=0;i<N;i++) {
        
        if (s[i] == '?') {
            q++;
            continue;
        }
        if ((s[i] == 'w') == (i % 2 == 0)) {
            cnt1++;
        } else {
            cnt2++;
        }
    }
    //printf("%d %d %d\n",cnt1,cnt2,q);
    fac[0] = 1;
    inv[0] = 1;
    for (int i=1;i<=N;i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = quick_pow(fac[i], MOD - 2);
    }
    LL ans = 0;
    LL cnt = 0;
    for (int i=0;i<=q;i++) {
        if (abs(cnt1 - cnt2 + i - (q - i)) % 4 != 0) continue;
        //printf("aaa %d\n",i);
        LL ret = abs(cnt1 - cnt2 + i - (q - i)) / 4;
        //printf("bbb %lld\n",ret);
        //printf("fuck %lld\n",ret * C(q, i) % MOD);
        ans = (ans + ret * C(q, i) % MOD) % MOD;
        cnt = (cnt + C(q, i)) % MOD;
    }
    ans = ans * quick_pow(cnt, MOD - 2) % MOD;
    printf("%lld\n",ans);
}