#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,M;
const int MOD = 1e9 + 7;
char mp[300][300],mp2[300][300];
int f[2][16][1 << 15][2][2];

void upd(int &x,int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) {
        scanf("%s", mp[i] + 1);
    }
    if (N < M) {
        for (int i=1;i<=M;i++) {
            for (int j=1;j<=N;j++) {
                mp2[i][j] = mp[j][i];
            }
        }
        for (int i=1;i<=M;i++) {
            for (int j=1;j<=N;j++) {
                mp[i][j] = mp2[i][j];
            }
        }
        swap(N, M);
    }
    for (int i=1;i<=N;i++) {
        for (int j=0;j<=M;j++) {
            mp[i][j] = mp[i][j+1];
        }
    }
    int nxt = 0, now = 1;
    int ans = 0;
    f[0][M][0][0][0] = 1;
    for (int i=1;i<=N;i++) {
        for (int j=0;j<=M;j++) {
            for (int mask = 0; mask < (1 << M); mask++) { // down
                for (int k=0;k<2;k++) { // this line right
                    for (int l=0;l<2;l++) { // number of ignored grids
                        f[now][j][mask][k][l] = 0;
                    }
                }
            }
        }
        for (int j=0;j<=M;j++) {
            for (int mask = 0; mask < (1 << M); mask++) { // down
                for (int k=0;k<2;k++) { // this line right
                    for (int l=0;l<2;l++) { // number of ignored grids
                        if (j == 0 && k == 1) continue;
                        int nowv = (j ? f[now][j][mask][k][l] : (f[nxt][M][mask][0][l] + f[nxt][M][mask][1][l]) % MOD);
                        if (!nowv) continue;
                        if (j == M) continue;
                        int ni = now, nj = j + 1, nmask, nk, nl;
                        if (mp[i][j] == '.') { // empty
                            // put
                            nmask = (mask | (1 << j));
                            nk = 1;
                            nl = l;
                            upd(f[ni][nj][nmask][nk][nl], nowv);
                            // ignore this one
                            if (k || (mask & (1 << j))) {
                                nl = l;
                            } else {
                                nl = l + 1;
                            }
                            if (nl > 1) continue;
                            nmask = mask;
                            nk = k;
                            upd(f[ni][nj][nmask][nk][nl], nowv);
                        } else { // block
                            nmask = (mask & (((1 << M) - 1) ^ (1 << j)));
                            nk = 0;
                            nl = l;
                            upd(f[ni][nj][nmask][nk][nl], nowv);
                        }
                    }
                }
            }
        }
        swap(nxt, now);
    }
    for (int mask = 0; mask < (1 << M); mask++) { 
        for (int k=0;k<2;k++) { 
            for (int l=0;l<2;l++) { 
                upd(ans, f[nxt][M][mask][k][l]);
            }
        }
    }
    printf("%d\n",ans);
}