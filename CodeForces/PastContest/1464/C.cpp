#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char s[100010];
LL T;
LL fuck(char ch) {
    return 1LL << (ch - 'a');
}
LL cnt[26];
LL sum[26];
const LL INF = 1e18;

bool dfs(int idx, LL s) {
    if (idx == -1) return (s == 0);
    if (abs(s) > sum[idx]) return false;
    LL min_pos = INF, max_neg = -INF;
    for (LL i=0;i<=cnt[idx];i++) {
        LL sub = cnt[idx] - i;
        LL tmp = ((i - sub) << idx);
        if (s - tmp <= 0) max_neg = max(max_neg, s - tmp);
        else min_pos = min(min_pos, s - tmp);
        //if (dfs(idx - 1, s - tmp)) return true;
    }
    if (min_pos != INF && dfs(idx - 1, min_pos)) return true;
    if (max_neg != -INF && dfs(idx - 1, max_neg)) return true;
    return false;
}

int main() {
    scanf("%d%lld",&N,&T);
    scanf("%s", s + 1);
    T -= fuck(s[N]);
    T += fuck(s[N - 1]);
    for (int i=1;i<=N-2;i++) {
        cnt[s[i] - 'a']++;
        T -= 1LL << (s[i] - 'a');
    }
    for (int i=25;i>=0;i--) {
        while(cnt[i] && T + (1LL << (i + 1)) <= 0) {
            cnt[i]--;
            T += (1LL << (i + 1));
        }
    }
    puts(T == 0 ? "Yes" : "No");
}