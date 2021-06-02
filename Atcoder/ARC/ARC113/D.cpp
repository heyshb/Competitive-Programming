#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;
int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int s1[200010], s2[200100];

int main() {
    int N, M, K;
    scanf("%d%d%d",&N,&M,&K);
    if (N == 1 || M == 1) {
        printf("%d\n",quick_pow(K, N + M - 1));
        return 0;
    }
    int ans = 0;
    for (int i=1;i<=K;i++) {
        s1[i] = quick_pow(i, N);
        s2[i] = quick_pow(K - i + 1, M);
    }
    for (int i=K;i>1;i--) {
        s1[i] -= s1[i - 1];
        if (s1[i] < 0) s1[i] += MOD;
    }
    for (int i=1;i<=K;i++) {
        //printf("%d %d %d\n",i,s1[i],s2[i]);
        ans += 1LL * s1[i] * s2[i] % MOD;
        ans %= MOD;
    }
    printf("%d\n",ans);
}