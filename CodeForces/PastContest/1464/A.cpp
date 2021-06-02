#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T, N, M;
typedef pair<int,int> pii;
int e[100010];
bool vis[100010],in[100010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        int x, y;
        for (int i=1;i<=N;i++) {
            e[i] = 0;
            vis[i] = false;
            in[i] = false;
        }
        int ans = 0;
        for (int i=1;i<=M;i++) {
            scanf("%d%d", &x, &y);
            if (x == y) continue;
            ans++;
            e[x] = y;
            in[y] = true;
        }
        for (int i=1;i<=N;i++) {
            if (!vis[i] && e[i] && !in[i]) {
                int j;
                for (j=i;j!=0&&!vis[j];vis[j]=true,j=e[j]);
            }
        }
        for (int i=1;i<=N;i++) {
            if (!vis[i] && e[i]) {
                int j;
                for (j=i;j!=0&&!vis[j];vis[j]=true,j=e[j]);
                if (j) ans++;
            }
        }
        printf("%d\n",ans);
    }
}