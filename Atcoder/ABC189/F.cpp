#include <bits/stdc++.h>

using namespace std;

int N, M, K;
bool fucked[200010];
typedef pair<double,double> pdd;
pdd f[200010];

int main() {
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1;i<=N+M;i++) {
        fucked[i] = false;
    }
    for (int i=1;i<=K;i++) {
        int tmp;
        scanf("%d",&tmp);
        fucked[tmp] = true;
    }
    pdd S(0, 0);
    for (int i=N - 1;i>=0;i--) {
        if (fucked[i]) {
            f[i] = pdd(1, 0);
        } else {
            f[i] = pdd(S.first / M, S.second / M + 1.0);
        }
        //printf("%d %.5lf %.5lf\n",i,f[i].first,f[i].second);
        S.first -= f[i + M].first;
        S.second -= f[i + M].second;
        S.first += f[i].first;
        S.second += f[i].second;
    }
    double A = f[0].first;
    double B = f[0].second;
    if (fabs(A - 1.0) < 1e-6) {
        puts("-1");
    } else {
        printf("%.10lf\n",B / (1 - A));
    }
}