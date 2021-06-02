#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, A, B;
vector<int>e[500010];
map<int, int> cntA[500010],cntB[500010];
double ans;

/*
void dfs(int x,int fa,int dep) {
    cntA[x][dep%A] = 1;
    cntB[x][dep%B] = 1;
    for (auto t:e[x]) {
        if (t == fa) continue;
        dfs(t, x, dep + 1);
        if (cntA[x].size() < cntA[t].size()) swap(cntA[x], cntA[t]);
        if (cntB[x].size() < cntB[t].size()) swap(cntB[x], cntB[t]);
        for (auto p:cntA[t]) cntA[x][p.first] += p.second;
        for (auto p:cntB[t]) cntB[x][p.first] += p.second;
        cntA[t].clear();
        cntB[t].clear();
    }
    double p1 = 1.0 * cntA[x][dep % A] / N;
    double p2 = 1.0 * cntB[x][dep % B] / N;
    ans += 1 - (1 - p1) * (1 - p2);
}
*/

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
        for (int i=2;i<=N;i++) {
            int u;
            scanf("%d",&u);
            e[u].push_back(i);
            e[i].push_back(u);
        }
        dfs(1, 0, 0);
        printf("Case #%d: %.6lf\n",T,ans);
    }
}