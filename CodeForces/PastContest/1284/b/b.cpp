#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int l[100010];
vector<int>v[100010];
int N;
const int INF = 1e9;
int mi[100010],ma[100010];
bool ac[100010];
int s[1000010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&l[i]);
        v[i].resize(l[i]);
        for (int j=0;j<l[i];j++) {
            scanf("%d",&v[i][j]);
        }
    }    
    int accnt = 0;
    LL ans = 0;
    vector<pii> nac;
    for (int i=1;i<=N;i++) {
        mi[i] = INF;
        ma[i] = -INF;
        ac[i] = false;
        for (int j=0;j<l[i];j++) {
            if (v[i][j] > mi[i]) {
                ac[i] = true;
            }
            mi[i] = min(mi[i], v[i][j]);
            ma[i] = max(ma[i], v[i][j]);
        }
        accnt += ac[i];
        if (!ac[i]) {
            nac.push_back(pii(mi[i], ma[i]));
        }
    }
    ans = 1LL * N * N - 1LL * (N - accnt) * (N - accnt);
    for (auto t:nac) {
        s[t.first]++;
    }
    for (int i=1;i<=1000000;i++) {
        s[i] += s[i-1];
    }
    for (auto t:nac) {
        if (t.second > 0) {
            ans += s[t.second - 1];
        }
    }
    printf("%lld\n",ans);
}