#include <bits/stdc++.h>

using namespace std;

int main() {
    int Cases;
    long long x;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%lld",&x);
        if (x < 20 || (x >= 30 && x < 40) || x == 59) {
            printf("Case #%d: IMPOSSIBLE\n", T);
        } else {
            printf("Case #%d: %lld\n", T, x / 20);
        }
    }
}