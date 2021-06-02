#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int a[300010];
int ans[300010];
vector<int>pos[300010];
const int INF = 1e9;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            pos[i].clear();
            pos[i].push_back(0);
        }
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
        }
        for (int i=1;i<=N;i++) {
            pos[i].push_back(N + 1);
        }
        for (int i=0;i<=N;i++) {
            ans[i] = INF;
        }
        for (int i=1;i<=N;i++) {
            int max_delta = 0;
            for (int j=1;j<pos[i].size();j++) {
                max_delta = max(max_delta, pos[i][j] - pos[i][j - 1]);
            }
            ans[max_delta] = min(ans[max_delta], i);
        }
        for (int i=1;i<=N;i++) {
            ans[i] = min(ans[i], ans[i - 1]);
        }
        for (int i=1;i<=N;i++) {
            if (ans[i] == INF) ans[i] = -1;
            printf("%d%c",ans[i]," \n"[i==N]);
        }
    }
}