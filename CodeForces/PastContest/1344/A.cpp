#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        vector<int>a(n);
        for (int i = 0; i < n; i++) scanf("%d",&a[i]);
        bool ok = true;
        auto mo = [](int x, int MOD) {
            if (x >= 0) return x % MOD;
            x = -x;
            if (x % MOD == 0) return 0;
            return MOD - x % MOD;
        };
        set<int> to;
        for (int i = 0; i < n; i++) {
            int g = (i + mo(a[i], n)) % n;
            if (to.find(g) != to.end()) ok = false;
            to.insert(g);
        }
        puts(ok ? "YES" : "NO");
    }
}