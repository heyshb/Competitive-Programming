#include <bits/stdc++.h>

using namespace std;

int N;
long double P;
long double f[8010][8010];
typedef long long LL;

LL C(int x) {
    return 1LL * x * (x - 1) / 2;
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        double tmp;
        scanf("%d%lf",&N,&tmp);
        P = tmp;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                f[i][j] = 0;
            }
        }
        for (int i=2;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                LL sum_match = C(i);
                LL sum_ss = C(i - j);
                LL sum_ww = C(j - 1);
                LL sum_sw = 1LL * (j - 1) * (i - j);
                LL sum_js = i - j;
                LL sum_jw = j - 1;
                assert(sum_match == sum_ss + sum_ww + sum_sw + sum_js + sum_jw);
                f[i][j] += sum_ss * f[i - 1][j];
                f[i][j] += sum_ww * f[i - 1][j - 1];
                f[i][j] += sum_sw * (P * f[i - 1][j - 1] + (1 - P) * f[i - 1][j]);
                f[i][j] += sum_js * (1 - P) * f[i - 1][j];
                f[i][j] += sum_jw * P * f[i - 1][j - 1];
                f[i][j] /= sum_match;
                f[i][j] += 1;
            }
        }
        printf("Case #%d:\n",T);
        for (int i=1;i<=N;i++) {
            printf("%.8lf\n",double(f[N][i]));
        }
    }
}