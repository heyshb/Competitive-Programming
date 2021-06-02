#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 998244353;

int N,K;
int A[20010],B[20010];
int f[20010];

int solve() {
    for (int i=1;i<=N;i++) {
        B[i] = (B[i] % MOD + MOD) % MOD;
    }
    for (int i=0;i<=N;i++) {
        f[i] = 0;
    }
    f[0] = 1;
    // get k in i and get K in N
    // k <= i
    // N - i + k >= K
    // k >= K - (N - i)
    for (int i=1;i<=N;i++) {
        int down = max(K - (N - i), 1);
        for (int k=min(K,i);k>=down;k--) {
            f[k] = (f[k] + 1LL * f[k - 1] * B[i]) % MOD;
        }
    }
    return f[K];
}

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<=N;i++) {
        scanf("%d",&A[i]);
    }
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int tp,q,L,R,i,d;
        scanf("%d",&tp);
        if (tp == 1) {
            scanf("%d%d%d",&q,&i,&d);
            for (int j=1;j<=N;j++) {
                B[j] = q - A[j];
            }
            B[i] = q - d;
        } else {
            scanf("%d%d%d%d",&q,&L,&R,&d);
            for (int j=1;j<=N;j++) {
                if (j >= L && j <= R) {
                    B[j] = q - (A[j] + d);
                } else {
                    B[j] = q - A[j];
                }
            }
        }
        printf("%d\n",solve());
    }
}