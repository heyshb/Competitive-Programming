#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

typedef long long LL;
int N, M;
int a[200010], cnt[1010];
LL MOD;

LL quick_pow(LL a,LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    scanf("%d%d",&N, &M);
    MOD = M;
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    if (N > M) {
        puts("0");
        return 0;
    }
    LL ans = 1;
    for (int i=1;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            ans = ans * abs(a[i] - a[j]) % M;
        }
    }
    printf("%lld\n",ans);
}