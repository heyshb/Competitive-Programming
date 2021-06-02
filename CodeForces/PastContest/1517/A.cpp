#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    LL x;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld",&x);
        if (x % 2050 != 0) {
            puts("-1");
            continue;
        }
        x /= 2050;
        LL ans = 0;
        while(x) {
            ans += x % 10;
            x /= 10;
        }
        printf("%lld\n",ans);
    }
}