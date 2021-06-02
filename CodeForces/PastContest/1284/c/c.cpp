#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
LL N,MOD;
LL fac[250010];

int main() {
    scanf("%lld%lld",&N,&MOD);
    fac[0] = 1;
    for (int i=1;i<=N;i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    LL ans = 0;
    for (LL l=1;l<=N;l++) {
        LL pos = N - l + 1; 
        LL choose = N - l + 1;
        ans += pos * choose % MOD * fac[N - l] % MOD * fac[l] % MOD;
        ans %= MOD;
    }
    printf("%lld\n",ans);
}