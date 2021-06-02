#include <bits/stdc++.h>

using namespace std;

int N;
typedef long long LL;
LL a[100010],s[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+N+1);
        for (int i=1;i<=N;i++) {
            s[i] = s[i - 1] + a[i];
        }
        LL ans = 0;
        for (int i=2;i<=N;i++) {
            ans += 1LL * (i - 1) * a[i] - s[i - 1];
        }
        printf("%lld\n",ans);
    }
}