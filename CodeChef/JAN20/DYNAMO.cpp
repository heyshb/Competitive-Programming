#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        LL A,B,C,D,E,S;
        int N;
        scanf("%d",&N);
        LL P = 1;
        for (int i=1;i<=N;i++) {
            P *= 10;
        }
        scanf("%lld",&A);
        printf("%lld\n",A + 2 * P);
        fflush(stdout);
        scanf("%lld",&B);
        printf("%lld\n",P - B);
        fflush(stdout);
        scanf("%lld",&B);
        printf("%lld\n",P - B);
        fflush(stdout);
        int ret;
        scanf("%d",&ret);
        assert(ret == 1);
    }
}