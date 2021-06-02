#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, n;
char s[100010];
int f[1010][1010][2], g[1010][1010][2];
void upd(int &x, int y) {x = min(x, y);}
int main() {
    n = 1000;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j][0] = f[i][j][1] = 1e9;
            g[i][j][0] = g[i][j][1] = 1e9;
        }
    }
    // 00, 01, flag
    f[0][0][0] = g[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= 1; k++) {
                if (i > 0) upd(g[i][j][k], -f[i - 1][j + 1][k] + 1);
                if (j > 0) upd(g[i][j][k], -f[i][j - 1][k] + 1);
                if (k > 0) upd(g[i][j][k], -f[i][j][k - 1] + 1);
                upd(f[i][j][k], g[i][j][k]);
                if (j != 0) upd(f[i][j][k], -g[i][j][k]);
            }
        }
    }
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s",s + 1);
        int c00 = 0;
        int c01 = 0;
        for (int i = 1; i < n + 1 - i; i++) {
            if (s[i] != s[n + 1 - i]) {
                c01++;
            } else if (s[i] == '0') {
                c00++;
            }
        }
        int o = (n % 2 == 1 && s[(n + 1) / 2] == '0');
        if (f[c00][c01][o] < 0) puts("ALICE");
        else if (f[c00][c01][o] > 0) puts("BOB");
        else puts("DRAW");
    }
}