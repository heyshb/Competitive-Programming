#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K;
vector<int>e[200010];
int far_uncov[200010], near_key[200100], sum[200010];
int X;
const int INF = 1e9;

void dfs(int x,int p) {
    int fa = -INF, ne = INF;
    for (auto &t: e[x]) {
        if (t == p) continue;
        dfs(t, x);
        if (near_key[t] != -1) ne = min(ne, near_key[t] + 1);
        if (far_uncov[t] != -1) fa = max(fa, far_uncov[t] + 1);
        sum[x] += sum[t];
    }
    //if (x == 1) printf("? %d %d\n",fa,ne);
    if (ne == INF) fa = max(0, fa);
    if (ne != INF && (fa == -INF || fa + ne <= X)) {
        far_uncov[x] = -1;
        near_key[x] = ne;
    } else if (fa == X || ne == X) {
        far_uncov[x] = -1;
        near_key[x] = 0;
        sum[x]++;
    } else {
        far_uncov[x] = fa;
        near_key[x] = ne;
    }

}

bool check() { 
    for (int i=1;i<=N;i++) sum[i] = 0, far_uncov[i] = -1, near_key[i] = -1;
    dfs(1, 0);
    if (sum[1] == 0) sum[1]++;
    return sum[1] <= K;
}

int main() {
    scanf("%d%d",&N,&K);
    for (int i=1;i<N;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    /*
    X = 2;
    check();
    for (int i=1;i<=N;i++) {
        printf("%d: %d %d %d\n",i,far_uncov[i],near_key[i],sum[i]);
    }
    return 0;
    */
    int L = 0, R = N;
    while(L < R - 1) {
        int mid = (L + R) / 2;
        X = mid;
        if (check()) {
            R = mid;
        } else {
            L = mid;
        }
    }
    printf("%d\n",R);
}