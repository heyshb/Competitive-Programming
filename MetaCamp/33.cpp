#include <bits/stdc++.h>

using namespace std;

int n, m, l;
int a[100010], b[100010], c[100010];
int prea[100010], suca[100010];
int preb[100010], sucb[100010];

bool calc_pre(int *val, int n, int *pre) {
    pre[0] = 0;
    int node = 1;
    for (int i = 1; i <= l; i++) {  
        while(node <= n && val[node] != c[i]) node++;
        if (node <= n) pre[i] = node; else return false;
        node++;
    }
    return true;
}

bool calc_suc(int *val, int n, int *suc) {
    suc[l + 1] = n + 1;
    int node = n;
    for (int i = l; i >= 1; i--) {  
        while(node >= 1 && val[node] != c[i]) node--;
        if (node >= 1) suc[i] = node; else return false;
        node--;
    }
    return true;
}

int vis[100010];
bool check(int L1, int R1, int L2, int R2) {
    //map<int, int> vis;
    bool ret = true;
    for (int i = L1; i <= R1; i++) vis[a[i]] = 1;
    for (int i = L2; i <= R2; i++) if (vis[b[i]]) ret = false;
    for (int i = L1; i <= R1; i++) vis[a[i]] = 0;
    return ret;
}

int main() {
    while(scanf("%d%d%d",&n,&m,&l) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1; i <= m; i++) scanf("%d",&b[i]);
        for (int i = 1; i <= l; i++) scanf("%d",&c[i]);
        int nodea = 1, nodeb = 1;
        bool ok = calc_pre(a, n, prea) && calc_pre(b, m, preb);
        calc_suc(a, n, suca);
        calc_suc(b, m, sucb);
        /*
        for (int i = 0; i <= l; i++) {
            printf("prea %d = %d\n",i,prea[i]);
            printf("preb %d = %d\n",i,preb[i]);
        }
        for (int i = 0; i <= l; i++) {
            printf("suca %d = %d\n",i,suca[i]);
            printf("sucb %d = %d\n",i,sucb[i]);
        }
        */
        for (int i = 0; i <= l; i++) {
            int L1, L2, R1, R2;
            L1 = prea[i] + 1;
            R1 = suca[i + 1] - 1;
            L2 = preb[i] + 1;
            R2 = sucb[i + 1] - 1;
            //printf("%d %d %d %d\n",L1,R1,L2,R2);
            ok &= check(L1, R1, L2, R2);
        }
        puts(ok ? "YES" : "NO");
    }
}