#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main() {
    const int MOD = 1e9 + 7;
    int n;
    scanf("%d",&n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&c[i]);
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    if (c[0] == 1) {
        
    }
}