#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, K;
int a[110];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&K);
        a[0] = 1e9;
        int dif = 0;
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            if (a[i] != a[i - 1]) dif++;
        }
        if (K == 1) {
            if (dif > 1) puts("-1");
            else puts("1");
        } else {
            printf("%d\n",(dif - 1 + K - 1 - 1) / (K - 1));
        }
    }
}