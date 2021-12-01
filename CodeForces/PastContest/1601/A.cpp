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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        int g = 0;
        for (int w = 30; w >= 0; w--) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((a[i] >> w) & 1) {
                    cnt++;
                }
            }
            g = __gcd(g, cnt);
        }
        for (int i = 1; i <= n; i++) {
            if (g % i == 0) {
                printf("%d ",i);       
            }
        }
        puts("");
    }
}