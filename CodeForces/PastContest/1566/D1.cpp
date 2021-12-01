#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
int ass[310 * 310], a[310 * 310];
int vis[310][310];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        vector<pii> pr;
        for (int i = 1; i <= n * m; i++) {
            scanf("%d",&a[i]);
            pr.push_back(pii(a[i], i));
        }
        sort(pr.begin(), pr.end());
        int done = 0;
        auto fuck = [&](int x) {
            return pii((x - 1) / m, -((x - 1) % m));
        };
        for (int i = 0; i < pr.size(); i++) {
            if (i == 0 || pr[i].first != pr[i - 1].first) {
                int R = i;
                while(R + 1 < pr.size() && pr[R + 1].first == pr[i].first) R++;
                int mi = i + 1;
                int ma = R + 1;
                vector<int> seats;
                for (int j = mi; j <= ma; j++) seats.push_back(j);
                sort(seats.begin(), seats.end(), [&](int s1, int s2) {
                    return fuck(s1) < fuck(s2);
                });
                for (int j = i; j <= R; j++) {
                    ass[pr[j].second] = seats[j - i];
                    //printf("ass %d %d\n",pr[j].second,seats[j - i]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n * m; i++) {
            auto seat = fuck(ass[i]);
            int row = seat.first;
            int col = -seat.second;
            //printf("zuo %d %d %d\n",ass[i],row,col);
            for (int j = 0; j < col; j++) {
                ans += vis[row][j];
            }
            vis[row][col] = 1;
        }
        printf("%d\n",ans);
    }
}