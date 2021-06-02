#include <bits/stdc++.h>

using namespace std;

int N;
const int INF = 0;
typedef pair<int,int> pii;
int lowbit(int x) {
    return x & -x;
}
int tr[500010];
int get_max(int x) {
    int ret = 0;
    while(x) {
        ret = max(ret, tr[x]);
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int y) {
    printf("add %d %d\n",x,y);
    while(x <= N) {
        tr[x] = max(tr[x], y);
        x += lowbit(x);
    }
}

int f[500010], a[500010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<=N;i++) {
            tr[i] = 0;
        }
        vector<int>stk;
        for (int i=1;i<=N;i++) {
            f[i] = get_max(a[i]) + 1;
            printf("f[%d]=%d\n",i,f[i]);
            add(a[i], f[i]);
            while(!stk.empty() && a[stk.back()] >= a[i]) {
                int idx = stk.back();
                add(a[idx], f[idx] + 1);
                //f[idx]++;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        int ans = *max_element(f + 1, f + N + 1);
        printf("%d\n",ans);
    }
}