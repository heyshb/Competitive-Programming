#include <bits/stdc++.h>

using namespace std;

int N;
typedef long long LL;
LL v[200010],s[200010];
map<LL,int>mp;
int ans[200010];
LL f[200010];
int lowbit(int x) {
    return x & -x;
}
LL getsum(int x) {
    LL ret = 0;
    while(x) {
        ret += f[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x,int y) {
    while(x <= N) {
        f[x] += y;
        x += lowbit(x);
    }
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&s[i]);
        v[i] = v[i - 1] + i;
        mp[v[i]] = i;
    }
    LL S = 0;
    for (int i=N;i>=1;i--) {
        int L = 1, R = N + 1;
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (v[mid - 1] - getsum(mid - 1) <= s[i]) {
                L = mid;
            } else {
                R = mid;
            }
        }
        ans[i] = L;
        add(L,L);
    }
    for (int i=1;i<=N;i++) {
        printf("%d%c",ans[i]," \n"[i==N]);
    }
}