#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M;
int k[300010], c[300010];
int cnt[300010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=M;i++) cnt[i] = 0;
        LL ans = 0;
        for (int i=1;i<=N;i++) scanf("%d",&k[i]);
        for (int i=1;i<=M;i++) scanf("%d",&c[i]);
        sort(k+1,k+N+1);
        for (int i=1;i<=N;i++) ans += c[k[i]];
        int mk = 0;
        int mi = 1e9;
        for (int K=1;K<=min(N,M);K++) {
            mi = min(mi, k[N-(K-1)] + (K-1));
            if (mi < K) break;
            mk = K;
        }
        for (int i=0;i<mk;i++) {
            if (k[N-i] < i+1) break;
            ans -= c[k[N-i]];
            ans += c[i+1];
        }
        printf("%lld\n", ans);
    }
}