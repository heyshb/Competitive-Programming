#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
map<pii,int> ecnt;
map<ppp,int> trid;


int N;
int v[100010][3];
vector<int>e[100010];
vector<int>ans,ans2;
int pre[100010],nxt[100010];
bool vis[100010];

void dfs(int x,int fa) {
    ans.push_back(x);
    for (auto t:e[x]) {
        if (t == fa || t == 1) continue;
        dfs(t, x);
    }
}

int getid(int mid) {
    int L = pre[mid], R = nxt[mid];
    pii p1 = pii(min(mid, L), max(mid, L));
    pii p2 = pii(min(mid, R), max(R, mid));
    if (p1 > p2) {
        swap(p1, p2);
    }
    ppp tri = ppp(p1, p2);
    if (trid.find(tri) == trid.end()) {
        return -1;
    } else {
        return trid[tri];
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        ecnt.clear();
        for (int i=1;i<=N;i++) {
            e[i].clear();
        }
        trid.clear();
        ans.clear();
        ans2.clear();
        for (int i=1;i<=N-2;i++) {
            vis[i] = false;
        }
        for (int i=1;i<=N-2;i++) {
            for (int j=0;j<3;j++) {
                scanf("%d",&v[i][j]);
            }
            sort(v[i],v[i]+3);
            pii e1, e2, e3;
            e1 = pii(v[i][0], v[i][1]);
            e2 = pii(v[i][0], v[i][2]);
            e3 = pii(v[i][1], v[i][2]);
            ecnt[e1]++;
            ecnt[e2]++;
            ecnt[e3]++;
            trid[ppp(min(e1, e2), max(e1, e2))] = i;
            trid[ppp(min(e1, e3), max(e1, e3))] = i;
            trid[ppp(min(e2, e3), max(e2, e3))] = i;
        }
        for (auto t:ecnt) {
            if (t.second == 1) {
                int u = t.first.first, v = t.first.second;
                e[u].push_back(v);
                e[v].push_back(u);
            }
        }
        dfs(1,0);
        for (int i=0;i<N;i++) {
            printf("%d%c",ans[i]," \n"[i==N-1]);
        }
        ans.push_back(1);
        for (int i=0;i<N;i++) {
            pre[ans[i + 1]] = ans[i];
            nxt[ans[i]] = ans[i + 1];
        }
        queue<int>cut;
        for (int i=1;i<=N;i++) {
            if (getid(i) != -1) {
                cut.push(i);
            }
        }
        while(!cut.empty()) {
            int mid = cut.front();
            cut.pop();
            int id = getid(mid);
            if (id == -1) {
                continue;
            }
            if (vis[id]) {
                continue;
            }
            vis[id] = true;
            ans2.push_back(id);
            nxt[pre[mid]] = nxt[mid];
            pre[nxt[mid]] = pre[mid];
            if (getid(pre[mid]) != -1) {
                cut.push(pre[mid]);
            }
            if (getid(nxt[mid]) != -1) {
                cut.push(nxt[mid]);
            }
        }
        assert(ans2.size() == N-2);
        for (int i=0;i<N-2;i++) {
            printf("%d%c",ans2[i]," \n"[i==N-3]);
        }
    }
}