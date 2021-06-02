#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, a[101000], b[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=N;i++) {
            scanf("%d",&b[i]);
        }
        sort(a+1,a+N+1);
        sort(b+1,b+N+1);
        for (int i=1;i<=N;i++) {
            printf("%d%c",a[i]," \n"[i==N]);
        }
        for (int i=1;i<=N;i++) {
            printf("%d%c",b[i]," \n"[i==N]);
        }
    }
}