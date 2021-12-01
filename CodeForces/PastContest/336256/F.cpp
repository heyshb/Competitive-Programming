#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int n;

LL ans = 0;
int m;
int bound;
vector<int>ret = {0};
int done = 0;

void dfs(int dep, int cnt0, int cnt1) {
    if (cnt0 > bound || cnt1 > bound) return;
    //printf("dfs %d %d %d %d\n",dep,cnt0,cnt1,bound);
    if (dep == n) {
        for (int i = 1; i <= n; i++) if (ret[i] == ret[i - 1]) printf("b"); else printf("r");
        puts("");
        done++;
        return;
    }
    int now = ret[dep];
    if (now == 0) {
        ret.push_back(0);
        dfs(dep + 1, cnt0 + 1, cnt1);
        ret.pop_back();
        if (done == 100) return;
        ret.push_back(1);
        dfs(dep + 1, cnt0, cnt1 + 1);
        ret.pop_back();
        if (done == 100) return;
    } else {
        ret.push_back(1);
        dfs(dep + 1, cnt0, cnt1 + 1);
        ret.pop_back();
        if (done == 100) return;
        ret.push_back(0);
        dfs(dep + 1, cnt0 + 1, cnt1);
        ret.pop_back();
        if (done == 100) return;
    }
}

int main() {
    scanf("%d",&n);
    m = n + 1;
    bound = m - m / 2;
    printf("%lld\n",1LL * (m / 2) * (m - m / 2));
    dfs(0, 1, 0);
}