#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
LL a[200010];
LL s[200010][3];
const int MOD = 998244353;
void upd(LL &x, LL y) {
    x = (x + y) % MOD;
    //printf("ret = %lld\n",x);
}

LL solve(LL *b, int m, LL bias) {
    //printf("solve %lld\n",bias);
    s[0][0] = s[0][1] = s[0][2] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++) {
            s[i][j] = s[i - 1][j];
        }
        s[i][2] += b[i]; 
        s[i][i % 2] += b[i]; 
        //printf("%lld %lld %lld\n",s[i][0],s[i][1],s[i][2]);
    }
    LL ret = 0;
    // last not C
    // C*i+PCPCPCPCPPPPP
    for (int i = 1; i <= m - 1; i++) {
        //printf("i = %lld\n",i);
        LL nowv = bias - s[i][2] + s[m][2] - s[i][2];
        if (nowv <= 0) break;
        int L = i, R = m - 1;
        auto check = [&](int idx) {
            return nowv - 2 * (s[idx][i % 2] - s[i][i % 2]) > 0;
        };
        if (check(R)) {
            LL delta = (R-i)/2+1;
            upd(ret, delta);
            continue;
        }
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (check(mid)) L = mid;
            else R = mid;
        }
        upd(ret, (L - i) / 2 + 1);
    }
    // last is C
    // C*i+PCPCPCPCPPPPC
    //puts("phase 2");
    for (int i = 1; i <= m - 2; i++) {
        //printf("i = %d\n",i);
        LL nowv = bias - s[i][2] + s[m - 1][2] - s[i][2] - b[m];
        //printf("?? %lld %lld %lld %lld\n",bias,s[i][2],s[m-1][2],b[m]);
        //printf("nowv = %lld\n",nowv);
        if (nowv <= 0) break;
        int L = i, R = m - 2;
        auto check = [&](int idx) {
            return nowv - 2 * (s[idx][i % 2] - s[i][i % 2]) > 0;
        };
        if (check(R)) {
            LL delta = (R - i) / 2 + 1;
            upd(ret, delta);
            continue;
        }
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (check(mid)) L = mid;
            else R = mid;
        }
        upd(ret, (L - i) / 2 + 1);
    }
    // PPPPCCCC
    if (bias == 0) {
        for (int i = 1; i <= m; i++) {
            if (s[i][2] - (s[m][2] - s[i][2]) > 0) {
                upd(ret, 1LL);
            }
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld",&a[i]);
        }
        LL v1 = solve(a, n, 0);
        LL v2 = solve(a + 1, n - 1, a[1]);
        LL ans = (v1 + v2) % MOD;
        printf("%lld\n", ans); 
    }
}