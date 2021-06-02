#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, A, B, F[500010], dep[500010];
vector<int>e[500010];
map<int, int> cntA[500010],cntB[500010];
double ans;

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        ans = 0;
        scanf("%d%d%d",&N,&A,&B);
        for (int i=1;i<=N;i++) {
            e[i].clear();
            cntA[i].clear();
            cntB[i].clear();
        }
        dep[1] = 0;
        for (int i=2;i<=N;i++) {
            int u;
            scanf("%d",&u);
            dep[i] = dep[u] + 1;
            e[u].push_back(i);
            e[i].push_back(u);
            F[i] = u;
        }
        for (int x=N;x>=1;x--) {
            cntA[x][dep[x]%A] = 1;
            cntB[x][dep[x]%B] = 1;
            for (auto t:e[x]) {
                if (t == F[x]) continue;
                if (cntA[x].size() < cntA[t].size()) swap(cntA[x], cntA[t]);
                if (cntB[x].size() < cntB[t].size()) swap(cntB[x], cntB[t]);
                for (auto p:cntA[t]) cntA[x][p.first] += p.second;
                for (auto p:cntB[t]) cntB[x][p.first] += p.second;
                cntA[t].clear();
                cntB[t].clear();
            }
            double p1 = 1.0 * cntA[x][dep[x] % A] / N;
            double p2 = 1.0 * cntB[x][dep[x] % B] / N;
            ans += 1 - (1 - p1) * (1 - p2);
        }
        printf("Case #%d: %.6lf\n",T,ans);
    }
}