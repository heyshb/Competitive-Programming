#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n, m;
int main() {
    scanf("%d%d",&n,&m);
    const double pi = acos(-1);
    double ans = (2 * m) * (n + 1) * n / 2;
    if (m == 1) ans = 0;
    double part_round = 0;
    double inner_round = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            double theta = pi * j / m;
            part_round += 2.0 * min(2.0, theta) * i * (n - i);
            //printf("%d %d %.5lf\n",i,j,theta);
            inner_round += 2.0 * min(2.0, theta) * i;
            //printf("fuck %.5lf\n",inner_round);
        }
        part_round += 2.0 * i * (n - i);
        inner_round += 2.0 * i;
    }
    part_round *= (2 * m);
    //printf("%.10lf\n",inner_round);
    inner_round *= m;
    //printf("%.10lf\n",part_round);
    double part_dir = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            part_dir += (j - i) * (2 * m);
        }
    }
    part_dir *= (2 * m);
    ans += part_round;
    ans += part_dir;
    ans += inner_round;
    printf("%.10lf\n",ans);
}