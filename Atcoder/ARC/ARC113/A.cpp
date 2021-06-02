#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int M = 200000;

int main() {
    vector<int> f(M + 10), g(M + 10), h(M + 10);
    for (int i=1;i<=M;i++) {
        f[i] = 0;
        for (int j=1;j*j<=i;j++) {
            if (i % j == 0) {
                f[i] += 2;
                if (j * j == i) f[i]--;
            }
        }
        for (int j=1;j*j<=i;j++) {
            if (i % j == 0) {
                //if (i == 4) printf("!!%d %lld %lld\n",j,f[j],f[i/j]);
                g[i] += f[j];
                if (j * j != i) {
                    g[i] += f[i / j];
                }
            }
        }
    }
    partial_sum(g.begin(), g.end(), h.begin());
    int K;
    scanf("%d",&K);
    printf("%lld\n",h[K]);
}