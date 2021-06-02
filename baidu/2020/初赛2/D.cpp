#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int cnt[10];
char ss[110];
int d[10],sum[5];
int ans = 0;

void dfs(int dep) {
    if (dep == 10) {
        memset(sum, 0, sizeof(sum));
        for (int i=0;i<10;i++) {
            sum[d[i]] += cnt[i];
        }
        int tmpmin = 1e9;
        for (int i=0;i<5;i++) {
            tmpmin = min(tmpmin, sum[i]);
        }
        ans = max(ans, tmpmin);
        return;
    } else {
        for (int i=0;i<5;i++) {
            d[dep] = i;
            dfs(dep + 1);
        }
    }
}

int main() {
    int T, N;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        memset(cnt, 0, sizeof(cnt));
        for (int i=1;i<=N;i++) {
            scanf("%s", ss + 1);
            char lst = ss[strlen(ss + 1)];
            cnt[lst - '0']++;
        }
        ans = 0;
        dfs(0);
        printf("%d\n",N - ans);
    }
}