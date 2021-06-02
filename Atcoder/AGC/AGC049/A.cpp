#include <bits/stdc++.h>

using namespace std;

char s[110][110];
bool vis[110][110];
int N;

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%s", s[i] + 1);
        for (int j=1;j<=N;j++) {
            vis[i][j] = (j == i || s[i][j] == '1');
        }
    }
    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                vis[i][j] |= (vis[i][k] && vis[k][j]);
            }
        }
    }
    double ans = 0;
    for (int i=1;i<=N;i++) {
        int cnt = 0;
        for (int j=1;j<=N;j++) {
            if (vis[j][i]) cnt++;
        }
        ans += 1.0 / cnt;
    }
    printf("%.10lf\n",ans);
}