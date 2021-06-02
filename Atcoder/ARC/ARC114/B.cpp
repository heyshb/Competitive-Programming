#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int MOD = 998244353;
int N, a[200010], vis[200010];
int in[200010];
int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        in[a[i]]++;
    }
    queue<int>q;
    for (int i=1;i<=N;i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = true;
        if (--in[a[now]] == 0) q.push(a[now]);
    }

    int fuck = 0;
    for (int i=1;i<=N;i++) {
        if (!vis[i]) {
            fuck++;
            for (int j=i;!vis[j];j=a[j]) {
                vis[j] = true;
            }
        }
    }
    LL ans = 1;
    for (int i=1;i<=fuck;i++) ans = ans * 2LL % MOD;
    ans = (ans + MOD - 1) % MOD;
    printf("%lld\n",ans);
}