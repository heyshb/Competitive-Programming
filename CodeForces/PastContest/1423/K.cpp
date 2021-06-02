#include <bits/stdc++.h>

using namespace std;

const int M = 1000000;
bool ok[M + 10];
int cnt;
int mp[M + 10], prime[M + 10];
int sum[M + 10];
int min_partner[M + 10];

int main() {
    memset(ok, true, sizeof(ok));
    cnt = 0;
    for (int i=2;i<=M;i++) {
        if (ok[i]) {
            prime[++cnt] = i;
            mp[i] = i;
        }
        for (int j=1;j<=cnt && i * prime[j] <= M;j++) {
            ok[i * prime[j]] = false;
            mp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    sum[1] = 1;
    for (int i=2;i<=M;i++) {
        sum[i] += sum[i - 1];
        if (ok[i]) {
            sum[i] = sum[i - 1] + int(ok[i]);
            if (1LL * i * i <= M) sum[i * i]--;
        }
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        printf("%d\n",sum[N]);
    }
}