#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
int d[21][50010];
const int MOD = 998244353;

int quick_pow(int a, int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int cnt[110];

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d",&d[i][j]);
        }
    }
    int fac = 1;
    for (int i = 1; i <= n; i++) fac = 1LL * fac * i % MOD;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n + 1; j++) cnt[j] = 0;
        for (int j = 1; j <= n; j++) {
            int need = n - d[j][i] + 2;
            cnt[need]++;
        }
        int way = 1;
        int remain = 0;
        for (int j = 1; j <= n; j++) {
            remain += cnt[j];
            way = 1LL * way * remain % MOD;
            remain--;
        }
        ans = (ans - way + fac) % MOD;
        if (ans < 0) ans += MOD;
    }
    ans = 1LL * ans * quick_pow(fac, MOD - 2) % MOD;
    printf("%d\n",ans);
}