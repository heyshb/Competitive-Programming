#include <bits/stdc++.h>

using namespace std;

int T, N;
int a[100010];
bool cut[100010];
int cnt[100010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            cnt[i] = 0;
            cut[i] = false;
        }
        int K = 1;
        cnt[a[1]]++;
        cnt[a[N]]++;
        for (int i=1;i<N;i++) {
            if (a[i] == a[i + 1]) {
                cnt[a[i]]++;
                cnt[a[i+1]]++;
                cut[i] = true;
                K++;
            }
        }
        int mx = 0, id = 0;
        for (int i=1;i<=N;i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                id = i;
            }
        }
        if (mx <= K + 1) {
            printf("%d\n",K - 1);
            continue;
        }
        for (int i=1;i<N;i++) {
            if (a[i] != id && a[i + 1] != id && !cut[i]) {
                K++;
                if (mx <= K + 1) break;
            }
        }
        if (mx <= K + 1) {
            printf("%d\n",K - 1);
        } else {
            puts("-1");
        }
    }
}