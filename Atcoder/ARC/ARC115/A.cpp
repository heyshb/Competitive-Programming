#include <bits/stdc++.h>

using namespace std;

int N, M;
char s[100010][25];
typedef long long LL;

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) {
        scanf("%s",s[i] + 1);
    }
    int cnt[4] = {0,0,0,0};
    LL ans = 0;
    for (int i=1;i<=N;i++) {
        int d = 0;
        for (int j=1;j<=M;j++) if (s[i][j] == '1') d ^= 1;
        ans += cnt[d];
        cnt[d]++;
    }
    ans = 1LL * N * (N - 1) / 2 - ans;
    printf("%lld\n",ans);
    /*
    if (M % 2 == 0) {
        for (int i=1;i<=N;i++) {
            int d = 0;
            for (int j=1;j<=M;j++) if (s[i][j] == '1') d ^= 1;
            ans += cnt[d];
            cnt[d]++;
        }
    } else {
        for (int i=1;i<=N;i++) {
            int d = 0;
            for (int j=1;j<=M;j++) if (s[i][j] == '1') d ^= 1;
        }
    }
    */
}