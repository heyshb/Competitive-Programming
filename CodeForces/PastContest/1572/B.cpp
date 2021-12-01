#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        vector<int> a(n);
        int S = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            S ^= a[i];
        }
        if (S != 0) {
            puts("NO");
            continue;
        }
        vector<int> ans;
        auto fuck = [&](int idx) {
            int ret = a[idx] ^ a[idx + 1] ^ a[idx + 2];
            a[idx] = a[idx + 1] = a[idx + 2] = ret;
            ans.push_back(idx);
        };
        for (int i = 0; i < n; i++) {
            
        }        
        printf("%d\n",ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d%c",ans[i] + 1, " \n"[i == ans.size() - 1]);
        }
    }
}