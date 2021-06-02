#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int C;
        scanf("%d",&C);
        LL a = 0, b = 0;
        bool first = true;
        for (int i=30;i>=0;i--) {
            if ((1 << i) > C) continue;
            if ((C >> i) & 1) {
                if (first) {
                    a ^= (1 << i);
                    first = false;
                } else {
                    b ^= (1 << i);
                }
            } else {
                a ^= (1 << i);
                b ^= (1 << i);
            }
        }
        printf("%lld\n",a * b);
    }
}