#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int MOD = 1e9 + 7;
int fac[MAXN + 10];
int ifac[MAXN + 10];
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

int N;
int D[100010];
typedef pair<int,int> pii;
typedef long long LL;
pii tr[800010];
void build(int x,int L,int R) {
    if (L == R) {
        tr[x] = pii(D[L], -L);
        return;
    }
    int mid = (L + R) / 2;
    build(x * 2, L, mid);
    build(x * 2 + 1, mid + 1, R);
    tr[x] = min(tr[x * 2], tr[x * 2 + 1]);
}
pii getmin(int x,int L,int R,int ql,int qr) {
    int mid = (L + R) / 2;
    if (L == ql && R == qr) return tr[x];
    if (qr <= mid) return getmin(x*2,L,mid,ql,qr);
    if (ql > mid) return getmin(x*2+1,mid+1,R,ql,qr);
    return min(getmin(x*2,L,mid,ql,mid),getmin(x*2+1,mid+1,R,mid+1,qr));
}

LL solve(int L,int R,int offset) {
    if (L > R) return 1LL;
    pii mi = getmin(1,1,N,L,R);
    int pos = -mi.second, val = mi.first;
    //printf("solve %d %d %d %d %d\n",L,R,offset,pos,val);
    if (val != offset + 1) return 0LL;
    //printf("solve %d %d %d %d %d\n",L,R,offset,pos,val);
    LL v1 = solve(L, pos - 1, offset);
    LL v2 = solve(pos + 1, R, offset + 1);
    return v1 * v2 % MOD * C(R - L, pos - L) % MOD;
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    int T, Case = 0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i = 1; i <= N; i++) {
            scanf("%d",&D[i]);
        }
        build(1,1,N);
        printf("Case #%d: %lld\n",++Case,solve(1,N,0));
    }
}