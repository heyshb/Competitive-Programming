#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;

vector<state> fuck(int x) {
    vector<state> ret;
    int B = int(sqrt(x)) + 1;
    for (int i = 1; i <= B; i++) {
        int L = x / i;
        int R = L + (x % i > 0);
        if (L > 0 && R > 0)
        ret.push_back((state){L, R, i - 1});   
    }
    for (int i = 1; i <= B; i++) {
        if (x % i == 0) {
            ret.push_back((state){i, i, x / i - 1});
        } else if (x % (i + 1) != 0) {
            int d = x / (i + 1) + 1;
            if (1LL * d * i < x && 1LL * d * (i + 1) > x && i > 0) {
                ret.push_back((state){i, i + 1, d - 1});
            }
        }
    }
    sort(ret.begin(), ret.end(), cmp2);
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        vector<state> lst, st;
        vector<int> dp, dp2;
        vector<int> ldp, ldp2;
        auto upd = [&](int &x, int y) {
            x += y;
            if (x >= MOD) x -= MOD;
        };
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            st = fuck(a[i]);
            //for (auto &t : st) printf("(%d,%d,%d)\n",t.L,t.R,t.d);
            dp.assign(st.size(), 0);
            dp2.assign(st.size(), 0);
            //printf("%d: %d\n",i,st.size());
            upd(dp.back(), 1);
            if (i < n) {
                int node = dp.size() - 1;
                for (int j = ldp.size() - 1; j >= 0; j--) {
                    while(st[node].R > lst[j].L) node--;
                    //printf("node = %d\n",node);
                    //printf("dp[%d][%d] = %d\n",i+1,j,dp[i+1][j]);
                    //printf("upd %d %d %lld\n",i,node,1LL * st[i][node].d * dp[i + 1][j] % MOD);
                    upd(ans, (1LL * st[node].d * ldp[j] + ldp2[j]) % MOD);
                    upd(dp[node], ldp[j]);
                    upd(dp2[node], (1LL * st[node].d * ldp[j] + ldp2[j]) % MOD);
                }
            }
            swap(dp, ldp);
            swap(dp2, ldp2);
            swap(st, lst);
        }
        printf("%d\n",ans);
    }
}