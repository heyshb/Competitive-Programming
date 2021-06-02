#include <bits/stdc++.h>

typedef long long LL;
using namespace std;
char ch[100];

bool ask(LL x) {
    printf("? %lld\n",x);
    fflush(stdout);
    scanf("%s", ch);
    return (ch[0] == 'L');
}

void answer(LL x) {
    printf("! %lld\n",x);
    fflush(stdout);
}

void solve() {
    if (!ask(1)) {
        answer(0);
        return;
    }
    LL cash = 2;
    LL L = 1, R = 1e14 + 1;
    while(L < R - 1) {
        LL mid = (L + R) / 2;
        mid = min(mid, LL(L + cash * 0.44 + 1));
        mid = min(mid, cash - 1);
        mid = max(mid, L);
        if (ask(mid)) {
            cash += mid;
            L = mid;
        } else {
            cash -= mid;
            R = mid;
        }
    }
    answer(L);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        solve();
    }
}