#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;


const int MOD = 1e9 + 7;

LL quick_pow(LL a,LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}

LL inv(LL x) {
    return quick_pow(x, MOD - 2);
}

int N;
const int MN = 10000000 + 5;
char s[2 * MN + 10];
LL cnt[2 * MN + 10];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        scanf("%s",s);
        LL ans = 0;
        int bias = MN;
        cnt[bias] = 1;
        for (int i=0;i<N;i++) {
            /*
            for (int j=0;j<=N;j++) {
                printf("%lld ",cnt[bias+j]);
            }
            puts("");
            */
            if (s[i] == '(') {
                bias--;
                cnt[bias] = 1;
            } else if (s[i] == ')') {
                ans = (ans + cnt[bias] * (N - i)) % MOD;
                bias++;
                cnt[bias + 1] += cnt[bias - 1];
                cnt[bias]++;
            } else if (s[i] == '*') {
                cnt[bias]++;
            }
        } 
        for (int i=MN-N-1;i<=MN+N+1;i++) {
            cnt[i] = 0;
        }
        /*
        printf("%lld\n",ans);
        LL ans2 = 0;
        for (int i=0;i<N;i++) {
            for (int j=i;j<N;j++) {
                int S = 0;
                for (int k=i;k<=j;k++) {
                    if (S == 0 && s[k] == ')') {
                        S++;
                        ans2++;
                    } else if (s[k] == ')') {
                        S--;
                    } else if (s[k] == '(') {
                        S++;
                    }
                }
            }
        }
        printf("%lld\n",ans2);
        */
        ans = ans * (2LL * inv(N) * inv(N + 1) % MOD) % MOD;
        printf("%lld\n",ans);
    }
}