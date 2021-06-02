#include <bits/stdc++.h>

using namespace std;

bool vis[2010];
vector<int>e[2010];
int N, M;
vector<int>cir;

void dfs(int x) {
    vis[x] = true;
    for (auto t:e[x]) {
        if (!vis[t]) {
            return dfs(t) + 1;
        }
    }
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vis[1] = true;
    for (auto t:e[1]) {
        if (!vis[t]) {
            cir.push_back(dfs(t));
        }
    }
}