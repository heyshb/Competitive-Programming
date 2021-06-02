#include <bits/stdc++.h>

using namespace std;

int T, N, M, X;
int a[1010][1010], S[1010][1010], C[1010][1010], D[1010][1010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&M,&X);
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                int tmp;
                scanf("%d",&tmp);
                a[i][j] -= tmp;
                S[i][j] = S[i - 1][j] + a[i][j];
            }
        }
        for (int i=1;i<=N-X+1;i++) {
            for (int j=1;j<=M;j++) {
                int past = C[i-1][j] - C[max(i - X, 0)][j];
                a[i][j] -= past;
                C[i][j] = C[i-1][j] + a[i][j];
            }
        }
        for (int i=N-X+2;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                a[i][j] -= C[N-X+1][j] - C[max(i - X, 0)][j];
            }
        }
        bool ans = true;
        for (int i=N-X+2;i<=N;i++) {
            for (int j=1;j<=M-X+1;j++) {
                int past = D[i][j-1] - D[i][max(j - X, 0)];
                a[i][j] -= past;
                D[i][j] = D[i][j - 1] + a[i][j]; 
            }
            for (int j=M-X+2;j<=M;j++) {
                a[i][j] -= D[i][M-X+1] - D[i][max(i - X, 0)];
                if (a[i][j]) ans = false;
            }
        }
        puts(ans ? "Yes" : "No");
    }
}