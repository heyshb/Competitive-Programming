#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL calc(LL x) {
    LL ret = x * (x - 1) / 2;
    ret -= x / 2;
    ret /= 2;
    return ret;
}

int N, M;
int cnt[2000010];

int main() {
    scanf("%d%d",&N, &M);
    if (M == 0) {
        for (int i=1;i<=N;i++) {
            printf("%d%c", 1000000 + i," \n"[i==N]);
        }
        return 0;
    }
    if (calc(N) < M) {
        puts("-1");
        return 0;
    }

    for (int i=1;i<=N;i++) {
        if (calc(i) < M) {
            continue;
        }
        
        for (int j=1;j<i;j++) {
            for (int k=j+1;k<i;k++) {
                cnt[j + k]++;
            }
        }

        for (int j=1;j<i;j++) {
            printf("%d ",j);
        }

        for (int j=i;j<=2*(i-1);j++) {
            if (cnt[j] == M - calc(i - 1)) {
                printf("%d ",j);
                break;
            } 
        }
        const int INF = 1e8;
        for (int j=i+1;j<=N;j++) {
            printf("%d%c",INF + (j - i) * 5 * N, " \n"[j==N]);
        }
        return 0;
    }
}