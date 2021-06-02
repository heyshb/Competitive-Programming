#include <bits/stdc++.h>

using namespace std;

int n;
typedef long long LL;
LL a[200010];

int main() {
    scanf("%d",&n);
    LL mx = 0;
    LL s = 0;
    LL S = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&a[i]);
        s += a[i];
        S += s;
        mx = max(mx, a[i]);
        printf("%lld\n",S + mx * i, " \n"[i==n]);
    }
}