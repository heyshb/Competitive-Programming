#include <bits/stdc++.h>
#define b(x,i) (((x) >> (i)) & 1)
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

// i rows  mask    m  fm
const int MOD = 31607;
int dp[22][2][2][1 << 21];
int prob[22][1 << 21], p2[22][1 << 21];
int n;
int a[22][22];

void mul(int &x, int y) {
    x = x * y % MOD;
}

void FWT(int f[], int n, int op) {
    int mx = 0;
    while((1LL<<mx) < n) mx++;
    for (int i = 1; i <= mx; ++i) {
        int m = (1 << i), len = m >> 1;
        for (int r = 0; r < n; r += m) {
            int t1 = r, t2 = r + len;
            for (int j = 0; j < len; ++j, ++t1, ++t2) {
                LL x1 = f[t1], x2 = f[t2];
                f[t1] = x1;
                f[t2] = x2 + x1;
            }
        }
    }
}

void IFWT(int f[], int n, int op) {
    int mx = 0;
    while((1<<mx) < n) mx++;
    for (int i = mx; i >= 1; --i) {
        int m = (1 << i), len = m >> 1;
        for (int r = 0; r < n; r += m) {
            int t1 = r, t2 = r + len;
            for (int j = 0; j < len; ++j, ++t1, ++t2) {
                int x1 = f[t1], x2 = f[t2];
                f[t1] = x1;
                f[t2] = x2 - x1;
            }
        }
    }
}

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    scanf("%d",&n);    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int M = (1 << n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            prob[i][j] = 1;
            p2[i][j] = 1;
            for (int k = 0; k < n; k++) {
                if (j & (1 << k)) mul(prob[i][j], 10000 - a[i][j]);
                else mul(prob[i][j], a[i][j]);
                if ((j & (1 << k)) && k != i && k != n - 1 - i) mul(p2[i][j], 10000 - a[i][j]);
                else mul(p2[i][j], a[i][j]);
            }
        }
    }
    for (int j = 0; j < M; j++) {
        dp[0][j & 1][(j >> (n - 1)) & 1][j] = prob[0][j];
    }
    for (int i = 1; i < n; i++) {

    }
}