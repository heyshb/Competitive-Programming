#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int f[1000010], g[1000010];
const int M = 1000000;
vector<int>fac[M + 10];

int main() {
    for (int i = 2; i <= M; i++) {
        for (int j = 2 * i; j <= M; j += i) {
            if (j != i + i) fac[j].push_back(i);
        }
    }
    g[1] = 1;
    for (int i = 2; i <= M; i++) {
        g[i] = 1;
        for (auto &t : fac[i]) {
            g[i] = max(g[i], g[i / t - 1] + 1);
        }
    }
    f[1] = 1;
    for (int i = 2; i <= M; i++) {
        f[i] = 1;
        for (auto &t : fac[i]) {
            if (t == 2) continue;
            f[i] = max(f[i], g[i / t - 1] + 1);
        }
    }
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        scanf("%d",&N);
        //N = (Case + 3);
        printf("Case #%d: %d\n",++Case,f[N]);
    }
}