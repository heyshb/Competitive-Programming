#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
bool vis[300010];
int N, M;
vector<int>e[300010];
int id[300010];
int col[300010];
int qq[300010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++) e[i].clear(), id[i] = 0, col[i] = 0;
        for (int i=1;i<=M;i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int nowid = 1;
        queue<int>q;
        q.push(1);
        id[1] = 1;
        qq[1] = 1;
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto t:e[now]) {
                if (id[t] == 0) {
                    id[t] = ++nowid;
                    q.push(t);
                }
            }
        }
        if (nowid != N) {
            puts("NO");
            continue;
        }
        vector<int>ans;
        for (int i=1;i<=N;i++) {
            qq[id[i]] = i;
            vis[i] = false;
        }
        for (int i=1;i<=N;i++) {
            int now = qq[i];
            vis[now] = true;
            bool black_neighbor = false;
            for (auto t:e[now]) {
                black_neighbor |= (vis[t] && col[t]);
            }
            col[now] = int(!black_neighbor);
            if (col[now]) ans.push_back(now);
        }
        puts("YES");
        printf("%d\n",ans.size());
        for (int i=0;i<ans.size();i++) {
            printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
        }
    }
}