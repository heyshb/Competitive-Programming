#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, a[500010];
const int MOD = 998244353;

LL quick_pow(LL a,LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

LL inv(LL x) {
    return quick_pow(x, MOD - 2);
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=2*N;i++) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+2*N+1);
    LL C = 1;
    for (int i=2*N;i>=N+1;i--) {
        C = C * i % MOD;
    }
    for (int i=1;i<=N;i++) {
        C = C * inv(i) % MOD;
    }
    LL tmp = 0;
    for (int i=1;i<=N;i++) tmp = (tmp - a[i] + MOD) % MOD;
    for (int i=N+1;i<=2*N;i++) tmp = (tmp + a[i]) % MOD;
    tmp = tmp * C % MOD;
    printf("%lld\n",tmp);
}