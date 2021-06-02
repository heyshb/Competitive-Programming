#include <bits/stdc++.h>

using namespace std;

int match, N, M, S;
int a[200010], b[200010];
bool matched[200010];
typedef pair<int,int> pii;

pii get_idx(int down,int up) {
    int L = lower_bound(b + 1, b + M + 1, down) - b;
    int R = upper_bound(b + 1, b + M + 1, up) - b;
    R--;
    if (L > R || L > M || R > M || L < 1 || R < 1) return pii(-1, -1);
    return pii(L, R);
}

multiset<pii> st;

void add(int idx) {
    st.insert(pii(b[idx], idx));
}

void del(int idx) {
    auto it = st.find(pii(b[idx], idx));
    assert(it != st.end());
    st.erase(it);
}

bool check(int d) {
    int cnt = 0;
    int split = 0;
    for (int i=N;i>=1;i--) {
        if (a[i] + d <= S - a[i]) {
            split = i;
            break;
        }
    }
    int Lnode = 1, Rnode = 0;
    for (int i=1;i<=M;i++) {
        matched[i] = false;
    }
    //printf("check %d\n",d);
    for (int i=N;i>=1;i--) {
        pii idx = get_idx(a[i] - d, min(a[i] + d, S - a[i]));
        int L = idx.first, R = idx.second;
        //printf("%d %d %d\n",i, L, R);
        if (L == -1) continue;
        while(Lnode > L && !matched[Lnode - 1]) {
            add(--Lnode);
        }
        while(Rnode < R && !matched[Rnode + 1]) {
            add(++Rnode);
        }
        while(Lnode < L && !matched[Lnode]) {
            del(Lnode++);
        }
        while(Rnode > R && !matched[Rnode]) {
            del(Rnode--);
        }
        if (st.empty()) continue;
        auto it = st.end();
        --it;
        int match_idx = it->second;
        //printf("match %d %d\n",i, match_idx);
        matched[match_idx] = true;
        cnt++;
        st.erase(it);
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