#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, a[300010];
LL s[300010], ds[300010];
LL OddMinusEven[300010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = a[i] + (i - 2 > 0 ? s[i - 2] : 0);
            //printf("s[%d] = %lld\n",i,s[i]);
        }
        for (int i = 1; i <= n; i++) {
            ds[i] = s[i] - s[i - 1];
            //printf("ds[%d] = %lld\n",i,ds[i]);
        }
        // Odd - Even
        unordered_map<LL, vector<int> > idx;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                OddMinusEven[i] = a[i] - ds[i - 1];
            } else {
                OddMinusEven[i] = ds[i - 1] - a[i];
            }
            idx[OddMinusEven[i]].push_back(i);
            //printf("odd minus even %d = %lld\n",i,OddMinusEven[i]);
        }
        ds[n + 1] = -1e18;
        vector<int> stk[2];
        vector<int> node = {0, 0};
        stk[0].push_back(n + 1);
        stk[1].push_back(n + 1);
        auto query = [&](LL x, int min_idx, int first_die) {
            if (idx.find(x) == idx.end()) return 0;
            auto &vec = idx[x];
            int ok = lower_bound(vec.begin(), vec.end(), first_die) - vec.begin();
            int too_small = lower_bound(vec.begin(), vec.end(), min_idx) - vec.begin();
            return max(ok - too_small, 0);
        };
        LL bias[2] = {0, 0};
        for (int i = 1; i <= n; i++) {
            bias[i % 2] += a[i];
        }
        for (int i = n; i >= 1; i--) {
            bias[i % 2] -= a[i];
            int first_die = n + 1;
            for (int j = 0; j <= 1; j++) {
                int L = 0, R = stk[j].size() - 1;
                if (ds[stk[j][R]] - bias[j] + bias[j ^ 1] < 0) {
                    first_die = min(first_die, stk[j][R]);
                } else {
                    while(L < R - 1) {
                        int mid = (L + R) / 2;
                        if (ds[stk[j][mid]] - bias[j] + bias[j ^ 1] < 0) {
                            L = mid;
                        } else {
                            R = mid;
                        }
                    }
                    first_die = min(first_die, stk[j][L]);
                }
            }
            while(ds[i] <= ds[stk[i % 2].back()]) stk[i % 2].pop_back();
            stk[i % 2].push_back(i);
            ans += query(bias[1] - bias[0], i, first_die);
        }
        printf("%lld\n",ans);
    }    
}