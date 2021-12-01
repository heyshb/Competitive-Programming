#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, Q;
char s[200010];
char t[200010];
int per[4];
int sum[6][200010];

int main() {
    int n, Q;
    scanf("%d%d",&n,&Q);
    scanf("%s", s + 1);
    for (int i = 0; i < 3; i++) {
        per[i] = i;
    }
    int M = 0;
    do {
        for (int i = 1; i <= n; i++) {
            t[i] = 'a' + per[i % 3];
        }
        for (int i = 1; i <= n; i++) {
            sum[M][i] = sum[M][i - 1] + (t[i] != s[i]);
        }
        M++;
    }while(next_permutation(per, per + 3));
    while(Q--) {
        int L, R;
        scanf("%d%d",&L,&R);
        int ans = 1e9;
        for (int i = 0; i < 6; i++) {
            ans = min(ans, sum[i][R] - sum[i][L - 1]);
        }
        printf("%d\n",ans);
    }
}