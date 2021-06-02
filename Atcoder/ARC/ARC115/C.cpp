#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
int N, col[100010];
bool vis[100010];
int main() {
    scanf("%d",&N);
    col[1] = 1;
    for (int i=2;i<=N;i++) {
        for (int j=1;j*j<=i;j++) {
            if (i % j == 0) {
                vis[col[j]] = true;
                vis[col[i/j]] = true;
            }
        }
        for (int k=1;;k++) {
            if (!vis[k]) {
                col[i] = k;
                break;
            }
        }
        for (int j=1;j*j<=i;j++) {
            if (i % j == 0) {
                vis[col[j]] = false;
                vis[col[i/j]] = false;
            }
        }
    }
    for (int i=1;i<=N;i++) printf("%d%c",col[i]," \n"[i==N]);
}