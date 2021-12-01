#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int x[6010], y[6010];
int cnt[4][4];

int fuck(int dx,int dy) {
    if (dx % 2 == 0 && dy % 2 == 0) return 0;
    return 1;
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; j++) {
            if (j != i) cnt[abs((x[i] - x[j]) % 4)][abs((y[i] - y[j]) % 4)]++;
        }
        for (int dx1 = 0; dx1 < 4; dx1++) {
            for (int dy1 = 0; dy1 < 4; dy1++) {
                for (int dx2 = 0; dx2 < 4; dx2++) {
                    for (int dy2 = 0; dy2 < 4; dy2++) {
                        int cnt1 = cnt[dx1][dy1];
                        int cnt2 = cnt[dx2][dy2];
                        if (dx1 == dx2 && dy1 == dy2) cnt2--;
                    }
                }
            }
        }
    }
    ans /= 6;
    printf("%lld\n",ans);
}