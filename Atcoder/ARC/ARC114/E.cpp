#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

int v[4], x;
int H, W, h1, h2, w1, w2;
const int MOD = 998244353;
const int M = 300000;
int fac[M + 1], ifac[M + 1];

int seg_mul(int L,int R) {
    assert(L >= 0 && L <= M && R >= 0 && R <= M);
    if (L > R) swap(L, R);
    int ret = fac[R];
    if (L > 0) ret = 1LL * ret * ifac[L - 1] % MOD;
    return ret;
}

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) {
            ret = 1LL * ret * a % MOD;
        }
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int inv(int x) {
    return quick_pow(x, MOD - 2);
}

int solve(int n, int m) {
    int sum = 0;
    int iv = inv(n + 1);
    for (int p=1;p<=n;p++) {
        int fz = seg_mul(n + 1 - p, n + m - p);
        int fm = seg_mul(n + 1, n + m);
        int tmp = 1LL * fz * inv(fm) % MOD;
        tmp = 1LL * tmp * inv(p) % MOD;
        sum = (sum + tmp) % MOD;
    }
    //printf("solve %d %d = %d\n",n,m,sum);
    return sum;
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i=1;i<=M;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2); 
    }
    //printf("seg mul = %d\n",seg_mul(3, 5));
    scanf("%d%d",&H,&W);
    scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
    if (h1 > h2) swap(h1, h2);
    if (w1 > w2) swap(w1, w2);
    v[0] = h1 - 1;
    v[1] = H - h2;
    v[2] = w1 - 1;
    v[3] = W - w2;
    x = h2 - h1 + w2 - w1;
    //printf("%d%d%d%d%d\n",v[0],v[1],v[2],v[3],x);
    int ans = 0;
    for (int i=0;i<4;i++) {
        ans = (ans + solve(v[i], x)) % MOD;
    }
    ans = (ans + 1) % MOD;
    printf("%d\n",ans);
}