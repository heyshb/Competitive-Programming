#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL a[200010];
const LL INF = 1e16;
typedef pair<LL,LL> pll;
LL up[200010], down[200010];

bool check(LL K) {
    up[1] = K;
    down[1] = 0;
    for (int i = 2; i <= N; i++) {
        LL u = a[i - 1], v = a[i];
        up[i] = -INF;
        down[i] = INF;
        LL delta = v - u;
        // from last up
        LL t = up[i - 1];
        /*
        if (t >= 0 && delta / 2 <= t) {
            up[i] = max(up[i], t - delta / 2);
            down[i] = min(down[i], delta / 2);
        }
        */
        if (t >= 0 && t <= K) {
            up[i] = max(up[i], t - delta / 2);
            if (t >= delta / 2) down[i] = min(down[i], delta / 2);
        }
        t = down[i - 1];
        if (t >= 0 && t <= K) {
            up[i] = max(up[i], K - t - delta / 2);
            down[i] = min(down[i], t + delta / 2);
        }
        //printf("%d %lld %lld\n",i,up[i],down[i]);
        up[i] = min(up[i], K);
        down[i] = max(down[i], 0LL);
        if (down[i] > K || up[i] < 0) return false;
    }
    return true;
}

int main() {
    scanf("%d",&N);
    for (int i = 1; i <= N; i++) {
        scanf("%lld",&a[i]);
    }
    //check(3);return 0;
    LL L = 0, R = 1e9;
    while(L < R - 1) {
        LL mid = (L + R) / 2;
        //printf("check %lld %lld %lld\n",L,R,mid);
        if (check(mid)) R = mid;
        else L = mid;
    }
    printf("%lld\n",R);
}