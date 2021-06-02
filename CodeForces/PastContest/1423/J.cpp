#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int M;
int digit[64];
const int MOD = 1e9 + 7;
int f[64][8],g[65536][8];
void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x-= MOD;
}

int main() {
    int T;
    scanf("%d",&T);
    LL N;
    for (N = 0; N < 65536; N++) {
        M = 0;
        memset(digit, 0, sizeof(digit));
        while(N) {
            digit[++M] = N % 2;
            N /= 2;
        }
        memset(f, 0, sizeof(f));
        f[1][0] = 1;
        for (int i=1;i<=16;i++) {
            for (int j=0;j<8;j++) {
                if (f[i][j] == 0) continue;
                for (int k=0;k<8;k++) {
                    if (((j + k) & 1) != digit[i]) continue;
                    upd(f[i+1][(j+k)>>1],f[i][j]);
                }
            }
        }
    }
    printf("%d\n",(f[M][0] + f[M][1]) % MOD);
    while(T--) {
        LL N;
        scanf("%lld",&N);
        M = 0;
        while(N) {
            digit[++M] = N % 2;
            N /= 2;
        }
        memset(f, 0, sizeof(f));
        f[1][0] = 1;
        for (int i=1;i<M;i++) {
            for (int j=0;j<8;j++) {
                if (f[i][j] == 0) continue;
                for (int k=0;k<8;k++) {
                    if (((j + k) & 1) != digit[i]) continue;
                    upd(f[i+1][(j+k)>>1],f[i][j]);
                }
            }
        }
        printf("%d\n",(f[M][0] + f[M][1]) % MOD);
    }
}