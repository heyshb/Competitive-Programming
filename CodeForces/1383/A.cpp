#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        int n;
        string A, B;
        cin >> n;
        cin >> A;
        cin >> B;
        const int M = 20;
        vector<vector<int>> vis(M, vector<int>(M, 0)), way(M, vector<int>(M, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > B[i]) goto END;
            if (A[i] < B[i]) {
                vis[A[i] - 'a'][B[i] - 'a'] = 1;
                way[A[i] - 'a'][B[i] - 'a'] = 1;
            }
        }
        for (int len = 2; len < M; len++) {
            for (int i = 0; i + len < M; i++) {
                int j = i + len;
                for (int k = i + 1; k < j; k++) {
                    way[i][j] += way[i][k] * way[k][j];
                }
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                if (vis[i][j] && way[i][j] == 1) ans++;
            }
        }
        cout << ans << endl;

        continue;
        END:
        cout << -1 << endl;
    }
    
}