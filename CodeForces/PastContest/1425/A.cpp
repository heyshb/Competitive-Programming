#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f(LL x) {
    if (x <= 1) return x;
    if (x == 2) return 1;
    if (x == 3) return 2;
    if (x == 4) return 3;
    if (x % 2 == 1) return x - f(x - 1);
    if (x % 4 != 0) {
        return x - f(x / 2);
    } else {
        return x - f(x - 1);
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        LL n;
        LL ans = 0;
        scanf("%lld",&n);
        printf("%lld\n",f(n));
    }
}

/*
1,3,4,5,8,9,11,12,14,15
2,2,3,4,3,4,4,5,5,6,4,5,5,6,5,6,6,7,6,7
81 8
83 8
85 9
87 8
89 9
91 9
93 10
95 6
97 7
99 7
*/