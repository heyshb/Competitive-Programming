#include <bits/stdc++.h>

using namespace std;

int N;
vector<int>e[1000010];
typedef long long LL;
bool vis[1000010];
int d1[1000010], d2[1000010];

int find_far(int x, int *d) {
    queue<int>q;
    for (int i = 1; i <= N; i++) vis[i] = false;
    vis[x] = true;
    d[x] = 0;
    q.push(x);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = true;
        for (auto &t : e[now]) {
            if (!vis[t]) {
                d[t] = d[now] + 1;
                q.push(t);
            }
        }
    }
    int max_dis = -1, max_p;
    for (int i = 1; i <= N; i++) {
        if (d[i] > max_dis) {
            max_dis = d[i];
            max_p = i;
        }
    }
    return max_p;
}

int main() {
    int T;
    while(scanf("%d",&T) != EOF) {
        LL ans = 0;
        while(T--) {
            scanf("%d",&N);
            for (int i = 1; i <= N; i++) {
                e[i].clear();
            }
            for (int i = 2; i <= N; i++) {
                int u;
                scanf("%d",&u);
                e[u].push_back(i);
                e[i].push_back(u);
            }
            int p1 = find_far(1, d1);
            int p2 = find_far(p1, d1);
            //printf("%d %d\n",p1,p2);
            find_far(p2, d2);
            int tmp_ans = 0;
            for (int i = 1; i <= N; i++) {
                tmp_ans = max(tmp_ans, d1[i] + d2[i]);
            }
            ans += d1[p2] + tmp_ans;
        }
        printf("%lld\n",ans);
    }
}