#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> e(n + 1), re(n + 1);
    vector<int> ind(n + 1, 0);
    while(m--) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        re[v].push_back(u);
        ind[v]++;
    }    
    vector<int> tp;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        tp.push_back(now);
        for (auto &t : e[now]) {
            if (--ind[t] == 0) {
                q.push(t);
            }
        }
    }
    if (tp.size() != n) return 0 * puts("-1");
    vector<int> pmin(n + 1), rmin(n + 1);
    for (int i = 1; i <= n; i++) {
        pmin[i] = rmin[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int now = tp[i];
        for (auto &t : e[now]) {
            pmin[t] = min(pmin[t], pmin[now]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int now = tp[i];
        for (auto &t : re[now]) {
            rmin[t] = min(rmin[t], rmin[now]);
        }
    }
    int ANS = 0;
    string ans(n, 'E');
    for (int i = 1; i <= n; i++) {
        if (pmin[i] == i && rmin[i] == i) {
            ANS++;
            ans[i - 1] = 'A';
        }
    }
    printf("%d\n",ANS);
    printf("%s\n",ans.c_str());
}
