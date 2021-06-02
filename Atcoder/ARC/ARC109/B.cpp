#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    LL N, L, R;
    scanf("%lld",&N);
    L = 0, R = N + 1;
    while(L < R - 1) {
        LL mid = (L + R) / 2;
        //printf("%lld %lld %lld\n",L,R,mid);
        if (mid > 2e9) {
            R = mid;
        } else if ((mid + 1) * mid / 2 <= N + 1) {
            L = mid;
        } else {
            R = mid;
        }
    }    
    printf("%lld\n",N + 1 - L);
}