#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<char, int> pci;

char s[200010];

int main() {
    int n;
    scanf("%d",&n);
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld",&a[i]);
    }
    scanf("%s",s);
    sort(a.begin(), a.end());
    vector<LL> ans;
    if (s[n - 1] == 'R') {
        for (int i = n - 2; i >= 0; i -= 2) {
            a[i] = -a[i];
        }
    } else {
        for (int i = n - 1; i >= 0; i -= 2) {
            a[i] = -a[i];
        }
    }
    int L = 0, R = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i > 0 && s[i] == s[i - 1]) {
            ans.push_back(a[L++]);
        } else {
            ans.push_back(a[R--]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto &t : ans) {
        printf("%d",abs(t));
        if (t > 0) puts(" R");
        else puts(" L");
    }
}