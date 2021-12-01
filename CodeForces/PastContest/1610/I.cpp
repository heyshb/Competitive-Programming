#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string ans(n, '1');
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> sg(n), fa(n, -1), col(n, 0);
    col[0] = 1;
    function<void(int)> dfs;
    dfs = [&](int x) {
        sg[x] = 0;
        for (auto &t : e[x]) {
            if (t == fa[x]) continue;
            fa[t] = x;
            dfs(t);
            sg[x] ^= (sg[t] + 1);
        }
    };
    dfs(0);
    int rsg = sg[0];
    if (rsg == 0) ans[0] = '2';
    for (int i = 1; i < n; i++) {
        for (int p = i; col[p] == 0; p = fa[p]) {
            col[p] = 1;
            int delta = (sg[p] + 1) ^ (sg[p] ^ 1);
            rsg ^= delta; 
        }        
        if (rsg == 0) ans[i] = '2';
    }
    cout << ans << endl;
}