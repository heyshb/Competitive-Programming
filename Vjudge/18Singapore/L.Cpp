#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MAXN = 400010;
int N, a[MAXN];
int last[MAXN], first[MAXN];
int suc[MAXN], pre[MAXN];
vector<int>pos[MAXN];
int T[4 * MAXN];

void modify(int x,int L,int R,int p,int v) {
    if (L == R) {
        T[x] = v;
        return;
    }
    int mid = (L + R) / 2;
    if (p <= mid) modify(x*2, L, mid, p, v);
    else modify(x*2+1, mid+1, R, p, v);
    T[x] = min(T[x*2], T[x*2+1]);
}

int getmin(int x,int L,int R,int ql,int qr) {
    if (L == ql && R == qr) return T[x];
    int mid = (L + R) / 2;
    if (qr <= mid) return getmin(x*2,L,mid,ql,qr);
    if (ql > mid) return getmin(x*2+1,mid+1,R,ql,qr);
    return min(getmin(x*2,L,mid,ql,mid),getmin(x*2+1,mid+1,R,mid+1,qr));
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=4*N;i++) {
        T[i] = INF;
    }
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        pos[a[i]].push_back(i);
        if (last[a[i]]) suc[last[a[i]]] = i;
        pre[i] = last[a[i]];
        if (first[a[i]] == 0) first[a[i]] = i;
        last[a[i]] = i;
    }
    pii ans(INF, INF);
    for (int i=1;i<=N;i++) {
        if (i != last[a[i]]) {
            int nxt = suc[i];
            if (nxt != i + 1) {
                int mi = getmin(1, 1, N, i + 1, nxt - 1);
                if (mi < INF) {
                    ans = min(ans, pii(mi, a[i]));
                }
            }
        }
        if (i == first[a[i]]) {
            for (auto &t: pos[a[i]]) {
                modify(1, 1, N, t, a[i]);
            }
        }
    }
    if (ans.first == INF) {
        puts("-1");
    } else {
        printf("%d %d\n",ans.first,ans.second);
    }
}