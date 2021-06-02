#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int N, M;
LL a[500010];
int d[500010];
vector<int>e[500010];
bool vis[500010];
std::mt19937 rnd(time(0));

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
        }
        for (int i=1;i<=N;i++) {
            e[i].clear();
        }
        for (int i=1;i<=M;i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
        }
        LL ans = 0;
        for (int tt=1;tt<=100;tt++) {
            for (int i=1;i<=N;i++) {
                vis[i] = false;
            }
            for (int i=1;i<=N;i++) {
                if (e[i].empty()) {
                    continue;
                }
                if (rnd() % 2 == 0) {
                    for (auto t:e[i]) {
                        vis[t] = true;
                    }
                }
            }
            LL s = 0;
            for (int i=1;i<=N;i++) {
                if (vis[i]) {
                    s += a[i];
                }
            }
            ans = __gcd(ans, s);
        }
        printf("%lld\n",ans);
    }
}