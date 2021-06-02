#include <bits/stdc++.h>

using namespace std;

int T;
int N, p[1000010];
bool vis[1000010];
int cnt[3], sum[3];
const int MOD = 1e9 + 7;

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int solve() {
    int s = cnt[0] + cnt[1] + cnt[2];
    int ret = 1e9;
    if (N % 3 == 0) {
        ret = (sum[0] / 3 - cnt[0]) + ((sum[1] - cnt[1]) / 3 - cnt[1]) + ((sum[2] - cnt[2] * 2) / 3 - cnt[2]);
        int match = min(cnt[1], cnt[2]);
        ret += match;
        cnt[1] -= match;
        cnt[2] -= match;
        assert(cnt[1] % 3 == 0);
        ret += cnt[1] / 3 * 2;
        assert(cnt[2] % 3 == 0);
        ret += cnt[2] / 3 * 2;
        return ret;
    }
    if (N % 3 == 1) {
        
    }
    if (N % 3 == 2) {
        if (cnt[2]) {
            ret += (sum[0] / 3 - cnt[0]) + ((sum[1] - cnt[1]) / 3 - cnt[1]) + ((sum[2] - cnt[2] * 2) / 3 - cnt[2]);
        } else {

        }
    }
}

int dfs(int x) {
    vis[x] = true;
    if (vis[p[x]]) return 1;
    return dfs(p[x]) + 1;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&p[i]);
        }
        int ans1, ans2;
        if (N <= 4) ans1 = N;
        else {
            if (N % 3 == 0) ans1 = quick_pow(3, N / 3);
            if (N % 3 == 1) ans1 = 4LL * quick_pow(3, N / 3 - 1) % MOD;
            if (N % 3 == 2) ans1 = 2LL * quick_pow(3, N / 3) % MOD;
        } 
        for (int i=1;i<=N;i++) {
            vis[i] = false;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i=1;i<=N;i++) {
            if (!vis[i]) {
                int len = dfs(i);
                cnt[len % 3]++;
                sum[len % 3] += len;
            }
        }
        ans2 = solve();
        printf("%d %d\n",ans1, ans2);
    }
}