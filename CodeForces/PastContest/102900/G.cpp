#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n;
// 1 1 0 1 1 0 1 1 0 ...

int main() {
    scanf("%d",&n);
    LL sum_period = n / 3;
    LL cnt_1 = 2 * sum_period;
    LL cnt_0 = sum_period;
    cnt_1 += n % 3;
    LL mul_1 = cnt_1 * (cnt_1 - 1) / 2;
    LL ans = 1LL * n * (n - 1) / 2 - mul_1;
    printf("%lld\n",ans);
}