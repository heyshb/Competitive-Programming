#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int cnt[110];
int cnt2[110];

int main() {
    const int TT = 100000;
    for (int T = 1; T <= TT; T++) {
        vector<int> a(100);
        for (int i = 0; i < 100; i++) a[i] = i + 1;
        random_shuffle(a.begin(), a.end());
        int a_min = *min_element(a.begin(), a.begin() + 5);
        int ab_min = *min_element(a.begin(), a.begin() + 10);
        cnt[a_min]++;
        if (a_min == ab_min) cnt2[a_min]++;
    }
    double SS = 0;
    for (int i = 1; i <= 100; i++) {
        SS += 1.0*cnt2[i]/TT;
        printf("%d: %.5lf %.5lf %.5lf %.5lf\n",i,1.0*cnt[i]/TT,1.0*cnt2[i]/TT,1.0*cnt2[i]/cnt[i],SS);
    }
}