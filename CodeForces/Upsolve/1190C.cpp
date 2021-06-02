#include <bits/stdc++.h>

using namespace std;

int N, K;
char s[100010];
int sum[100010];
int nxt[100010][2], lst[100010][2];

int main() {
    scanf("%d%d",&N,&K);
    scanf("%s", s + 1);
    for (int i=1;i<=N;i++) {
        s[i]  -= '0';
        sum[i] = sum[i - 1] + s[i];
    }
    lst[0][0] = lst[0][1] = 0;
    for (int i=1;i<=N;i++) {
        lst[i][0] = lst[i - 1][0];
        lst[i][1] = lst[i - 1][1];
        lst[i][s[i]] = i;
    }
    nxt[N + 1][0] = nxt[N + 1][1] = N + 1;
    for (int i=N;i>=1;i--) {
        nxt[i][0] = nxt[i + 1][0];
        nxt[i][1] = nxt[i + 1][1];
        nxt[i][s[i]] = i;
    }
    for (int i=K;i<=N;i++) {
        int ts = sum[i - K] + sum[N] - sum[i];
        if (ts == N - K || ts == 0) {
            puts("tokitsukaze");
            return 0;
        }
    }
    bool draw = false;
    for (int i=K;i<=N;i++) {
        for (int j=0;j<=1;j++) {
            // set (j ^ 1) on (i - K, i]
            if (lst[i - K][j] != 0 && nxt[i + 1][j] != N + 1) {
                draw = true;
            }
            if (lst[i - K][j] == 0) {
                int p = nxt[i + 1][j];
                p = nxt[min(p + K, N + 1)][j];
                if (p != N + 1) {
                    draw = true;
                }
            }
            if (nxt[i + 1][j] == N + 1) {
                int p = lst[i - K][j];
                p = lst[max(p - K, 0)][j];
                if (p != 0) {
                    draw = true;
                }
            }
        }
        if (draw) {
            puts("once again");
            return 0;
        }
    }
    puts("quailty");
    return 0;
}