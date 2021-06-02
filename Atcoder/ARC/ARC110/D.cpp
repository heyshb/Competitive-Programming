#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
const int MAXM = 2000 * 2000 + 2000 + 10;
int fac[MAXM + 10];
int inv[MAXM + 10];
int N, a[2010], M;

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int C(int N,int M) {
    if (M < 0 || M > N) return 0;
    return 1LL * fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

int C2(int N, int M) {
    //printf("%d %d\n",N,M);
    if (M < 0 || M > N) return 0;
    int ret = 1;
    for (int i=N;i>N-M;i--) {
        ret = 1LL * ret * i % MOD;
    }
    ret = 1LL * ret * inv[M] % MOD;
    return ret;
}

int main() {
    fac[0] = 1;
    for (int i=1;i<=MAXM;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    inv[MAXM] = quick_pow(fac[MAXM], MOD - 2);
    for (int i=MAXM-1;i>=0;i--) {
        inv[i] = 1LL * inv[i + 1] * (i + 1) % MOD;
    }
    int sum = 0;
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int P = M - sum;
    int Q = sum + N;
    int ans = 0;
    /*
    for (int S=0;S<=P;S++) {
        ans = (ans + C(S + Q - 1, Q - 1)) % MOD;
    }
    C(Q - 1, Q - 1) + C(Q, Q - 1) .. + C(Q + P - 1, Q - 1) = C(P + Q, Q) = C(M + N, sum + N)
    */
    ans = C2(M + N, sum + N);
    printf("%d\n",ans);
}