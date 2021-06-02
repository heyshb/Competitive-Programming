#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, N, K;
int x[1010],y[1010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&K);
        for (int i=1;i<=N;i++) {
            scanf("%d%d",&x[i],&y[i]);
        }
        bool ok = false;
        for (int i=1;i<=N;i++) {
            int cnt = 0;
            for (int j=1;j<=N;j++) {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= K) {
                    cnt++;
                }
            }
            if (cnt == N) ok = true;
        }
        puts(ok ? "1" : "-1");
    }
}