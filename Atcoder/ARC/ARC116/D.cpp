#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;
const int D = 13;
int N, M;
int f[D + 1][5010];

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int fac[200010], ifac[200010];
int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i=1;i<=5000;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    scanf("%d%d",&N,&M);
    for (int i=0;i<=min(N, M);i+=2) {
        f[0][i] = C(N, i);
    }
    for (int i=0;i<D;i++) {
        for (int j=0;j<=M;j+=2) {
            if (f[i][j]) {
                //printf("f[%d][%d] = %d\n",i,j,f[i][j]);
                for (int k=0;k<=N && j+(k<<(i+1))<=M;k+=2) {
                    upd(f[i+1][j+(k<<(i+1))], 1LL * f[i][j] * C(N, k) % MOD);
                }
            }
        }
    }
    printf("%d\n",f[D][M]);
}