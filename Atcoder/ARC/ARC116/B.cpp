#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 998244353;
int N;
LL a[200100];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+N+1);
    LL S = a[1];
    LL ans = 0;
    for (int i=2;i<=N;i++) {
        ans = (ans + a[i] * S % MOD) % MOD;
        S = (S * 2 + a[i]) % MOD;
    }
    for (int i=1;i<=N;i++) {
        ans = (ans + a[i] * a[i]) % MOD;
    }
    printf("%lld\n",ans);
}