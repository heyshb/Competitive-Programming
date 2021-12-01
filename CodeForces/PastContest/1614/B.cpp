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
        vector<pii> a(n); 
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i].first);
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        vector<int> ans(n);
        LL sum = 0;
        for (int i = 0; i < n; i++) {
            int d = i / 2 + 1;
            sum += 2LL * a[i].first * d;
            if (i & 1) d = -d;
            ans[a[i].second] = d;
        }
        printf("%lld\n",sum);
        printf("0");
        for (int i = 0; i < n; i++) {
            printf(" %d",ans[i]);
        }
        puts("");
    }
    
}