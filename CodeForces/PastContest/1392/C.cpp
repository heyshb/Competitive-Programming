#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int n;
int a[200010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        LL ans = 0;
        LL mx = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] > a[i + 1]) {
                ans += a[i] - a[i + 1];
            }
        }
        printf("%lld\n",ans);
    }
}