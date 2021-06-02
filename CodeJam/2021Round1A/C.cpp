#include <bits/stdc++.h>

using namespace std;

int N, Q;
char s[10][1010];
int answer[100];
int score[100];
bool ok[1024];
int cnt[100];
char my_ans[100];

int main() {
    int T;
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        memset(s,0,sizeof(s));
        memset(answer,0,sizeof(answer));
        memset(score,0,sizeof(score));
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d",&N,&Q);
        for (int i=1;i<=N;i++) {
            scanf("%s", s[i]);
            answer[i] = 0;
            for (int j=Q-1;j>=0;j--) {
                answer[i] = (answer[i] << 1) | (s[i][j] == 'T');
            }
            scanf("%d",&score[i]);
        }
        memset(ok, true, sizeof(ok));
        int sum_ok = 0;
        for (int cand=0;cand<(1<<Q);cand++) {
            for (int i=1;i<=N;i++) {
                int xo = answer[i] ^ cand;
                if (__builtin_popcount(xo) != Q - score[i]) {
                    ok[cand] = false;
                }
            }
            if (ok[cand]) {
                sum_ok++;
                for (int i=0;i<Q;i++) {
                    if (cand & (1 << i)) {
                        cnt[i]++;
                    }
                }
            }
        }
        my_ans[Q] = 0;
        int expected = 0;
        for (int i=0;i<Q;i++) {
            if (cnt[i] > sum_ok - cnt[i]) {
                my_ans[i] = 'T';
                expected += cnt[i];
            } else {
                my_ans[i] = 'F';
                expected += sum_ok - cnt[i];
            }
        }
        int g = __gcd(sum_ok, expected);
        printf("Case #%d: %s %d/%d\n",++Case,my_ans,expected/g,sum_ok/g);
    }
}