#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int MOD = 998244353;
int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) {
            ret = 1LL * ret * a % MOD;
        }
        x >>= 1;
        a = 1LL * a * a % MOD;
    }
    return ret;
}
int N, M;
int q[5010][5010];

int main() {
    scanf("%d%d",&N,&M);
    for (int i=0;i<=M;i++) {
        for (int j=0;j<=N;j++) {
            q[i][j] = quick_pow(i, j);
        }
    }
    LL ans = 1LL * q[M][N] * N % MOD;
    for (int i=1;i<=M;i++) {
        for (int len=2;len<=N;len++) {
            LL pos = N - len + 1;
            LL in = q[M - i][len - 2];
            LL out = q[M][N - len];
            ans = (ans + MOD - pos * in % MOD * out % MOD) % MOD;
        }
    } 
    printf("%lld\n",ans);
}