#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int a[110];
int f[110][110][2];

int main() {
    scanf("%d",&N);
    int od = (N + 1) / 2 ,ev = N / 2;
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<=N;i++) {
        for (int j=0;j<=N;j++) {
            f[i][j][0] = f[i][j][1] = 1e9;
        }
    }
    f[0][0][0] = f[0][0][1] = 0;
    for (int i=1;i<=N;i++) {
        for (int j=0;j<=od;j++) {
            for (int l=0;l<2;l++) {
                if (a[i] > 0) {
                    if (a[i] % 2 == l) {
                        if (l == 1) {
                            if (j)
                                f[i][j][l] = min(f[i-1][j-1][1], f[i-1][j-1][0] + 1);
                        } else {
                            if (i-j>0)
                                f[i][j][l] = min(f[i-1][j][0], f[i-1][j][1] + 1);
                        }
                    } 
                    continue;
                }
                f[i][j][l] = min(f[i][j][l], min(f[i-1][j-1][0] + 1, f[i-1][j-1][1]));
                f[i][j][l] = min(f[i][j][l], min(f[i-1][j][1] + 1, f[i-1][j][0]));
            }
        }
    }
    printf("%d\n",min(f[N][od][ev][0], f[N][od][ev][1]));
}