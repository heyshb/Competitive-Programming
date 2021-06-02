#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
int N, M, Q;
pii p[200010];
LL gao[200010][2][3];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d",&p[i].first,&p[i].second);
    }
    scanf("%d",&M);
    gao[0][0][0] = 1;
    gao[0][1][1] = 1;
    for (int i=1;i<=M;i++) {
        int op, p;
        scanf("%d",&op);
        if (op > 2) scanf("%d",&p);
        if (op == 1) {
            for (int j=0;j<3;j++) {
                gao[i][0][j] = gao[i-1][1][j];
                gao[i][1][j] = -gao[i-1][0][j];
            }
        }
        if (op == 2) {
            for (int j=0;j<3;j++) {
                gao[i][0][j] = -gao[i-1][1][j];
                gao[i][1][j] = gao[i-1][0][j];
            }
        }
        if (op == 3) {
            for (int j=0;j<3;j++) {
                gao[i][1][j] = gao[i-1][1][j];
                gao[i][0][j] = -gao[i-1][0][j];
            }
            gao[i][0][2] += 2LL * p;
        }
        if (op == 4) {
            for (int j=0;j<3;j++) {
                gao[i][1][j] = -gao[i-1][1][j];
                gao[i][0][j] = gao[i-1][0][j];
            }
            gao[i][1][2] += 2LL * p;
        }
    }
    scanf("%d",&Q);
    auto calc = [&](LL A, LL B, LL c0, LL c1, LL c2) {
        return c0 * A + c1 * B + c2;
    };
    while(Q--) {
        LL A, B;
        scanf("%lld%lld",&A,&B);
        printf("%lld %lld\n",calc(p[B].first, p[B].second, gao[A][0][0], gao[A][0][1], gao[A][0][2]), 
                             calc(p[B].first, p[B].second, gao[A][1][0], gao[A][1][1], gao[A][1][2]));
    }
}