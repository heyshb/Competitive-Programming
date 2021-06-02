#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

int N, C[510][510], A[510], B[510];

int main() {
    scanf("%d",&N);
    int minv = 1e9 + 10, mini = -1, minj = -1;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d",&C[i][j]);
            if (C[i][j] < minv) {
                minv = C[i][j];
                mini = i;
                minj = j;
            }
        }
    }
    bool ok = true;
    for (int i=2;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (C[i][j] - C[i-1][j] != C[i][1] - C[i-1][1]) ok = false;
            if (C[j][i] - C[j][i-1] != C[1][i] - C[1][i-1]) ok = false;
        }
    }
    if (!ok) {puts("No");return 0;}
    puts("Yes");
    A[mini] = 0;
    B[minj] = minv;
    for (int i=1;i<=N;i++) {
        B[i] = C[mini][i];
        A[i] = C[i][minj] - minv;
    }
    for (int i=1;i<=N;i++) printf("%d%c",A[i]," \n"[i==N]);
    for (int i=1;i<=N;i++) printf("%d%c",B[i]," \n"[i==N]);
}