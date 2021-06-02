#include <bits/stdc++.h>

using namespace std;

int Cases;
int N, P, cnt[2000010];

int main() {
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        P = 0;
        int u, v, w;
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d%d%d",&u,&v,&w);
            P = max(P, max(u, v));
            if (w == 0) cnt[u]++;
            else cnt[v]++;
        }
        int ans = -1;
        for (int i=1;i<=P;i++) {
            if (cnt[i] == 0) ans = i;
        }
        for (int i=1;i<=P;i++) {
            cnt[i] = 0;
        }
        printf("Case #%d: %d\n",T, ans);
    }
}