#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL a[1000010], v[1000010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&a[i]);
    }
    int ans = 0;
    for (int b=0;b<=24;b++) {
        int mask = (1 << (b + 1)) - 1;
        for (int i=1;i<=N;i++) {
            v[i] = a[i] & mask;
        }
        sort(v + 1, v + N + 1);
        LL cnt = 0;
        int up = mask, down = (1 << b);
        for (int i=1;i<=N;i++) {
            int L = lower_bound(v + 1, v + N + 1, down - v[i]) - v;
            int R = upper_bound(v + 1, v + N + 1, up - v[i]) - v;
            R--;
            cnt += (R - L + 1);
            if (i >= L && i <= R) cnt--;

            //printf("%d %d\n",b, (1 << (b + 1)) + down);
            L = lower_bound(v + 1, v + N + 1, (1 << (b + 1)) + down - v[i]) - v;
            R = N;
            cnt += (R - L + 1);
            if (i >= L && i <= R) cnt--;
        }
        assert(cnt % 2 == 0);
        cnt /= 2;
        if (cnt & 1) {
            ans |= (1 << b);
        }
    }
    /*
    int ans2 = 0;
    for (int i=1;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            ans2 ^= (a[i] + a[j]);
        }
    }
    printf("%d\n",ans2);
    */
    printf("%d\n",ans);
}