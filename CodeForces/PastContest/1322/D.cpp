#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
int l[4040], s[4040], c[4040];
LL f[2020][2020][2];

void upd(LL &x, LL y) {
    x = max(x, y);
}

const LL INF = 1e12;

int main() {
    scanf("%d%d",&N, &M);
    for (int i=1;i<=N;i++) {
        scanf("%d",&l[i]);
    }
    for (int i=1;i<=N;i++) {
        scanf("%d",&s[i]);
    }
    for (int i=1;i<=N+M;i++) {
        scanf("%d",&c[i]);
    }
    l[N + 1] = 0;
    f[N + 1][0][0] = 0;
    for (int i=0;i<=N+1;i++) {
        for (int j=0;j<=N+1;j++) {
            for (int k=0;k<=1;k++) {
                f[i][j][k] = -INF;
            }
        }
    }
    LL ans = -INF;
    for (int i=N+1;i>=1;i--) {
        for (int j=0;j<=N+1;j++) {
            for (int k=0;k<=1;k++) {
                if (f[i][j][k] <= -INF / 2) continue;
                LL nowv = f[i][j][k];
                LL tmp = j, level = l[i];
                LL tmpv = nowv;
                while(tmp) {
                    level++;
                    tmp /= 2;
                    tmpv += c[level] * tmp;
                }
                upd(ans, tmpv);
                for (int m=i-1;m>=1;m--) {
                    if (l[m] < l[i]) continue;
                    if (l[m] == l[i]) {
                        int nj, nk;
                        nk = k ^ 1;
                        nj = j + k;
                        upd(f[m][nj][nk], nowv - s[m] + (k == 1 ? c[l[m] + 1] : c[l[m]]));
                    } else {
                        LL tmp = j, level = l[i] + 1, tmpv = nowv;
                        while(level < l[m] && tmp) {
                            level++;
                            tmp /= 2;
                            tmpv += c[level] * tmp;
                        }
                        int nk = (tmp + 1) % 2;
                        int nj = (tmp + 1) / 2;
                        upd(f[m][nj][nk], tmpv - s[m] + )
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
}