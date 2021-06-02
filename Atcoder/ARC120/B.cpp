#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MOD = 998244353;
int ans = 0;
char s[510][510];
int cnt[3];

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    int ans = 1;
    for (int sum = 2; sum <= n + m; sum++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; j++) {
            int k = sum - j;
            if (k < 0 || k > m) continue;
            if (s[j][k] == 'R') cnt[0]++;
            if (s[j][k] == 'B') cnt[1]++;
            if (s[j][k] == '.') cnt[2]++;
        }
        if (cnt[0] && cnt[1]) {
            puts("0");
            return 0;
        }
        if (cnt[0] == 0 && cnt[1] == 0 && cnt[2]) ans = ans * 2 % MOD;
    }
    printf("%d\n",ans);
}