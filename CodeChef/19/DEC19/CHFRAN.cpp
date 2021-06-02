#include <bits/stdc++.h>

using namespace std;
int N;
typedef pair<int,int> pii;
typedef long long LL;
const int INF = 1e9;
int L[100010],R[100010],M;
int b[200010];
int f[200010],g[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        M = 0;
        for (int i=1;i<=N;i++) {
            scanf("%d%d",&L[i],&R[i]);
            b[++M] = L[i];
            b[++M] = R[i];
        }
        M = 0;
        b[0] = -1;
        sort(b+1,b+2*N+1);
        for (int i=1;i<=2*N;i++) {
            if (b[i] != b[i - 1]) {
                b[++M] = b[i];
            }
        }
        for (int i=1;i<=N;i++) {
            L[i] = lower_bound(b+1,b+M+1,L[i]) - b;
            R[i] = lower_bound(b+1,b+M+1,R[i]) - b;
        }
        int ans = INF;
        for (int i=0;i<=M+1;i++) {
            f[i] = 0;
            g[i] = 0;
        }
        for (int i=1;i<=N;i++) {
            f[R[i]]++;
            g[L[i]]++;
        }
        for (int i=1;i<=M;i++) {
            f[i] += f[i - 1];
        }
        for (int i=M;i>=1;i--) {
            g[i] += g[i + 1];
        }
        for (int i=1;i<M;i++) {
            if (f[i] > 0 && g[i + 1] > 0) {
                ans = min(ans, N - f[i] - g[i + 1]);
            }
        }
        if (ans == INF) {
            puts("-1");
        } else {
            printf("%d\n",ans);
        }
    }
}