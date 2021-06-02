#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;
int N,b[MAXN],c[MAXN],d[MAXN];
vector<int>e[MAXN];
vector<int>v;
int fa[MAXN];
int g[MAXN], en[MAXN], vis[MAXN], nxt[MAXN];
int cnt = 1;
vector<int>ans;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    fa[x] = y;
    return 1;
}

void addedge(int x,int y) {
    cnt++;
    en[cnt] = y;
    nxt[cnt] = g[x];
    g[x] = cnt;
}

void dfs(int x) {
    for (int &i=g[x];i;) {
        if (vis[i]) {
            i = nxt[i];
            continue;
        }
        vis[i] = vis[i^1] = 1;
        int tmp = en[i];
        dfs(en[i]);
        ans.push_back(tmp);
    }
}

int main() {
    scanf("%d",&N);
    N--;
    for (int i=1;i<=N;i++) {
        scanf("%d",&b[i]);
        v.push_back(b[i]);
    }
    for (int i=1;i<=N;i++) {
        scanf("%d",&c[i]);
        v.push_back(c[i]);
        if (c[i] < b[i]) {
            return 0 * puts("-1");
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int M = v.size();
    int com = M;
    for (int i=0;i<M;i++) {
        fa[i] = i;
    }
    for (int i=1;i<=N;i++) {
        b[i] = lower_bound(v.begin(),v.end(), b[i]) - v.begin();
        c[i] = lower_bound(v.begin(),v.end(), c[i]) - v.begin();
        //printf("%d %d\n",b[i],c[i]);
        d[b[i]]++;
        d[c[i]]++;
        addedge(b[i],c[i]);
        addedge(c[i],b[i]);
        com -= merge(b[i], c[i]);
    }
    if (com != 1) {
        return 0 * puts("-1");
    }
    int S = -1, T = -1;
    for (int i=0;i<M;i++) {
        if (d[i] % 2 == 1) {
            if (S == -1) {
                S = i;
            } else if (T == -1) {
                T = i;
            } else {
                return 0 * puts("-1");
            }
        }
    }
    if (S == -1) {
        S = 0;
    }
    dfs(S);
    ans.push_back(S);

    for (int j=0;j<ans.size();j++) {
        printf("%d%c",v[ans[j]]," \n"[j==ans.size()-1]);
    }
}