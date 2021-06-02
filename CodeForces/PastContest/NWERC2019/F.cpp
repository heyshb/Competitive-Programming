#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

map<int,vector<int> > nei;
int ans[200010][3];
int fa[200010];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    int N, K;
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&K);
        int v;
        for (int j=1;j<=K;j++) {
            scanf("%d",&v);
            nei[v].push_back(i);
        }
    }
    for (int i=1;i<=N;i++) {
        fa[i] = i;
    }
    int com = N;
    int M = 0;
    for (auto t:nei) {
        auto &vec = t.second;
        int v0 = vec[0];
        for (int i=1;i<vec.size();i++) {
            if (find(vec[i]) != find(v0)) {
                fa[find(vec[i])] = find(v0);
                com--;
                M++;
                ans[M][0] = v0;
                ans[M][1] = vec[i];
                ans[M][2] = t.first;
            }
        }
    }
    if (com != 1) {
        puts("impossible");
        return 0;
    }
    for (int i=1;i<=M;i++) {
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
}