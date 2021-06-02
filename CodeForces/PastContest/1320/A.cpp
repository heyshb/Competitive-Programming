#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

int N, b[200010];
int bias = 200000;
LL  S[1000010];
int main() {
    scanf("%d",&N);
    LL ans = 0;
    for (int i=1;i<=N;i++ ){
        scanf("%d",&b[i]);
        S[b[i] - i + bias] += b[i];
        ans = max(ans, S[b[i] - i + bias]);
    }
    printf("%lld\n",ans);
}