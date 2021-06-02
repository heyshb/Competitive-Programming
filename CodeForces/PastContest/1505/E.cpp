#include <bits/stdc++.h>

using namespace std;

char s[10][10];
bool vis[10][10];
int N, M;

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) {
        scanf("%s",s[i] + 1);
    }
    vis[1][1] = true;
    int x = 1, y = 1;
    while(true) {
        if (x + 1 <= N) x++;
        vis[x][y] = true;
        if (y + 1 <= M) y++;
        vis[x][y] = true;
        if (x == N && y == M) break;
    }
    int ans = 0;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            if (vis[i][j] && s[i][j] == '*') ans++;
        }
    }
    printf("%d\n",ans);
}