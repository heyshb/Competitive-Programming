#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL a[1000010],b[1000100];

LL check(LL d) {
    //printf("%lld\n",d);
    for (int i=1;i<=N;i++) {
        b[i] = a[i] % d;
    }
    LL s = 0;
    LL ret = 0;
    for (int i=1;i<=N;i++) {
        ret += min(s, d - s);
        s = (s + a[i]) % d;
    }
    return ret;
}

int main() {
    scanf("%d",&N);
    LL S = 0;
    for (int i=1;i<=N;i++) {
        scanf("%lld",&a[i]);
        S += a[i];
    }
    if (S == 1) {
        puts("-1");
        return 0;
    }
    LL ans = check(S);
    LL os = S;
    for (LL i=2;i*i<=os;i++) {
        if (S % i == 0) {
            ans = min(ans, check(i));
            while(S % i == 0) {
                S /= i;
            }
            if (S == 1) {
                break;
            }
        }
    }
    if (S > 1) {
        ans = min(ans, check(S));
    }
    printf("%lld\n",ans);
}