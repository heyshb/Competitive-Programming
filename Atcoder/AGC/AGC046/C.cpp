#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char s[310];
int a[310];
int f[310][310][310];
const int MOD = 998244353;
void upd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%s", s);
    scanf("%d", &K);
    N = strlen(s);
    int tmp = 0;
    M = 0;
    for (int i=0;i<N;i++) {
        if (s[i] == '1') {
            tmp++;
        } else {
            a[++M] = tmp;
            tmp = 0;
        }
    }
    a[++M] = tmp;
    //for (int i=1;i<=M;i++) printf("%d %d\n",i,a[i]);
    K = min(K, N);
    f[0][0][0] = 1;
    for (int i=0;i<=M;i++) {
        for (int j=0;j<=K;j++) {
            for (int k=0;k<=K;k++) {
                int v = f[i][j][k];
                if (!v) continue;
                assert(j<=k);
                // return
                for (int l=0;l<=j && l<=a[i+1];l++) {
                    upd(f[i+1][j-l][k], v);
                }
                // borrow
                for (int l=1;k+l<=K;l++) {
                    upd(f[i+1][j+l][k+l], v);
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=K;i++) {
        upd(ans, f[M][0][i]);
    }
    printf("%d\n",ans);
}