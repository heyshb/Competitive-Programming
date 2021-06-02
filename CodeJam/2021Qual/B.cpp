#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int N;
int f[1010][2];
int X, Y;
char s[1010];

int main() {
    int T;
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        scanf("%d%d",&X,&Y);
        scanf("%s", s + 1);
        N = strlen(s + 1);
        f[0][0] = f[0][1] = 0;
        for (int i=1;i<=N;i++) {
            if (s[i] == 'C') {
                f[i][1] = INF;
                f[i][0] = min(f[i - 1][0], f[i - 1][1] + Y);
            } else if (s[i] == 'J') {
                f[i][0] = INF;
                f[i][1] = min(f[i - 1][1], f[i - 1][0] + X);
            } else {
                f[i][1] = min(f[i - 1][1], f[i - 1][0] + X);
                f[i][0] = min(f[i - 1][0], f[i - 1][1] + Y);
            }
        }
        int ans = min(f[N][0], f[N][1]);
        printf("Case #%d: %d\n",++Case,ans);
    }
}