#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
vector<int> e[200010];
int fa[200010];
int d[200010];
int ch_cnt[200010], ch_leaf[200010];

void dfs(int x) {
    for (auto &t : e[x]) {
        if (t != fa[x]) {
            ch_cnt[x]++;
            fa[t] = x;
            dfs(t);
            if (ch_cnt[t] == 0) ch_leaf[x]++;
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            ch_cnt[i] = 0;
            ch_leaf[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d",&u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        fa[1] = 0;
        dfs(1);
        //puts("?");
        queue<int> q;
        int leaf = 0;
        int bud = 0;
        for (int i = 1; i <= n; i++) {
            if (!ch_cnt[i]) leaf++;
            if (ch_cnt[i] && ch_leaf[i] == ch_cnt[i]) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int now = q.front();
            //printf("bud %d\n",now);
            if (now) bud++;
            q.pop();
            int f = fa[now];
            int ff = fa[f];
            ch_cnt[f]--;
            if (ch_cnt[f] == 0) {
                if (f == 1) {
                    q.push(1);
                    leaf++;
                    continue;
                }
                leaf++;
                ch_leaf[ff]++;
                if (ch_cnt[ff] == ch_leaf[ff]) q.push(ff);
            } else {
                if (ch_cnt[f] == ch_leaf[f]) q.push(f);
            }
        }
        //printf("%d %d\n",leaf, bud);
        printf("%d\n",leaf-bud+1);
    }
}