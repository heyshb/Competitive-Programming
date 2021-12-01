#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
LL a[30][30];
bool vis[100];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 == 0) a[i][j] = (1LL << (i + j - 2));
            printf("%lld ",a[i][j]);
        }
        puts("");
    }
    fflush(stdout);
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        LL x;
        scanf("%lld",&x);
        for (int i = 0; i <= 2 * n - 2; i++) {
            vis[i] = (x >> i) & 1;
            //if (vis[i]) printf("%d\n",i);
        }
        int nowx = 0, nowy = 1;
        for (int i = 0; i <= 2 * n - 2; i++) {
            //printf("?? %d %lld\n",vis[i],(a[nowx + 1][nowy] > 0));
            if (vis[i] == (a[nowx + 1][nowy] > 0) && nowx + 1 <= n) {
                nowx++;
            } else {
                nowy++;
            }
            printf("%d %d\n",nowx,nowy);
        }
        fflush(stdout);
    }
}