#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int a[1010];
const int MOD = 1e9 + 7;
int qp(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}
int inv(int a) {
    return qp(a, MOD - 2);
}

int mul(int a,int b) {
    return 1LL * a * b % MOD;
}

int dv(int a,int b) {
    //printf("dv %d %d\n",a,b);
    return 1LL * a * inv(b) % MOD;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        int ans = 0;
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            ans += a[i] / 2;
        }
        for (int i=1;i<N;i++) {
            int d1 = a[i + 1];
            int d2 = a[i];
            int single_p = dv(d1 + d2, 2 * d1);
            //printf("p = %d\n",single_p);
            ans -= mul(single_p, d1 / 2);
            if (ans < 0) ans += MOD;
        }
        printf("%d\n",ans);
    }
}