#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[510][510];
int N, M;
int f[510][510];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=0;i<=N+1;i++) {
            for (int j=0;j<=M+1;j++) {
                s[i][j] = '.';
                f[i][j] = 0;
            }
        }
        for (int i=1;i<=N;i++) {
            scanf("%s", s[i] + 1);
        }
        int ans = 0;
        for (int i=N;i>=1;i--) {
            for (int j=1;j<=M;j++) {
                if (s[i][j] == '.') {
                    f[i][j] = 0;
                } else {
                    f[i][j] = min(min(f[i+1][j], f[i+1][j-1]), f[i+1][j+1]) + 1;
                    ans += f[i][j];
                }
            }
        }
        printf("%d\n",ans);
    }
}