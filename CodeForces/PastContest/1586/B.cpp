#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, m;
        scanf("%d%d",&n,&m);
        vector<int>vis(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            vis[b] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                for (int j = 1; j <= n; j++) {
                    if (j != i) printf("%d %d\n",i,j);
                }
                break;
            }
        }
    }
}