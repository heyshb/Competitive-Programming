#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
vector<pii>e[1010];
int N, M;
vector<int>rk[1010];
int L[1010],R[1010],d[1100];
int ans[1010], nowmax;
bool vis[1010];
const int INF = 1e7;

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        nowmax = 0;
        scanf("%d%d",&N,&M);
        for (int i=2;i<=N;i++)scanf("%d",&d[i]);
        d[1] = 0;
        for (int i=1;i<=M;i++) {
            scanf("%d%d",&L[i],&R[i]);
        }
        for (int i=1;i<=N;i++) {
            ans[i] = abs(d[L[i]] - d[R[i]]);
        }
        for (int i=1;i<=M;i++) {
            if (!ans[i]) ans[i] = 1;
        }
        printf("Case #%d:",T);
        for (int i=1;i<=M;i++) printf(" %d",ans[i]);
        puts("");
    }
}

/*
1
6 9
-1 -1 -3 15 20
1 2
1 3
2 3
2 4
2 5
3 5
3 6
4 5
5 6
*/