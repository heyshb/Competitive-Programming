#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int X, K;

int fac(int X) {
    int TX = X;
    int ret = 0;
    for (int i=2;i*i<=TX;i++) {
        while(X % i == 0) {
            ret++;
            X /= i;
        }
    }
    if (X > 1) ret++;
    return ret;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d", &X, &K);
        puts(fac(X) < K ? "0" : "1");
    }
}