#include <bits/stdc++.h>

using namespace std;

int N, a[100010];
int cnt[100010];
map<int,int> mi, mx;
typedef long long LL;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            cnt[i] = cnt[i - 1];
            a[i] = abs(a[i]);
            while(a[i] > 0 && a[i] % 2 == 0) {
                a[i] /= 2;
                cnt[i]++;
            }
        }
        int node1 = 1, node2 = 1;
        LL ans = 0;
        for (int i=0;i<N;i++) {
            while(node1 <= N && cnt[node1] <= cnt[i]) node1++;
            while(node2 <= N && cnt[node2] <= cnt[i] + 1) node2++;
            ans += N - i - (node2 - node1);
        }
        printf("%lld\n",ans);
    }
}