#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
int fa[1000010];
int mi[1000010], ma[1000010];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    ma[u] = max(ma[u], ma[v]);
    mi[u] = min(mi[u], mi[v]);
    fa[v] = u;
}

set<pii> st;
map<pii, set<pii>> ch; 

void addedge(int u, int v) {
    vector<pii> contain_u, contain_v;
    pii now(0, n + 1);
    pii fuck = st.upper_bound(pii(u, 1e9));
    if (fuck != st.begin()) {
        fuck--;
        while(true) {

            contain_u.push_back(*fuck);
            if (fuck == )
        }
    }
    merge(u, v);
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        mi[i] = i;
        ma[i] = i;
    }
    string ans = "";
    ch[pii(0, n + 1)].clear();
    while(m--) {
        int e, u, v;
        scanf("%d%d%d",&e,&u,&v);
        if (u > v) swap(u, v);
        if (e == 1) {
            addedge(u, v);
        } else {
            ans.push_back('0' + (find(u) == find(v)));
        }
    }
    printf("%s\n",ans.c_str());
}