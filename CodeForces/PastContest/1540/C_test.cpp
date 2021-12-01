#include <bits/stdc++.h>

using namespace std;

int n;
double a[1010];
int b[1010];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf",&a[i]);
    }
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d",&b[i]);
    }
    srand(time(NULL));
    for (int T = 1; T <= 1000; T++) {
        int t = rand() % (n - 1) + 1;
        double mid = (a[t] + a[t + 1]) / 2;
        a[t] = min(a[t], mid - 0.5 * b[t]);
        a[t + 1] = max(a[t + 1], mid + 0.5 * b[t]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%.3lf ", a[i]);
    }
}