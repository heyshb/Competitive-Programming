#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int>e[500010];
int col[500010];

bool OK;
void dfs(int x) {
    for (auto t:e[x]) {
        if (!col[t]) {
            col[t] = 3 - col[x];
            dfs(t);
        } else {
            if (col[x] == col[t]) {
                OK = false;
            }
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
    int ans = 0;
    int BIP = 0, NBIP = 0;
    for (int i=1;i<=N;i++) {
        if (!col[i]) {
            col[i] = 1;
            OK = true;
            dfs(i);
            if (OK) {
                BIP++;
            } else {
                NBIP++;
            }
        }
    }
    if (NBIP) {
        ans = NBIP + BIP - 1;
    } else {
        ans = BIP;
    }
    printf("%d\n",ans);
}