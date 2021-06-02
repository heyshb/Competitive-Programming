#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
char S[200010];
int n, cnt[26];

int main() {
    scanf("%s", S + 1);
    n = strlen(S + 1);
    LL ans = 0;
    for (int i=n;i>=1;i--) {
        if (i > 0 && S[i] == S[i - 1]) {
            ans += (n - i - cnt[S[i] - 'a']);
            memset(cnt, 0, sizeof(cnt));
            cnt[S[i] - 'a'] = n - i;
        }
        cnt[S[i] - 'a']++;
    }
    printf("%lld\n",ans);
}