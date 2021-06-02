#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
int N;
pii s[200010];
bool covered[200010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&s[i].first);
    }
    vector<pii> neg;
    vector<pii> event;
    for (int i=1;i<=N;i++) {
        scanf("%d",&s[i].second);
        if (s[i].first - s[i].second > 0) {
            event.emplace_back(s[i].first - s[i].second, 1);
            event.emplace_back(s[i].first + 1, 0);
        } else {
            event.emplace_back(s[i].first, i + 1);
        }
    }
    sort(event.begin(), event.end());
    int cnt = 0;
    for (auto t:event) {
        if (t.second == 1) {
            cnt++;
        } else if (t.second == 0) {
            cnt--;
        } else {
            covered[t.second - 1] = (cnt > 0);
        }
    }
    int back_cnt = 0;
    int ans = 1e9;
    for (int i=N;i>=1;i--) {
        if (s[i].first - s[i].second <= 0) {
            ans = min(ans, max(back_cnt, s[i].second - s[i].first + 1));
            if (!covered[i]) {
                back_cnt++;
            }
        }
    }
    ans = min(ans, back_cnt);
    printf("%d\n",ans);
}