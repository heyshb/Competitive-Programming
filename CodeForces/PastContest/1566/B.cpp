#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int have_0 = 0;
        int mi1 = n + 1;
        int ma1 = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                have_0 = 1;
            }
            if (s[i] == '1') {
                mi1 = min(mi1, i);
                ma1 = max(ma1, i);
            }
        }
        if (!have_0) {
            puts("0");
            continue;
        }
        if (ma1 == 0) {
            puts("1");
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] != '1' && (i == 1 || s[i - 1] == '1')) {
                cnt++;
            }
        }
        if (cnt > 1) puts("2");
        else puts("1");
    }
}