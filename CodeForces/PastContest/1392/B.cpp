#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
LL k;
LL a[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%lld",&n,&k);
        k = k % 2;
        if (k == 0) k = 2;
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        while(k--) {
            LL mx = *max_element(a+1,a+n+1);
            for (int i = 1; i <= n; i++) a[i] = mx - a[i];
        }
        for (int i = 1; i <= n; i++) {
            printf("%lld%c",a[i]," \n"[i==n]);
        }
    }
}