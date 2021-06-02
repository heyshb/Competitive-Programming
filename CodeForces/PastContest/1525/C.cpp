#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
pii p[300010];
vector<int> id[2];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        id[0].clear();
        id[1].clear();
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++) {
            scanf("%d",p[i].first);
            id[p[i].first % 2].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            char ss[5];
            scanf("%s", ss);
            if (ss[0] == 'L') p[i].second = -1;
            else p[i].second = 1;
        }
    }
}