#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, n, S[5010];
int R[5010];
int cnt[5010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        LL ans = 0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&S[i]);
            int val = S[i] - 1;
            for (int j=1;j<i-1;j++) {
                if (j + S[j] >= i) val--;
            }
            if (val > 0) ans += val;
        }
        printf("%lld\n",ans);
    }
}