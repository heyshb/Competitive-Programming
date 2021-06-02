#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, n;
map<int,vector<int> > mp;

int main() {
    scanf("%d",&T);
    while(T--) {
        mp.clear();
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d",&tmp);
            mp[tmp].push_back(i);
        }
        LL ans = 0;
        for (auto &t : mp) {
            auto &p = t.second;
            LL sum = 0;
            for (auto &tt : p) {
                ans += (n - tt + 1) * sum;
                sum += tt;
            }
        }
        printf("%lld\n",ans);
    }    
}