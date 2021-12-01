#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int lowbit(int x) {
    return x & -x;
}
const int M = 100001;
int tr[100010];
void add(int x, int y) {
    while(x <= M) {
        tr[x] += y;
        x += lowbit(x);
    }
} 
int getsum(int x) {
    int ret = 0;
    while(x) {
        ret += tr[x];
        x -= lowbit(x);
    }
    return ret;
}

int col[100010];
int n;
int a[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
        }
        for (int i = n; i >= 1; i--) {
            col[i] = getsum(a[i] - 1) % 2;
            add(a[i], 1);
        }
        for (int i = 1; i <= n; i++) add(a[i], -1);
        
        for (int i = 1; i <= n; i++) {
            col[i] ^= (getsum(M) - getsum(a[i])) % 2;
            add(a[i], 1);
        }
        for (int i = 1; i <= n; i++) add(a[i], -1);

        map<int, int> cnt;
        for (int i = 1; i <= n; i++) {
            if (col[i]) cnt[a[i]] += 1;
        }
        bool ok = true;
        for (auto &t : cnt) if (t.second % 2) ok = false;
        puts(ok ? "YES" : "NO");
    }
}