#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;


bool is_prime(int x) {
    for (int i=2;i<x;i++) {
        if (x % i == 0) return false;
    }
    return true;
}
vector<int>p;
int N, a[110];

int main() {
    for (int i=2;i<=50;i++) {
        if (is_prime(i)) p.push_back(i);
    }
    int M = p.size();
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d",&a[i]);
    LL ans = 1e18;
    for (int i=0;i<(1<<M);i++) {
        LL val = 1;
        for (int j=0;j<M;j++) {
            if (i & (1 << j)) val *= p[j];
        }
        bool ok = true;
        for (int j=1;j<=N;j++) if (__gcd(LL(a[j]), val) == 1) ok = false;
        if (ok) ans = min(ans, val);
    }
    printf("%lld\n",ans);
}