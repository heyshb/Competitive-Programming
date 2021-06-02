#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, a[200100];
int f[200010];

int main() {
    int T;
    scanf("%d",&T);    
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=2*N+1;i++) f[i] = 0;
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            f[a[i]]++;
        }
        set<int>s;
        for (int i=1;i<=2*N+1;i++) {
            if (f[i] > 1) f[i+1]++;
        }
        int ans = 0;
        for (int i=1;i<=2*N+1;i++) {
            if (f[i]) ans++;
        }
        printf("%d\n",ans);
    }
}