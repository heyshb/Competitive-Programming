#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        int ans = 0;
        while(ans * 2 + 1 < n) ans = ans * 2 + 1;
        printf("%d\n",ans);
    }
}