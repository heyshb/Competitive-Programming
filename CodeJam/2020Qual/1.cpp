#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int a[110][110];
int N;
bool vis[110];

int main() {
    int T;
    scanf("%d",&T);
    for (int _=1;_<=T;_++) {
        scanf("%d",&N);
        int trace = 0;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                scanf("%d",&a[i][j]);
                if (i == j) trace += a[i][j];
            }
        }
        int rcnt = 0, ccnt = 0;
        for (int i=1;i<=N;i++) {
            bool ok;

            for (int j=1;j<=N;j++) {
                vis[j] = false;
            }
            ok = true;
            for (int j=1;j<=N;j++) {
                if (vis[a[i][j]]) {
                    ok = false;
                } 
                vis[a[i][j]] = true;
            }
            if (!ok) rcnt++;

            for (int j=1;j<=N;j++) {
                vis[j] = false;
            }
            ok = true;
            for (int j=1;j<=N;j++) {
                if (vis[a[j][i]]) {
                    ok = false;
                } 
                vis[a[j][i]] = true;
            }
            if (!ok) ccnt++;
        }
        printf("Case #%d: %d %d %d\n",_, trace, rcnt, ccnt);
    }
}
