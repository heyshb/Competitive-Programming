#include <bits/stdc++.h>
#define x1 sdzjxl
#define x2 zsxcln
#define y1 zaaaaa
#define y2 zxcnvs
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, k;
int x[100010], y[100010];
bool vis[100010];

int check(int x1, int y1, int x2, int y2) {
    if (x1 > y1) swap(x1, y1);
    int p1 = (x2 > x1 && x2 < y1);
    int p2 = (y2 > x1 && y2 < y1);
    return p1 != p2;
}

int main() {
    int T;
    scanf("%d",&T);    
    while(T--) {
        scanf("%d%d",&n,&k);
        for (int i = 1; i <= 2 * n; i++) {
            vis[i] = false;
        }
        for (int i = 1; i <= k; i++) {
            scanf("%d%d",&x[i],&y[i]);
            vis[x[i]] = vis[y[i]] = true;
        }
        vector<int>d;
        for (int i = 1; i <= 2 * n; i++) {
            if (!vis[i]) d.push_back(i);
        }
        sort(d.begin(), d.end());
        int dd = n - k;
        for (int i = 0; i < dd; i++) {
            k++;
            x[k] = d[i];
            y[k] = d[i + dd];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += check(x[i],y[i],x[j],y[j]);
            }
        }
        printf("%d\n",ans);
    }
}