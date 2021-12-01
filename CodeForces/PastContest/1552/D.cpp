#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[110];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 0; i < n; i++) scanf("%d",&a[i]);
        bool ok = false;
        for (int i = 1; i < (1 << n); i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) if (i & (1 << j)) v.push_back(a[j]);
            int m = v.size();
            for (int mask = 0; mask < (1 << m); mask++) {
                int sum = 0;
                for (int k = 0; k < m; k++) {
                    if (mask & (1 << k)) sum += v[k];
                    else sum -= v[k];
                }
                if (sum == 0) ok = true;
            }
        }
        puts(ok ? "YES" : "NO");
    }
}