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
        LL po = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            while(a[i] % 2 == 0) {
                po *= 2LL;
                a[i] /= 2;
            }
        }
        sort(a.begin(), a.end());
        LL ret = po * a[n - 1];
        for (int i = 0; i < n - 1; i++) {
            ret += a[i];
        }
        printf("%lld\n",ret);
    } 
}