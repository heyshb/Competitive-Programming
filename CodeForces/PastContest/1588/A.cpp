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
        vector<int>a(n), b(n);
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d",&b[i]);
        }
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= (b[i] >= a[i] && b[i] <= a[i] + 1);
        }
        puts(ok ? "YES" : "NO");
    }   
}