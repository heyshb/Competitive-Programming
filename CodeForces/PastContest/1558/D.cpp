#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 1 << 19;
int n, m;
int x[200010], y[200010];
int fac[MAXN], ifac[MAXN];
const int MOD = 998244353;

int quick_pow(int a, int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

int tr[MAXN + 1];
int lowbit(int x){return x & -x;}
int getsum(int x) {
    int ret = 0;
    while(x) {
        ret += tr[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x, int y) {
    while(x <= MAXN) {
        tr[x] += y;
        x += lowbit(x);
    }
}

int query(int y) {
    int l = 0, r = MAXN;
    y--;
    while(l < r - 1) {
        int mid = (l + r) / 2;
        if (mid - l - tr[mid] >= y) {
            r = mid;
        } else {
            y -= (mid - l - tr[mid]);
            l = mid;
        }
    }
    return r + 1;
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        set<int> banned, ok;
        vector<int> clr;
        for (int i = m; i >= 1; i--) {
            int real_y = query(y[i]);
            printf("%d\n",real_y);
            add(real_y, 1);
            clr.push_back(real_y);
            if (banned.find(real_y) == banned.end()) ok.insert(real_y);
            if (real_y > 1) banned.insert(real_y - 1);
        }
        for (auto &t : clr) add(t, -1);
        int fuck = ok.size();
        printf("%d\n",fuck);
        //printf("?? %d %d\n",2 * n - 1 - fuck, n - 1 - fuck);
        printf("%d\n",C(2 * n - 1 - fuck, n - 1 - fuck));
    }
}