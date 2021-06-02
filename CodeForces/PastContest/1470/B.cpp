#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int M = 1000000;
map<vector<int>,int>cnt, cnt2;
int N;
int a[300010];
vector<int>fac[M + 10];
bool is_prime[M + 10];
vector<int>prime;
int mind[M + 10];

int main() {
    memset(is_prime, true, sizeof(is_prime));
    for (int i=2;i<=M;i++) {
        if (is_prime[i]) prime.push_back(i), mind[i] = i;
        for (auto t:prime) {
            if (i * t > M) break;
            is_prime[i * t] = false;
            mind[i * t] = t;
            if (i % t == 0) break;
        }
    }
    for (int i=2;i<=M;i++) {
        map<int,int>fuck;
        int tmp = i;
        while(tmp > 1) {
            fuck[mind[tmp]] += 1;
            tmp /= mind[tmp];
        }
        for (auto t:fuck) {
            if (t.second % 2 == 0) continue;
            fac[i].push_back(t.first);
        }
        sort(fac[i].begin(),fac[i].end());
        //if (i < 20) {printf("%d: ",i);for (auto t:fac[i]) printf("%d ",t);puts("");}
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        cnt.clear();
        cnt2.clear();
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            cnt[fac[a[i]]] += 1;
        }
        int ans0 = 0, ans1 = 0;
        for (auto &t:cnt) {
            ans0 = max(ans0, t.second);
            if (t.second % 2 == 0) {
                cnt2[fac[1]] += t.second;
            } else {
                cnt2[t.first] += t.second;
            }
        }
        for (auto &t:cnt2) {
            ans1 = max(ans1, t.second);
        }
        int Q;
        scanf("%d",&Q);
        while(Q--) {
            LL w;
            scanf("%lld",&w);
            if (w == 0) printf("%d\n",ans0);
            else printf("%d\n",ans1);
        }
    }
    
}