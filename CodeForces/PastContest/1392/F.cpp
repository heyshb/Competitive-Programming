#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
LL h[1000100], ans[1000010];

int main() {
    scanf("%d",&n);
    LL s = 0;
    LL sp = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&h[i]);
        sp += i;
        s += h[i];
    }
    int delta = (s - sp) % n;
    s -= delta;
    for (int i = 1; i <= n; i++) {
        ans[i] = i + (s - sp) / n;
    }
    for (int i = 1; i <= delta; i++) {
        ans[i]++;
    }
    for (int i = 1; i <= n; i++) printf("%lld%c",ans[i]," \n"[i==n]);
}