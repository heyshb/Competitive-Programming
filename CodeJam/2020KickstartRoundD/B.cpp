#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N,a[20010];
int f[20010][4];

void upd(int &x, int y) {
    x = min(x, y);
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            for (int j=0;j<4;j++) {
                f[i][j] = 1e9;
            }
        }
        int ans = 1e9;
        for (int i=0;i<4;i++) f[1][i] = 0;
        for (int i=1;i<N;i++) {
            for (int j=0;j<4;j++) {
                if (a[i+1] > a[i]) {
                    for (int k=0;k<4;k++) {
                        upd(f[i+1][k], f[i][j] + (k > j ? 0 : 1));
                    }
                } else if (a[i + 1] == a[i]) {
                    for (int k=0;k<4;k++) {
                        upd(f[i+1][k], f[i][j] + (k == j ? 0 : 1));
                    }
                } else {
                    for (int k=0;k<4;k++) {
                        upd(f[i+1][k], f[i][j] + (k < j ? 0 : 1));
                    }
                }
            }
        }
        for (int i=0;i<4;i++) upd(ans, f[N][i]);
        printf("Case #%d: %d\n",T,ans);
    }
}