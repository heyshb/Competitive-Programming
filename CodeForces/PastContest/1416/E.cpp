#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL a[300010];
const LL INF = 1e12;

typedef pair<LL, LL> pll;
const pll empty(1, 0);
pll normalize(pll p, LL L, LL R) {
    if (p == empty) return p;
    p.first = max(p.first, L);
    p.second = min(p.second, R);
    return p;
}

pll rev(pll p, LL x) {
    if (p == empty) return p;
    pll ret = pll(x - p.second, x - p.first);
    return normalize(ret, 1, x - 1);
}

pll intersect(pll p1, pll p2) {
    LL L = max(p1.first, p2.first);
    LL R = min(p1.second, p2.second);
    if (L > R) return empty;
    return pll(L, R);
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&a[i]);
    }
    pll range = empty;
    set<LL> s;
    int ans = 0;
    for (int i=1;i<=N;i++) {
        if (a[i] % 2 == 0) {
            LL m = a[i] / 2;
            if ((m >= range.first && m <= range.second) || (s.find(m) != s.end())) {
                ans += 2;
                s.clear();
                range = pll(m, m);
            } else {
                ans++;
            }
        } else {

        }
    }
} 