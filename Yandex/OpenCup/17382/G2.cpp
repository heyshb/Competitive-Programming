#include <bits/stdc++.h>

using namespace std;

int match, N, M, S;
int a[200010], b[200010];
bool matched[200010];
typedef pair<int,int> pii;
int L[200010], R[200010];

pii get_idx(int down,int up) {
    int L = lower_bound(b + 1, b + M + 1, down) - b;
    int R = upper_bound(b + 1, b + M + 1, up) - b;
    R--;
    if (L > R || L > M || R > M || L < 1 || R < 1) return pii(-1, -1);
    return pii(L, R);
}

set<pii> st;
vector<int>event[200010];

bool check(int d) {
    for (int i=1;i<=M+1;i++) {
        event[i].clear();
    }
    for (int i=1;i<=N;i++) {
        auto it = get_idx(a[i] - d, min(a[i] + d, S - a[i]));
        L[i] = it.first;
        R[i] = it.second;
        if (L[i] == -1) continue;
        event[L[i]].push_back(i);
        event[R[i] + 1].push_back(-i);
    }
    st.clear();
    int cnt = 0;
    for (int i=1;i<=M;i++) {
        for (auto e:event[i]) {
            int idx = abs(e);
            if (e > 0) {
                st.insert(pii(R[idx], idx));
            } else {
                if (st.find(pii(R[idx], idx)) != st.end()) {
                    st.erase(pii(R[idx], idx));
                }
            }
        }
        if (!st.empty()) {
            cnt++;
            st.erase(st.begin());
        }
    }
    return cnt >= match;
}

int main() {
    scanf("%d%d%d%d",&match, &N, &M, &S);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=M;i++) {
        scanf("%d",&b[i]);
    }
    sort(a + 1, a + N + 1);
    sort(b + 1, b + M + 1);
    int L = 0, R = 1e9 + 10;
    if (check(0)) {
        puts("0");
        return 0;
    }
    if (!check(R)) {
        puts("-1");
        return 0;
    }
    while(L < R - 1) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    printf("%d\n",R);
}