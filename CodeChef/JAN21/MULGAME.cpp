#include <bits/stdc++.h>

using namespace std;

int d[200010];
int N, Q, M;
int a[200010];
int cnt[510][510];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&Q,&M);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        int B = int(sqrt(M)) + 1;
        //int B = 1;
        for (int i=0;i<=B;i++) {
            for (int j=0;j<=B;j++) {
                cnt[i][j] = 0;
            }
        }
        for (int i=0;i<=M;i++) {
            d[i] = 0;
        } 
        while(Q--) {
            int L, R;
            scanf("%d%d",&L,&R);
            L = a[L], R = a[R];
            int period = L + R;
            if (period > B) {
                int p = 0;
                while(p <= M) {
                    int st = p + L;
                    if (st <= M) {
                        int en = st + R - 1;
                        en = min(en, M);
                        d[st]++;
                        d[en + 1]--;
                    }
                    p += period;
                }
            } else {
                for (int i=L;i<period;i++) {
                    cnt[period][i]++;
                }
            }
        }
        int ans = 0;
        int S = 0;
        for (int i=1;i<=M;i++) {
            S += d[i];
            int tmp = S;
            for (int j=1;j<=B;j++) {
                tmp += cnt[j][i%j];
            }
            ans = max(ans, tmp);
        }
        printf("%d\n",ans);
    }
}