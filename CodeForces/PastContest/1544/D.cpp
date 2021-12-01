#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int ind[200010], oud[200010], b[200010], a[200010];
int fuck[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) ind[i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d",&b[i]);
            ind[b[i]]++;
            oud[i]++;
            fuck[i] = 0;
            a[i] = 0;
        }
        queue<int>q;
        for (int i = 1; i <= n; i++) {
            if (ind[i] == 0) {
                printf("i=%d\n",i);
                int last = -1;
                for (int j = i; !a[j]; j = b[j]) {
                    a[j] = b[j];
                    printf("a[%d]=%d\n",j,a[j]);
                    fuck[j] = i;
                    last = j;
                }
                a[last] = i;
                printf("fix %d = %d\n",last,i);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!a[i]) a[i] = b[i];
            ans += (a[i] == b[i]);
        }
        printf("%d\n",ans);
        for (int i = 1; i <= n; i++) {
            printf("%d%c",a[i]," \n"[i==n]);
        }
    }
}