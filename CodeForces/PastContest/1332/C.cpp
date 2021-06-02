#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K;
char s[200010];
int fa[200010];
int cnt[200010][26];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x,int y) {
    if (find(x) == find(y)) return;
    fa[find(x)] = find(y);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N, &K);
        scanf("%s", s + 1);
        for (int i=1;i<=N;i++) {
            fa[i] = i;
            for (int j=0;j<26;j++) {
                cnt[i][j] = 0;
            }
        }
        for (int i=1;i<=N;i++) {
            if (i + K <= N) {
                merge(i, i + K);
            }
            merge(i, N + 1 - i);
        }
        for (int i=1;i<=N;i++) {
            cnt[find(i)][s[i] - 'a']++;
        }
        int ans = 0;
        for (int i=1;i<=N;i++) {
            if (i == find(i)) {
                int ss = 0, mx = 0;
                for (int j=0;j<26;j++) {
                    ss += cnt[i][j];
                    mx = max(mx, cnt[i][j]);
                }
                ans += ss - mx;
            }
        }
        printf("%d\n",ans);
    }
}