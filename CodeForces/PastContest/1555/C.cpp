#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

typedef long long LL;
LL a[2][100010], s[2][100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for (int j = 0; j <= 1; j++) {
            for (int i = 1; i <= n; i++) {
                scanf("%lld",&a[j][i]);
                s[j][i] = s[j][i - 1] + a[j][i];
            }
        }
        LL ans = 1e18;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, max(s[0][n] - s[0][i], s[1][i - 1]));
        }
        printf("%lld\n",ans);
    }
}