#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[100100][5];

bool better(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (a[x][i] < a[y][i]) cnt++;
    }
    return cnt >= 3;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d",&a[i][j]);
            }
        }
        int best = 1;
        for (int i = 2; i <= n; i++) {
            if (better(i, best)) best = i;
        }
        int ans = best;
        for (int i = 1; i <= n; i++) {
            if (i != best && !better(best, i)) {
                ans = -1;
            }
        }
        printf("%d\n",ans);
    }    
}