#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
int f[3010][3010][3][3];
int A,B,C,D;

int main() {
    scanf("%d%d%d%d",&A,&B,&C,&D);
    f[A][B][0][0] = 1;
    int ans = 0;
    for (int i=A;i<=C;i++) {
        for (int j=B;j<=D;j++) {
            for (int k=0;k<3;k++) {
                for (int l=0;l<3;l++) {
                    int nk, nl;
                    int v = f[i][j][k][l];
                    if (!v) continue;
                    //printf("f[%d][%d][%d][%d] = %d\n",i,j,k,l,v);
                    if (i == C && j == D) upd(ans, v);
                    // add i
                    upd(f[i+1][j][1][l], 1LL * v * (j - 1) % MOD);
                    upd(f[i+1][j][1][min(l+1,2)], v);

                    // add j
                    if (k != 1 || i == A) {
                        upd(f[i][j+1][k][1], 1LL * v * (i - 1) % MOD);
                    }
                    if (min(k+1,2) != 1 || i == A) {
                        upd(f[i][j+1][min(k+1,2)][1], v);
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}