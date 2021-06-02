#include <bits/stdc++.h>

using namespace std;

char s[200010];
int sum[200010];
int N,M;
int one[200010];
int zerosum[200010];
typedef long long LL;

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    M = 0;
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
    int MAGIC = 450;
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
    printf("%lld\n",ans);
    unordered_map<LL,int>mp;
    for (int k=1;k<=MAGIC;k++) {
        mp.clear();
        for (int i=0;i<=N;i++) {
            LL tmp = i - 1LL * k * sum[i];
            if (mp.find(tmp) != mp.end()) {
                ans += mp[tmp];
                mp[tmp]++;
            } else {
                mp[tmp] = 1;
            }
        }
    }
    printf("%lld\n",ans);
}