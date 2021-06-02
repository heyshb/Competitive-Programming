#include <bits/stdc++.h>

using namespace std;

int n;
int a[200010], b[200010], c[200010], d[200010];
int ID = 0;
map<int,int> id;
map<int,set<int> >g;
vector<int>pos[200010];
int node[200010];

int tr[200010];
int lowbit(int x) {
    return x & -x;
}
int getsum(int x) {
    int ret = 0;
    while(x) {
        ret += tr[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x,int y) {
    while(x <= n) {
        tr[x] += y;
        x += lowbit(x);
    }
}

typedef long long LL;
int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        a[i] += i;
        c[i] = a[i];
        g[a[i]].insert(i);
        if (id.find(a[i]) == id.end()) {
            id[a[i]] = ++ID;
        }
        pos[id[a[i]]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d",&b[i]);
        b[i] += i;
        d[i] = b[i];
    }
    sort(c+1,c+n+1);
    sort(d+1,d+n+1);
    for (int i = 1; i <= n; i++) {
        if (c[i] != d[i]) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        int val = id[b[i]];
        b[i] = pos[val][node[val]++];
        //printf("%d\n",b[i]);
    }
    LL ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += getsum(b[i] - 1);
        add(b[i], 1);
    }
    printf("%lld\n",ans);
}