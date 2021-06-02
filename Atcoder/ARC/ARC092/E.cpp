#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
int main() {
    int N;
    scanf("%d",&N);
    vector<int> a(N+1);
    LL sum_odd = 0, sum_even = 0;
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        if (i % 2 == 1) sum_odd += max(0, a[i]);
        else sum_even += max(0, a[i]);
    }
    int flag = (sum_odd > sum_even ? 1 : 0);
    int idx = -1;
    LL max_sum = max(sum_odd, sum_even);
    if (max_sum <= 0) {
        idx = max_element(a.begin() + 1, a.begin() + N + 1) - a.begin();
        max_sum = a[idx];
    }
    int last_remain = -1;
    vector<int>ans;
    for (int i=N;i>=1;i--) {
        if ((i % 2 == flag && a[i] > 0) || (i == idx)) {
            if (last_remain == -1) {
                for (int j=N;j>i;j--) {
                    ans.push_back(j);
                }
            } else {
                for (int j=last_remain-2;j>=i+2;j-=2) {
                    ans.push_back(j);
                }
                ans.push_back(i + 1);
            }
            last_remain = i;
        }
    }
    for (int i=0;i<last_remain-1;i++) {
        ans.push_back(1);
    }
    printf("%lld\n",max_sum);
    printf("%d\n",ans.size());
    for (auto &t:ans) {
        printf("%d\n",t);
    }
}