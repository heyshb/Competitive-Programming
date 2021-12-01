#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int v[100010];
char s[2][100010];
int sum[100010];
int last0[100010], last1[100010];
int dp[100010];

int mex(int L, int R) {
    int tot = (R - L + 1) * 2;
    int have0 = (sum[R] - sum[L - 1] != tot);
    int have1 = (sum[R] - sum[L - 1] != 0);
    if (!have0) return 0;
    if (have1) return 2;
    else return 1;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s",s[0] + 1);
        scanf("%s",s[1] + 1);
        for (int i = 1; i <= n; i++) {
            v[i] = (s[0][i] - '0') + (s[1][i] - '0') * 2;
        }
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + __builtin_popcount(v[i]);
        }
        last0[0] = last1[0] = -1;
        for (int i = 1; i <= n; i++) {
            last0[i] = last0[i - 1];
            last1[i] = last1[i - 1];
            if (__builtin_popcount(v[i]) != 0) last1[i] = i;
            if (__builtin_popcount(v[i]) != 2) last0[i] = i;
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            int L0 = last0[i], L1 = last1[i];
            if (L0 != -1) dp[i] = max(dp[i], dp[L0 - 1] + mex(L0, i));
            if (L1 != -1) dp[i] = max(dp[i], dp[L1 - 1] + mex(L1, i));
        }
        printf("%d\n",dp[n]);
    }
}