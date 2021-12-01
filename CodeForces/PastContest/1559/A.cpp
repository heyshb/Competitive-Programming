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
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d",&tmp);
            if (i == 1) ans = tmp;
            else ans &= tmp;
        }
        printf("%d\n",ans);
    }
}