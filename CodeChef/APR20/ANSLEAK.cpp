#include <bits/stdc++.h>

using namespace std;

int correct_answer[510][5010];
int N, M, K;
std::mt19937 rnd(time(NULL));
int now[510], ans[510];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&M,&K);
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=K;j++) {
                scanf("%d",&correct_answer[i][j]);
            }
        }
        int max_min_score = 0;
        for (int t=1;t<=700;t++) {
            for (int i=1;i<=N;i++) {
                now[i] = rnd() % M + 1;
            }
            int min_score = 1e9;
            for (int j=1;j<=K;j++) {
                int cnt = 0;
                for (int i=1;i<=N;i++) {
                    cnt += (now[i] == correct_answer[i][j]);
                }
                min_score = min(min_score, cnt);
            }
            if (min_score > max_min_score) {
                max_min_score = min_score;
                for (int i=1;i<=N;i++) {
                    ans[i] = now[i];
                }
            }
        }
        for (int i=1;i<=N;i++) {
            printf("%d%c", ans[i], " \n"[i==N]);
        }
    }
}