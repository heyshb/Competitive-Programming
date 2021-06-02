#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 100010;
const int MAXM = 1000010;
int N,M,Q;
int MM, head[MAXN], en[MAXM], nxt[MAXM];
int dfn[MAXN], low[MAXN];
int time_tag = 0;

void addedge(int u,int v) {
    MM++;
    en[MM] = v;
    nxt[MM] = head[u];
    head[u] = MM;
}

int main() {
    scanf("%d%d%d",&N,&M,&Q);
    MM = 0;
    for (int i=1;i<=M;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u, v);
        addedge(v, u);
    }
    time_tag = 0;

}