#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    LL v;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld",&v);
        int cnt2 = 0;
        while(v % 2 == 0) {
            cnt2++;
            v /= 2;
        }
        if (cnt2 == 0) puts("Odd");
        else if (cnt2 == 1) puts("Same");
        else puts("Even");
    }
}