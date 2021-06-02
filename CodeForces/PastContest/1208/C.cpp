#include <bits/stdc++.h>

using namespace std;

int ans[1010][1010];
int N;
int main() {
    scanf("%d",&N);
    int M = 0;
    for (int i=0;i<N;i+=2) {
        for (int j=0;j<N;j+=2,M+=4) {
            ans[i][j] = M;
            ans[i][j+1] = M + 3;
            ans[i+1][j] = M + 1;
            ans[i+1][j+1] = M + 2;
        }
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            printf("%d%c",ans[i][j]," \n"[j==N-1]);
        }
    }
}