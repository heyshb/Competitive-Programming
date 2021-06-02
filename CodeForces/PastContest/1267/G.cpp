#include <bits/stdc++.h>

using namespace std;

typedef long double bg;

bg C[110][110],f[110][10010];
int N,S,X;
int a[110];

int main() {
    scanf("%d%d",&N,&X);
    S = 0;
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        S += a[i];
    }
    memset(C,0,sizeof(C));
    C[0][0] = 1;
    for (int i=1;i<=100;i++) {
        C[i][0] = 1;
        for (int j=1;j<=i;j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    } 
    bg ans = 0;
    memset(f,0,sizeof(f));
    f[0][0] = 1;
    for (int i=1;i<=N;i++) {
        for (int j=N;j>=1;j--) {
            for (int k=a[i];k<=S;k++) {
                f[j][k] += f[j-1][k-a[i]];
            }
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=S;j++) {
            ans += f[i][j] / C[N][i] * min(1.0 * j / i, 0.5 * X * (N + i) / i);
        }
    }
    printf("%.12lf\n",double(ans));
}