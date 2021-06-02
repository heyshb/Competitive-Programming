#include <bits/stdc++.h>

using namespace std;

int N, a[300010], b[300010], c[300010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) scanf("%d",&a[i]);
        b[1] = a[1];
        c[1] = 0;
        bool ok = true;
        for (int i=2;i<=N;i++) {
            if (b[i - 1] + c[i - 1] >= a[i]) {
                c[i] = c[i - 1];
                b[i] = a[i] - c[i];
            } else {
                b[i] = b[i - 1];
                c[i] = a[i] - b[i];
            }
            if (b[i] < 0 || c[i] < 0) ok = false;
        }
        puts(ok ? "YES" : "NO");
    }
}