#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
map<ppi, LL> mp;
int NN;

LL solve(int N, int M, int mi) {
    if (1LL * (1 + N) * N * mi > M) return 0;
    if (N == 0) return M / NN + 1;
    auto tmp = ppi(pii(N, M), mi);
    if (mp.find(tmp) != mp.end()) return mp[tmp];
    LL ret = 0;
    for (int i=mi;;i++) {
        LL nxt = solve(N - 1, M - 1LL * N * i, i);
        if (nxt == 0) break;
        ret = (ret + nxt) % MOD;
    }
    return mp[tmp] = ret;
}

int main() {
    int N, M;
    scanf("%d%d",&N, &M);
    NN = N;
    printf("%lld\n", (solve(N - 1, M, 0) - solve(N, M - 1, 0) + MOD) % MOD);
} 