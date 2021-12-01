#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL C3(int x) {
    return 1LL * x * (x - 1) * (x - 2) / 6;
}

LL C2(int x) {
    return 1LL * x * (x - 1) / 2;
}

int main() {
    int n, P;
    double PP;
    scanf("%d%lf",&n,&PP);
    P = int(PP * 10000 + 0.5);
    for (int x = 0; x <= n; x++) {
        LL up = 2LL * C3(x) + 2LL * C2(x) * (n - x) + 1LL * x * C2(n - x);
        if (up * 5000 >= P * C3(n)) {
            printf("%d\n",x);
            return 0;
        }
    }
    assert(false);
}