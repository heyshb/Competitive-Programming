#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
char s[51][51];
int d[51][51];

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%s",s[i] + 1);
    }
    int cnt = 0;
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] != '.') {
                queue<pii> q;
                q.emplace(i, j);
                cnt++;
                while(!q.empty()) {
                    auto now = q.front();
                    q.pop();
                    int x = now.first, y = now.second;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                    }
                }
            }
        }
    }
}