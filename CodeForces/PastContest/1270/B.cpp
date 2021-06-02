#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int a[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        int ansl, ansr;
        bool ok = false;
        int mi = 1e9 + 1e6, ma = -1e9 - 1e6;
        int miidx, maidx;
        for (int i=1;i<=N;i++) {
            if ((a[i] - i) - mi >= 1) {
                ok = true;
                ansl = miidx;
                ansr = i;
            }
            if ((a[i] + i) - ma <= -1) {
                ok = true;
                ansl = maidx;
                ansr = i;
            }
            if (a[i] - i < mi) {
                mi = a[i] - i;
                miidx = i;
            }
            if (a[i] + i > ma) {
                ma = a[i] + i;
                maidx = i;
            }
        }
        puts(ok ? "YES" : "NO");
        if (ok) {
            printf("%d %d\n",ansl,ansr);
        }
    }
}