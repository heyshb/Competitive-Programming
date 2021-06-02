#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, a[5010];
int f[5010][10010];
void upd(int &x, int y) {
    x = min(x, y);
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2 * n; j++) f[i][j] = 1e9;
    }
    f[0][n] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            //printf("f[%d][%d] = %d\n",i,j,f[i][j]);
            int val = f[i][j] + abs(j - n);
            if (a[i + 1] == 1) {
                if (j + 1 <= 2 * n) upd(f[i + 1][j + 1], val);
            } else {
                if (j - 1 >= 0) upd(f[i + 1][j - 1], val);
                upd(f[i + 1][j], val);
            }
        }
    }
    printf("%d\n",f[n][n]);
}