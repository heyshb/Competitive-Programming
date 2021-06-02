#include <bits/stdc++.h>

using namespace std;

int N, a[510], f[510][510], g[510];

int solve(int L,int R) {
    if (f[L][R] != -1) return f[L][R];
    assert(L <= R);
    if (L == R) {
        return f[L][R] = a[L];
    }
    for (int i=L;i<R;i++) {
        int f1 = solve(L, i), f2 = solve(i + 1, R);
        if (f1 <= 0 || f2 <= 0) continue;
        if (f1 == f2) {
            return f[L][R] = f1 + 1;
        }
    }
    return f[L][R] = 0;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            f[i][j] = -1;
        }
    }
    solve(1, N);
    g[0] = 0;
    for (int i=1;i<=N;i++) {
        g[i] = 1e9;
        for (int j=1;j<=i;j++) {
            if (f[j][i] > 0) {
                g[i] = min(g[i], g[j - 1] + 1);
            }
        }
    }
    printf("%d\n",g[N]);
}