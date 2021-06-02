#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
char s[400010];
int val[400100];
char Q[4] = "WRB";

int CC(int n, int m) {
    int ret = 1;
    for (int i = 1; i <= m; i++) ret = ret * (n + 1 - i);
    for (int i = 1; i <= m; i++) ret = ret / i;
    return ret;
}

int C(int n, int m) {
    if (m > n || m < 0) return 0;
    if (n <= 3) return CC(n, m);
    return C(n / 3, m / 3) * C(n % 3, m % 3) % 3;
}

int main() {
    scanf("%d",&N);
    scanf("%s",s + 1);
    for (int i = 1; i <= N; i++) {
        if (s[i] == 'W') val[i] = 0;
        if (s[i] == 'R') val[i] = 1;
        if (s[i] == 'B') val[i] = 2;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        //printf("%d %d\n",i,C(N-1,i-1));
        ans = ans + val[i] * C(N - 1, i - 1) % 3;
    }
    ans %= 3;
    if (N % 2 == 0) ans = (3 - ans) % 3;
    //printf("%d\n",ans);
    printf("%c\n", Q[ans]);
}