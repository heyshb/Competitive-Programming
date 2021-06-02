#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
char s[1000010];
const int MOD = 998244353;
const int MX = 21;
LL f[1000010][MX+2], s2[1000010][MX+2];
LL sum[1000010][3];
LL p2[1000010];

LL getsum(int idx, int L, int R) {
    if (L > R) return 0;
    return (s2[R][idx] - s2[L - 1][idx] + MOD) % MOD;
}

void upd(LL &x, LL y) {
    x += y;
    x %= MOD;
}
int nB[1000010];

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    p2[0] = 1;
    for (int i=1;i<=N;i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }
    reverse(s + 1, s + N + 1);
    // 012
    // ?SB
    for (int i=1;i<=N;i++) {
        if (s[i] == 'S') s[i] = 1;
        if (s[i] == 'B') s[i] = 2;
        if (s[i] == '?') s[i] = 0;
    }
    for (int i=1;i<=N;i++) {
        for (int j=0;j<3;j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][s[i]]++;
    }
    nB[N] = N;
    for (int i=N - 1;i>=1;i--) {
        if (s[i + 1] == 2) nB[i] = i + 1;
        else nB[i] = nB[i + 1];
    }
    for (int i=1;i<=N;i++) {
        if (s[i] != 1) f[i][MX + 1] = (sum[N][2] - sum[i][2] == 0); 
        s2[i][MX + 1] = s2[i - 1][MX + 1] + f[i][MX + 1];
    }
    // 012
    // ?SB
    for (int j=MX;j>=1;j--) {
        for (int i=1;i<=N;i++) {
            if (s[i] == 2 || s[i] == 0) {
                int Scnt = (1 << (j - 1));
                //if (i == 1 && j == 1) printf("%d %d\n",i + Scnt + 1, nB[i]);
                upd(f[i][j], getsum(j + 1, i + Scnt + 1, nB[i]));
                /*
                int R = min(N + 1, i + Scnt + 1);
                if (sum[R - 1][2] - sum[i][2] == 0) {
                    upd(f[i][j], getsum(j + 1, R, N));
                }
                */
                if (sum[N][2] - sum[i][2] == 0) {
                    upd(f[i][j], 1LL);
                }
            }
            s2[i][j] = s2[i - 1][j] + f[i][j];
        }
    }
    
    /*
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=3;j++) {
            printf("f[%d][%d] = %lld\n",i,j,f[i][j]);
        }
    }
    */
    
    LL ans = 0;
    for (int i=1;i<=N;i++) {
        if (sum[i - 1][2] == 0) {
            //printf("%d %lld %lld\n",i,f[i][1],p2[sum[i-1][0]]);
            //upd(ans, f[i][1] * p2[sum[i - 1][0]] % MOD);
            upd(ans, f[i][1]);
        }
    }    
    if (sum[N][2] == 0) upd(ans, 1LL);
    //printf("here %lld\n",ans);
    //printf("?? %lld %lld\n",sum[N][0],p2[sum[N][0]]);
    ans = (p2[sum[N][0]] - ans + MOD) % MOD;
    printf("%lld\n",ans);
}