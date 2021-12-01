#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL query(int L, int R) {
    printf("? %d %d\n",L,R);
    fflush(stdout);
    LL ret;
    scanf("%lld",&ret);
    return ret;
}

const int M = 1e9;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        LL sum = query(1, n);
        int L = 1, R = n;
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (query(1, mid) == sum) {
                R = mid;
            } else {
                L = mid;
            }
        }
        int ansi, ansj, ansk;
        ansk = R;
        LL len2 = sum - query(1, ansk - 1);
        ansj = ansk - len2;
        LL sum2 = 1LL * len2 * (len2 + 1) / 2;
        sum -= sum2;
        //printf("pre sum = %lld\n",sum);
        LL len1 = (1 + LL(sqrt((long double)1 + 8LL * sum) + 0.5)) / 2;
        ansi = ansj - len1;
        printf("! %d %d %d\n",ansi,ansj,ansk);
        fflush(stdout);
    }
}