#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
int N;
int a[100010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+N+1);
    int ans = 1;
    for (int i = 0; i < N; i++) {
        ans = 1LL * ans * (a[i + 1] - a[i] + 1) % MOD;
    }
    printf("%d\n",ans);
}