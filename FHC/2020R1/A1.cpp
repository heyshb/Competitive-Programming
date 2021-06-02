#include <bits/stdc++.h>

using namespace std;

int N, K, W;
int L[1000010], H[1000010];
typedef long long LL;
const int MOD = 1e9 + 7;

void read(int *v) {
    for (int i=1;i<=K;i++) {
        scanf("%d",v + i);
    }
    int A, B, C, D;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    for (int i=K+1;i<=N;i++) {
        v[i] = (1LL * A * v[i - 2] + 1LL * B * v[i - 1] + C) % D + 1;
    }
}

int q[1000010], head, tail;

int main() {
    freopen("A1_test.txt","r",stdin);
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d%d%d",&N,&K,&W);
        read(L);
        //for (int i=1;i<=N;i++) printf("%d ", L[i]);puts("");
        read(H);
        //for (int i=1;i<=N;i++) printf("%d ", H[i]);puts("");
        LL peri = 2 * (W + H[1]);
        LL ans = peri;
        q[head = tail = 1] = 1;
        for (int i=2;i<=N;i++) {
            LL delta = 2 * (H[i] + W);
            if (L[i] > L[i - 1] + W) {
                peri += delta;
            } else {
                delta -= 2 * (W - (L[i] - L[i - 1]));
                //printf("-= %lld\n", 2 * (W - (L[i] - L[i - 1])));
                while(head <= tail && L[q[head]] + W < L[i]) head++;
                if (head <= tail) {
                    delta -= 2LL * min(H[i], H[q[head]]);
                }
                peri += delta;
                
            }
            while (head <= tail && H[i] > H[q[tail]]) {
                tail--;
            }
            q[++tail] = i;
            //printf("fuck %lld\n",peri);
            peri %= MOD;
            ans = ans * peri % MOD;
        }
        printf("Case #%d: %lld\n",T,ans);
    }
}