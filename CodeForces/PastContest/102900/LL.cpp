#include <bits/stdc++.h>

using namespace std;

double dis(int x, int y) {
    return sqrt(1.0 * x * x + 1.0 * y * y);
}

const double INF = 1e18;

double test(int x, int y, int n, int m) {
    if (y < 0 || y > m) return INF;
    if (__gcd(x, y) != 1) return INF;
    if (__gcd(n - x, m - y) != 1) return INF;
    if (1LL * n * y == 1LL * m * x) return INF;
    // y / x == m / n
    return dis(x, y) + dis(n - x, m - y); 
}

double solve(int n, int m) {
    if (__gcd(n, m) == 1) return dis(n, m);
    double ans = INF;
    for (int i = 0; i <= n; i++) {
        int p = int(1.0 * i / n * m);
        for (int j = p - 2; j <= p + 2; j++) {
            ans = min(ans, test(i, j, n, m));
            //printf("%d %d %.5lf\n",i,j,ans);
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, m;
        scanf("%d%d",&n,&m);
        printf("%.10lf\n",solve(n, m));
    }
}