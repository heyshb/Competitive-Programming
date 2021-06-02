#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
char s[100010];
int N;
int f[100010][4];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s + 1);
        N = strlen(s + 1);
        for (int i=1;i<=N;i++) {
            for (int j=0;j<4;j++) {
                f[i][j] = 1e9;
            }
        }
        f[1][0] = 0;
        f[1][1] = 1;
        for (int i=2;i<=N;i++) {
            for (int j=0;j<4;j++) {
                for (int k=0;k<2;k++) {
                    bool ok = true;
                    int nj = (k | ((j & 1) << 1));
                    if (k == 0) {
                        if ((j & 1) == 0 && s[i] == s[i - 1]) continue;
                        if ((j & 2) == 0 && s[i] == s[i - 2]) continue;
                        f[i][nj] = min(f[i][nj], f[i - 1][j]);
                    } else {
                        f[i][nj] = min(f[i][nj], f[i - 1][j] + 1);
                    }
                }
            }
        }
        int ans = 1e9;
        for (int i=0;i<4;i++) {
            ans = min(ans, f[N][i]);
        }
        printf("%d\n",ans);

    }
}