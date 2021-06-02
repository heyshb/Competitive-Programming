#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K;
const int MOD = 998244353;
int p[200010];

int main() {
    scanf("%d%d",&N, &K);
    vector<int> pos;
    LL ans1 = 0, ans2 = 1;
    for (int i=1;i<=N;i++) {
        scanf("%d",&p[i]);
        if (p[i] >= N - K + 1) {
            pos.push_back(i);
            ans1 += p[i];
        }
    }
    for (int i=0;i<pos.size()-1;i++) {
        ans2 = ans2 * (pos[i + 1] - pos[i]) % MOD;
    }
    printf("%lld %lld\n",ans1, ans2);
}