#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, N;
int a[110];

int solve() {
    bool asc = true;
    for (int i = 2; i <= N; i++) {
        if (a[i] < a[i - 1]) asc = false;
    }
    if (asc) return 0;
    if (a[1] == N && a[N] == 1) return 3;
    if (a[1] == 1 || a[N] == N) return 1;
    return 2;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i = 1; i <= N; i++) {
            scanf("%d",&a[i]);
        }
        printf("%d\n",solve());
    }
}