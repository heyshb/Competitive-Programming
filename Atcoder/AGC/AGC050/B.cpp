#include <bits/stdc++.h>

using namespace std;

int f[510][510], g[510][510];
int N, a[510], s[510];

int sum(int L,int R) {
    return s[R] - s[L - 1];
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        s[i] = s[i - 1] + a[i];
    }    
    for (int i=1;i<=N;i++) {
        for (int j=i;j<=N;j++) {
            f[i][j] = 0;
            g[i][j] = sum(i, j);
        }
    }
    for (int len=1;len<=N;len++) {
        for (int L=1;L+len-1<=N;L++) {
            int R = L + len - 1;
            /*
            for (int i=L;i+2<=R;i++) {
                f[L][R] = max(f[L][R], f[L][i - 1] + f[i + 3][R] + max(0, sum(i, i + 2)));
                g[L][R] = max(g[L][R], g[L][i - 1] + g[i + 3][R] + max(0, sum(i, i + 2)));
            }
            */
            for (int i=L;i<R;i++) {
                f[L][R] = max(f[L][R], f[L][i] + f[i + 1][R]);
                g[L][R] = max(g[L][R], g[L][i] + g[i + 1][R]);
            }
            
            if (len % 3 == 0) {
                int mx = max(f[L][R], g[L][R]);
                f[L][R] = g[L][R] = mx;
            }
            //printf("f[%d][%d] = %d, g[%d][%d] = %d\n",L,R,f[L][R],L,R,g[L][R]);
        }
    }
    printf("%d\n",f[1][N]);
}