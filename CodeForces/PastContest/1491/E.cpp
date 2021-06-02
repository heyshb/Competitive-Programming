#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, f[100], a[200010], FA[200010];
set<int>e[200010];
map<int,int>idx;
int SZ[220000];

vector<int>now;
void dfs(int x, int fa) {
    if (x%100==0)printf("dfs %d %d\n",x,fa);
    FA[x] = fa;
    now.push_back(x);
    SZ[x] = 1;
    for (auto &t: e[x]) {
        if (t != fa) {
            dfs(t, x);
            SZ[x] += SZ[t];
        }
    }
}

bool check(int x,int sz) {
    printf("check %d %d\n",x,sz);
    if (sz <= 3) return true;
    if (idx.find(sz) == idx.end()) return false;
    puts("??");
    int id = idx[sz];
    now.clear();
    dfs(x, 0);
    int sp = -1;
    for (auto &p: now) {
        if (SZ[p] == f[id - 1] || SZ[p] == f[id - 2]) {
            sp = p;
            break;
        }
    }
    //printf("%d %d %d\n",x,sp,SZ[sp]);
    if (sp == -1) return false;
    e[sp].erase(FA[sp]);
    e[FA[sp]].erase(sp);
    return check(sp, SZ[sp]) && check(FA[sp], sz - SZ[sp]);
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        int u, v;
        //scanf("%d%d",&u,&v);
        u = i;
        v = i + 1;
        e[u].insert(v);
        e[v].insert(u);
    }
    f[1] = f[0] = 1;
    idx[1] = 1;
    for (int i=2;i<=30;i++) {
        f[i] = f[i - 1] + f[i - 2];
        idx[f[i]] = i;
        printf("%d %d\n",i,f[i]);
    }
    puts(check(1, n) ? "YES" : "NO");
}