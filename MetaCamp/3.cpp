#include <bits/stdc++.h>

using namespace std;

int n, m, l;
int a[100010], b[100010], c[100010];

bool check() {
    int nodea = 1, nodeb = 1;
    bool ok = true;
    int a1 = 0;
    int b1 = 0;
    for (int i = 1; i <= l; i++) {
        while(nodea <= n && a[nodea] != c[i]) nodea++;
        if (nodea > n) ok = false;
        nodea++;
        while(nodeb <= m && b[nodeb] != c[i]) nodeb++;
        if (nodeb > m) ok = false;
        nodeb++;
        if (i == 1) a1 = nodea - 1, b1 = nodeb - 1;
    }
    map<int, int> vis;
    for (int i = nodea; i <= n; i++) vis[a[i]] = 1;
    for (int i = nodeb; i <= m; i++) if (vis[b[i]]) ok = false;
    vis.clear();
    for (int i = 1; i < a1; i++) vis[a[i]] = 1;
    for (int i = 1; i < b1; i++) if (vis[b[i]]) ok = false;
    return ok;
}


int main() {
    while(scanf("%d%d%d",&n,&m,&l) != EOF) {
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
        for (int i = 1; i <= m; i++) scanf("%d",&b[i]);
        for (int i = 1; i <= l; i++) scanf("%d",&c[i]);
        bool ok = check();
        reverse(a + 1, a + n + 1);
        reverse(b + 1, b + m + 1);
        reverse(c + 1, c + l + 1);
        ok &= check();
        puts(ok ? "YES" : "NO");
    }
}