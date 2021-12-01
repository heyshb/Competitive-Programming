#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T = 1;
    //cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<vector<int>> e(n, vector<int>(m, 0)), fuck(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '.') {
                    if (i == 0 || j == 0 || e[i - 1][j] || e[i][j - 1]) {
                        e[i][j] = 1;
                    }
                }
                if (i > 0 && j > 0) {
                    fuck[i][j] = fuck[i - 1][j] + fuck[i][j - 1] - fuck[i - 1][j - 1] + (e[i][j] == 0);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", fuck[i][j]);
            }
            puts("");
        }
        int Q;
        cin >> Q;
        while(Q--) {
            int L, R;
            cin >> L >> R;
            L--; R--;
            int sum = fuck[n - 1][R] - fuck[n - 1][L];
            puts(sum > 0 ? "NO" : "YES");
        }
    }
}