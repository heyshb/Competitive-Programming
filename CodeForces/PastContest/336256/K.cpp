#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, k;
int a[1000010];
int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    LL ans = 0;
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for (int i = 1; i <= k; i++) ans += a[i];
    printf("%lld\n",ans);
}