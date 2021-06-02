#include <bits/stdc++.h>

using namespace std;

char s[200010];
int sum[200010];
int N,M;
int one[200010];
int zerosum[200010];
typedef long long LL;
int vv[200010];

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    M = 0;
    
    sum[0] = 0;
    for (int i=1;i<=N;i++) {
        sum[i] = sum[i - 1] + (s[i] == '1');
        if (s[i] == '1') {
            one[++M] = i;
        }
    }
    s[0] = s[N + 1] = '1';
    one[M + 1] = N + 1;
    one[0] = 0;
    for (int i=0;i<=M;i++) {
        zerosum[i] = one[i + 1] - one[i] - 1;
    }
    LL ans = 0;
    int node = 0;
    int MAGIC = 500;
    for (int o=1;o<=MAGIC && o<=M;o++) {
        for (int i=1;i<=N;i++) {
            if (s[i - 1] == '1') {
                node++;
            }
            int R = node + o - 1;
            if (R > M) {
                break;
            }
            int mi = one[R] - i + 1, ma = one[R + 1] - i;
            if (ma <= 1LL * MAGIC * o) continue;
            ans += ma / o - max(MAGIC, (mi - 1) / o);
        }
    }
    int cc = 0;
    for (int k=1;k<=MAGIC;k++) {
        for (int i=0;i<=N;i++) {
            LL tmp = 1LL * i - 1LL * k * sum[i];
            vv[i+1] = tmp;
        }
        sort(vv+1,vv+N+2);
        vv[0] = -1;
        LL nowv = -1e18;
        int nowcnt = 0;
        for (int i=1;i<=N+1;i++) {
            if (vv[i] != vv[i - 1]) {
                nowv = vv[i];
                nowcnt = 1;
            } else {
                ans += nowcnt;
                nowcnt++;
            }
        }
    }
    
    printf("%lld\n",ans);
}