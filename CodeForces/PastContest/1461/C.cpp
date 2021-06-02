#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T, N, M;
double P;
int a[100010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        int fuck = N + 1;
        for (int i=N;i>=1;i--) {
            if (a[i] != i) {
                fuck = i;
                break;
            }
        }
        double fail = 1;
        for (int i=1;i<=M;i++) {
            int p;
            double r;
            scanf("%d%lf",&p,&r);
            if (p < fuck) continue;
            fail *= (1 - r);
        }
        if (fuck == N + 1) fail = 0;
        printf("%.10lf\n",1 - fail);
    }
}