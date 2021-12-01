#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m, a[400010];
string s[400010];
set<int> st[400010];
vector<int> e[400010];
int time_tag = 0;
int dfn[400010], low[400010];
bool ins[400010];
int top, stk[400010];
int ind[400010];
int SCC_ID = 0;
int scc_id[400010];

void dfs(int x) {
    ins[x] = true;
    stk[++top] = x;
    dfn[x] = low[x] = ++time_tag;
    for (auto &t : e[x]) {
        if (!dfn[t]) {
            dfs(t);
            low[x] = min(low[x], low[t]);
        } else if (ins[t]) {
            low[x] = min(low[x], dfn[t]);
        }
    }
    if (low[x] == dfn[x]) {
        int now;
        SCC_ID++;
        do {
            now = stk[top--];
            scc_id[now] = SCC_ID;
            ins[now] = false;
        } while(now != x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }   
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<vector<int> >id(n, vector<int>(m, 0)); 
    int id_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                st[j].insert(i);
                id[i][j] = ++id_cnt;
                //printf("id[%d][%d] = %d\n",i,j,id[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '#') continue;
            int ID = id[i][j];
            // down
            auto down_it = st[j].upper_bound(i);
            if (down_it != st[j].end()) {
                int down = (*down_it);
                e[ID].push_back(id[down][j]);
            }
            // up
            if (i > 0 && s[i - 1][j] == '#') {
                e[ID].push_back(id[i - 1][j]);
            }
            // left
            if (j > 0) {
                auto left_it = st[j - 1].lower_bound(i);
                if (left_it != st[j - 1].end()) {
                    int left = (*left_it);
                    e[ID].push_back(id[left][j - 1]);
                }
            }
            // right
            if (j < m - 1) {
                auto right_it = st[j + 1].lower_bound(i);
                if (right_it != st[j + 1].end()) {
                    int right = (*right_it);
                    e[ID].push_back(id[right][j + 1]);
                }
            }
        }
    }
    /*
    for (int i = 1; i <= id_cnt; i++) {
        for (auto &t : e[i]) printf("%d-->%d\n",i,t);
    }
    */
    
    for (int i = 1; i <= id_cnt; i++) {
        if (!dfn[i]) dfs(i);
    }
    for (int i = 1; i <= id_cnt; i++) {
        for (auto &t : e[i]) {
            if (scc_id[i] == scc_id[t]) continue;
            ind[scc_id[t]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= SCC_ID; i++) {
        if (!ind[i]) ans++;
    }
    cout << ans << endl;
}