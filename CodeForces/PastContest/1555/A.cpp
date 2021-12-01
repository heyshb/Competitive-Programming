#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        LL x;
        scanf("%lld",&x);
        if (x % 2 == 1) x++;
        if (x <= 6) puts("15");
        else printf("%lld\n",x * 5 / 2);
    }
}