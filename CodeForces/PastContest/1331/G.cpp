#include <bits/stdc++.h>

using namespace std;

int q[11];

void solve(int x) {
    double ret = 0;
    double a = sqrt(abs(x));
    double b = x * x * x * 5;
    double o = a + b;
    if (o <= 400) {
        printf("f(%d) = %.2lf\n",x, o);
    } else {
        printf("f(%d) = MAGNA NIMIS!\n",x);
    }
}

int main() {
    for (int i=0;i<11;i++) {
        scanf("%d",&q[i]);
    }
    for (int i=10;i>=0;i--) {
        solve(q[i]);
    }
}