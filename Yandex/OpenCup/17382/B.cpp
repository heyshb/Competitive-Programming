#include <bits/stdc++.h>

using namespace std;

int N, K;
int v[11];
char mp[11][11];
int a[11][11];
int ans = 0;

void dfs(int dep) {
    if (dep == K + 1) {
        bool ok = true;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (mp[i][j] == 'O' && !a[i][j]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans++;
        }
        return;
    }
    int len = v[dep];
    // hor
    for (int i=1;i<=N;i++) {
        for (int j=1;j+len-1<=N;j++) {
            bool ok = true;
            for (int k=j;k<=j+len-1;k++) {
                if (mp[i][k] == 'X' || a[i][k]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int k=j;k<=j+len-1;k++) {
                a[i][k] = dep;
            }
            dfs(dep + 1);
            for (int k=j;k<=j+len-1;k++) {
                a[i][k] = 0;
            }
        }
    }
    // ver
    if (len == 1) return;
    for (int i=1;i<=N;i++) {
        for (int j=1;j+len-1<=N;j++) {
            bool ok = true;
            for (int k=j;k<=j+len-1;k++) {
                if (mp[k][i] == 'X' || a[k][i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int k=j;k<=j+len-1;k++) {
                a[k][i] = dep;
            }
            dfs(dep + 1);
            for (int k=j;k<=j+len-1;k++) {
                a[k][i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d%d",&N, &K);
    for (int i=1;i<=N;i++) {
        scanf("%s", mp[i] + 1);
    }
    for (int i=1;i<=K;i++) {
        scanf("%d",&v[i]);
    }
    memset(a, 0, sizeof(a));
    dfs(1);
    printf("%d\n",ans);
}