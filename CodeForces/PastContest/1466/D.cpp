#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int w[200010];
LL sum_d[200010], S2[200010];
int d[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&w[i]);
            d[i] = 0;
            sum_d[i] = 0;
        }
        multiset<int>s;
        LL ans = 0;
        for (int i=1;i<N;i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            d[u]++;
            d[v]++;
        }
        for (int i=1;i<=N;i++) {
            ans += w[i];
            for (int j=1;j<d[i];j++) s.insert(-w[i]);
        }
        for (int i=1;i<N;i++) {
            printf("%lld%c",ans," \n"[i==N-1]);
            if (!s.empty()) {
            auto tmp = s.begin();
            ans -= (*tmp);
            s.erase(tmp);
            }
        }
    }
}