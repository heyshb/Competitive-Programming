#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int T;
int N, M;
LL a[500010];
LL hsh[500010];
LL s1[500010], s2[500010];
LL sum1[500010], sum2[500010];
int d[500010];
std::mt19937 rnd(time(0));
map<pll,LL>sum;

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
        }
        for (int i=1;i<=N;i++) {
            hsh[i] = 0;
            s1[i] = rnd();
            s2[i] = rnd();
            sum1[i] = sum2[i] = 0;
        }
        for (int i=1;i<=M;i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            sum1[v] += s1[u];
            sum2[v] += s2[u];
        }
        sum.clear();
        for (int i=1;i<=N;i++) {
            //printf("fuck %d %lld %lld\n",i,sum1[i],sum2[i]);
            sum[pll(sum1[i], sum2[i])] += a[i];
        }
        LL ans = 0;
        for (auto t:sum) {
            if (t.first.first == 0 || t.first.second == 0) {
                continue;
            }
            ans = __gcd(ans, t.second);
        }
        printf("%lld\n",ans);
    }
}