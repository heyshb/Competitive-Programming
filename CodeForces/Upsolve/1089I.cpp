#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 400;
int f[MN + 10][MN + 10], ans[MN + 10], g[MN + 10];
int MOD = 1e9 + 7;
int fac[MN + 10];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

void nico() {
    fac[0] = 1;
    for (int i=1;i<=MN;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    f[0][0] = 1;
    // i permutations sum_length = j
    for (int i=0;i<MN;i++) {
        for (int j=i;j<MN;j++) {
            for (int k=1;j+k<=MN;k++) {
                add(f[i + 1][j + k], 1LL * f[i][j] * fac[k] % MOD);
            }
        }
    }
    g[1] = 1;
    // i elements, none of prefix is a permutation of prefix
    for (int i=2;i<=MN;i++) {
        g[i] = fac[i];
        // enum the end of the first permutation of the invalid permutations
        for (int j=1;j<i;j++) {
            sub(g[i], 1LL * g[j] * fac[i - j] % MOD);
        }
    }
    //printf("%d\n",f[2][3]);
    ans[1] = 1;
    ans[2] = 2;
    for (int i=3;i<=MN;i++) {
        ans[i] = fac[i];
        for (int j=3;j<i;j++) {
            sub(ans[i], 1LL * f[j][i] * ans[j] % MOD);
        }
        for (int j=1;j<i;j++) {
            sub(ans[i], 2LL * g[j] * fac[i - j] % MOD);
        }
        //if (i <= 10) printf("ans[%d]=%d\n",i,ans[i]);
    }
}

int main() {
    int T;
    scanf("%d%d",&T,&MOD);
    nico();
    while(T--) {
        int N;
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
}