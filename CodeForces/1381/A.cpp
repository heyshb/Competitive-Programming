#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        string A, B;
        cin >> n >> A >> B;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (A[i] != B[i]) {
                ans.push_back(i + 1);
                ans.push_back(1);
                ans.push_back(i + 1);
            }
        }
        printf("%d",ans.size());
        for (auto &t : ans) printf(" %d",t);
        puts("");
    }
}