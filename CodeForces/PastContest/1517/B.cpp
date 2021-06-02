#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m, a[110][110],b[110][110];
int ans[110][110];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d",&a[i][j]);
                b[i][j] = 0;
            }
        }
        for (int p = 1; p <= m; p++) {
            //printf("p = %d\n",p);
            int mi = 1e9 + 10;
            int x = -1, y = -1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (!b[i][j] && a[i][j] < mi) {
                        x = i;
                        y = j;
                        mi = a[i][j];
                    }
                }
            }
            //printf("fuck %d %d\n",x,y);
            ans[x][p] = a[x][y];
            b[x][y] = 1;
            for (int i = 1; i <= n; i++) {
                if (i == x) continue;
                int mx = -1, id = -1;
                for (int j = 1; j <= m; j++) {
                    if (!b[i][j] && a[i][j] > mx) {
                        mx = a[i][j];
                        id = j;
                    }
                }
                //printf("fuck %d %d\n",i,id);
                b[i][id] = 1;
                ans[i][p] = a[i][id];
                //printf("ans[%d][%d] = %d\n",i,p,ans[i][p]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d%c",ans[i][j]," \n"[j==m]);
            }
        }
    }
}