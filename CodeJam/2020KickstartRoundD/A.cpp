#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N,a[200010];

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        int ans = 0;
        int mx = -1;
        for (int i=1;i<=N;i++) {
            if (a[i] > mx) {
                mx = a[i];
                if (i == N || a[i] > a[i + 1]) ans++;
            }
        }
        printf("Case #%d: %d\n",T,ans);
    }
}