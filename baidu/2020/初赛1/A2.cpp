#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
int x[110],y[110];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        int mx = 0;
        int ans = 1e9;
        for (int i=1;i<=N;i++) {
            scanf("%d%d",&x[i],&y[i]);
            ans = min(ans, (M + x[i] - 1) / x[i] * y[i]);
        }
        printf("%d\n",ans);
    }
}