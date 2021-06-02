#include <bits/stdc++.h>

using namespace std;

int N;
int ans[2010][2010];

int main() {
    scanf("%d",&N);
    if (N % 2 == 1) {
        puts("Boo");
        return 0;
    }
    puts("Hooray");
    for (int i=1;i<=N;i++) {
        ans[i][i] = 1;
        ans[i][1] = i;
    }
    for (int i=2;i<=N;i++) {
        for (int j=2;j<i;j++) {
            ans[i][j] = ans[i][j-1] + 1;
            if (ans[i][j] > N) {
                ans[i][j] -= N - 1;
            }
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            ans[i][j] = ans[j][i] + N - 1;
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            printf("%d%c",ans[i][j]," \n"[j==N]);
        }
    }
}