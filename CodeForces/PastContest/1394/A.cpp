#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, D, M;

int main() {
    scanf("%d%d%d",&N,&D,&M);
    vector<LL> v1, v2;
    for (int i=1;i<=N;i++) {
        int tmp;
        scanf("%d",&tmp);
        if (tmp <= M) v1.push_back(tmp);
        else v2.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v2.begin(), v2.end());
    int N1 = v1.size(), N2 = v2.size();
    for (int i=1;i<N1;i++) v1[i] += v1[i - 1];
    for (int i=1;i<N2;i++) v2[i] += v2[i - 1];
    LL ans = N1 ? v1[N1 - 1] : 0;
    for (int i=1;i<=N2;i++) {
        LL need = 1LL * (i - 1) * (D + 1) + 1;
        if (need > N) break;
        LL fun = v2[i - 1];
        LL rest = N - need;
        if (rest && N1 > 0) fun += v1[min(rest - 1, LL(N1 - 1))];
        ans = max(ans, fun);
    }
    printf("%lld\n",ans);
}