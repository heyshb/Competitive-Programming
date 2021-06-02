#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
int f[20010];
int x[110],y[110];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        int mx = 0;
        for (int i=1;i<=N;i++) {
            scanf("%d%d",&x[i],&y[i]);
            mx = max(mx, x[i]);
        }
        for (int i=0;i<=M+mx;i++) f[i] = 1e9;
        f[0] = 0;
        for (int i=1;i<=N;i++) {
            for (int j=0;j<=M;j++) {
                f[j+x[i]] = min(f[j+x[i]],f[j]+y[i]);
            }
        }
        int ans = 1e9;
        for (int i=M;i<=M+mx;i++) {
            ans = min(ans, f[i]);
        }
        printf("%d\n",ans);
    }
}