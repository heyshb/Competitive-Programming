#include <bits/stdc++.h>

using namespace std;

int N, K;
bool vis[110];
bool v2[110];
int a[110][110];
int e[110][110];
int match[110];

bool dfs(int x) {
    for (int i=1;i<=N;i++) {
        if (a[x][i] == 0 && !v2[i]) {
            v2[i] = true;
            if (!match[i] || dfs(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d",&a[i][j]);
            vis[a[i][j]] = true;
        }
    }
    bool QAQ = false;
    for (int v=1;v<=N;v++) {
        if (vis[v]) continue;
        for (int i=1;i<=N;i++) {
            match[i] = 0;
        }
        for (int i=1;i<=N;i++) {
            memset(v2,false,sizeof(v2));
            if (!dfs(i)) {
                QAQ = true;
            }
        }
        for (int i=1;i<=N;i++) {
            a[match[i]][i] = v;
        }
    }
    if (QAQ) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("%d%c",a[i][j]," \n"[j==N]);
        }
    }
}