#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL r1, r2, r3, d;
int N;
LL f[1000010][2],b[1000010][2];
int a[1000010];

void udp(LL &x, LL y) {
    x = min(x, y);
}

int main() {
    scanf("%d%lld%lld%lld%lld", &N, &r1, &r2, &r3, &d);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&a[i]);
        b[i][0] = 1LL * 
    }
    for (int i=0;i<=N;i++) {
        f[i][0] = f[i][1] = 1e18;
    }
    f[0][0] = 0;
    for (int i=0;i<N;i++) {
        
    }
}