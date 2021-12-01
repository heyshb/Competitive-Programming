#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, l, r, k;
        scanf("%d%d%d%d",&n,&l,&r,&k);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < l || a[i] > r) continue;
            if (k < a[i]) break;
            k -= a[i];
            ans++;
        }
        printf("%d\n",ans);
    }
}