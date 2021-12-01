#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<char, int> pci;

char s[200010];

char sgn(LL x) {
    if (x < 0) return 'L';
    else return 'R';
}

int main() {
    int n;
    scanf("%d",&n);
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld",&a[i]);
    }
    set<LL> st;
    scanf("%s",s);
    vector<pci> ans;
    for (int i = 0; i < n; i++) {
        
    }
    for (int i = 0; i < n; i++) {
        printf("%d %c\n",ans[i].second,ans[i].first);
        if (ans[i].first == 'L') S -= ans[i].second;
        else S += ans[i].second;
        assert(S != 0);
        assert(sgn(S) == s[i]);
    }
}