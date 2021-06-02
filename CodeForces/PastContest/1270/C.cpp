#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL a[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        LL A = 0,B = 0;
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
            A += a[i];
            B ^= a[i];
        }
        LL v1 = (1LL << 58) + A % 2;
        A += v1;
        B ^= v1;
        B *= 2;
        LL v2 = (B - A) / 2;
        puts("3");
        printf("%lld %lld %lld\n",v1,v2,v2);
        a[N+1]=v1;a[N+2]=v2;a[N+3]=v2;
        A = 0, B = 0;
        for (int i=1;i<=N+3;i++) {
            A += a[i];
            B ^= a[i];
        }
        printf("%lld %lld\n",A,B*2);
    }
}