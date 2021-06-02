#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N, k1, k2;
        scanf("%d%d%d",&N,&k1,&k2);
        int m1 = 0, m2 = 0;
        for (int i=1;i<=k1;i++) {
            int tmp;
            scanf("%d",&tmp);
            m1 = max(m1, tmp);
        }
        for (int i=1;i<=k2;i++) {
            int tmp;
            scanf("%d",&tmp);
            m2 = max(m2, tmp);
        }
        puts(m1 > m2 ? "YES" : "NO");

    }
}