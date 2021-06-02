#include <bits/stdc++.h>

using namespace std;

int N, K;
int S[1000010], X[1000010], Y[1000010];
typedef long long LL;

void read(int *v) {
    int A,B,C,D;
    for (int i=1;i<=K;i++) {
        scanf("%d", v + i);
    }
    scanf("%d%d%d%d",&A,&B,&C,&D);
    for (int i=K+1;i<=N;i++) {
        v[i] = (1LL * A * v[i - 2] + 1LL * B * v[i - 1] + C) % D;
    }
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d%d",&N,&K);
        read(S);
        read(X);
        read(Y);
        /*
        for (int i=1;i<=N;i++) {
            printf("%d\n",S[i]);
        }*/
        LL ans = 0;
        LL sum = 0;
        for (int i=1;i<=N;i++) {
            X[i] -= S[i];
            Y[i] += X[i];
            if (Y[i] < 0) {
                sum += Y[i];
                ans += -Y[i];
            } else if (X[i] > 0) {
                sum += X[i];
                ans += X[i];
            }
        }
        for (int i=1;i<=N;i++) {
            if (Y[i] < 0) {
                X[i] -= Y[i];
                Y[i] = 0;
            }
            if (X[i] > 0) {
                Y[i] -= X[i];
                X[i] = 0;
            }
            if (sum > 0) {
                LL delta = min(sum, LL(-X[i]));
                sum -= delta;
                ans += delta;
            } else if (sum < 0) {
                LL delta = min(-sum, LL(Y[i]));
                sum += delta;
                ans += delta;
            }
            if (sum == 0) {
                break;
            }
        }
        if (sum != 0) {
            printf("Case #%d: -1\n", T);
        } else {
            //printf("Case #%d: %lld\n",T, ans);
            assert(ans % 2 == 0);
            ans /= 2;
            printf("Case #%d: %lld\n",T, ans);
        }
    }
}