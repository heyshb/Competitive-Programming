#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K, L;
int a[1000010];

LL solve() {
    LL ans = 0;
    int cnt = 0;
    for (int i=K;i<=N;i++) {
        int need;
        if ((K - i) % K == 0) {
            need = L - K + 1;
        } else {
            need = 1;
        }
        need = min(need, N - L + 1 - cnt);
        ans += 1LL * need * a[i];
        cnt += need;
        if (cnt >= N - L + 1) break;
    }
    return ans;
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    while(Cases--) {
        scanf("%d%d%d",&N,&L,&K);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+N+1);
        reverse(a+1,a+N+1);
        LL ans1 = solve();
        reverse(a+1,a+N+1);
        for (int i=1;i<=N;i++) {
            a[i] = -a[i];
        }
        K = L - K + 1;
        LL ans2 = -solve();
        printf("%lld %lld\n",ans1,ans2);
    }    
}