#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int n;
int a[100010];
int b[100010];

LL calc() {
    vector<int> pa, pb;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) pa.push_back(i);
        if (b[i] == 1) pb.push_back(i);
    }
    LL cnt = 0;
    for (int i = 0; i < pa.size(); i++) {
        cnt += abs(pa[i] - pb[i]);
    }
    return cnt;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int cnt[2] = {0, 0};
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
            a[i] %= 2;
            cnt[a[i]]++;
        }
        if (abs(cnt[0] - cnt[1]) > 1) {
            puts("-1");
            continue;
        }
        LL ans = 1e9;
        if (cnt[0] != cnt[1]) {
            if (cnt[0] > cnt[1]) {
                b[1] = 0;
            } else {
                b[1] = 1;
            }
            for (int i = 2; i <= n; i++) {
                b[i] = 1 - b[i - 1];
            }
            ans = calc();
        } else {
            for (int b1 = 0; b1 <= 1; b1++) {
                b[1] = b1;
                for (int i = 2; i <= n; i++) {
                    b[i] = 1 - b[i - 1];
                }
                ans = min(ans, calc());
            }
        }
        printf("%lld\n",ans);
    }
}