#include <bits/stdc++.h>

using namespace std;

int N;
int st[1010], ed[1010], t[1010];
bool edge[1010][1010];
int col[1010];

bool intersect(int L1, int R1, int L2,int R2) {
    if (L1 > L2) {
        swap(L1, L2);
        swap(R1, R2);
    }
    return (L2 < R1);
}

bool dfs(int x) {
    bool ret = true;
    for (int i=1;i<=N;i++) {
        if (edge[x][i]) {
            if (!col[i]) {
                col[i] = 3 - col[x];
                ret &= dfs(i);
            } else {
                if (col[i] == col[x]) {
                    return false;
                }
            }
        }
    }
    return ret;
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d%d",&st[i], &ed[i]);
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (i == j) {
                    edge[i][j] = false;
                } else {
                    edge[i][j] = intersect(st[i], ed[i], st[j], ed[j]);
                }
            }
        }
        for (int i=1;i<=N;i++) {
            col[i] = 0;
        }
        bool ok = true;
        for (int i=1;i<=N;i++) {
            if (!col[i]) {
                col[i] = 1;
                ok &= dfs(i);
            }
        }
        printf("Case #%d: ", T);
        if (!ok) {
            puts("IMPOSSIBLE");
        } else {
            for (int i=1;i<=N;i++) {
                putchar(col[i] == 1 ? 'C' : 'J');
            } 
            puts("");
        }
    }
}