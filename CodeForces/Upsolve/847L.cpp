#include <bits/stdc++.h>

using namespace std;

int N;
int sz[1010][1010];
int fa[1010];
int d[1010];
typedef pair<int,int> pii;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int merge(int x,int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return 0;
    }
    fa[x] = y;
    return 1;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        fa[i] = i;
    }
    for (int i=1;i<=N;i++) {
        int SZ,x;
        d[i] = 0;
        while(true) {
            d[i]++;
            scanf("%d:",&SZ);
            for (int j=1;j<SZ;j++) {
                scanf("%d,",&x);
                sz[i][x] = SZ;
            }
            scanf("%d",&x);
            sz[i][x] = SZ;
            char ch = getchar();
            if (ch == '\n' || ch == EOF) {
                break;
            }
        }
    }
    bool ok = true;
    int com = N;
    vector<pii> ans;
    for (int i=1;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            if (sz[i][j] + sz[j][i] == N) {
                d[i]--;
                d[j]--;
                ans.push_back(pii(i,j));
                if (!merge(i,j)) {
                    ok = false;
                }
                com--;
            }
        }
    }
    if (com != 1) {
        ok = false;
    }
    for (int i=1;i<=N;i++) {
        if (d[i] != 0) {
            ok = false;
        }
    }
    if (ok) {
        printf("%d\n",N-1);
        assert(ans.size() == N - 1);
        for (int i=0;i<N-1;i++) {
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    } else {
        puts("-1");
    }
}