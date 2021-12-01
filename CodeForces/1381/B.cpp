#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int ok[4010][2][4010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        vector<int> a(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i <= 2 * n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2 * n; k++) {
                    ok[i][j][k] = 0;
                }
            }
        }
        ok[0][0][n] = 1;
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int d = 0; d <= 2 * n; d++) {
                    if (ok[i][j][d]) {
                        printf("ok %d %d %d\n",i,j,d);
                        int delta = (j ? -1 : 1);
                        if (a[i + 1] < a[i]) {
                            ok[i + 1][j][d + delta] = 1;
                        } else {
                            ok[i + 1][j][d + delta] = 1;
                            ok[i + 1][j ^ 1][d - delta] = 1;
                        }
                    }
                }
            }
        }
        puts(ok[2 * n][0][n] || ok[2 * n][1][n] ? "YES" : "NO");
    }
    
}