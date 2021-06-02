#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, k;
int a[40010];
LL f[110][40010];
int pre[40010], d[40010];
map<int, int> pos;
const int MM = 400010;
LL mi[MM], tag[MM];
LL b[40010];
const LL INF = 1e18;

void pushdown(int x) {
    if (tag[x]) {
        tag[x * 2] += tag[x];
        tag[x * 2 + 1] += tag[x];
        mi[x * 2] += tag[x];
        mi[x * 2 + 1] += tag[x];
        tag[x] = 0;
    }
}

void upd(int x) {
    mi[x] = min(mi[x * 2], mi[x * 2 + 1]);
}

void build(int x, int L, int R) {
    tag[x] = 0;
    if (L == R) {
        //mi[x] = b[L];
        mi[x] = 0;
        return;
    }
    int mid = (L + R) / 2;
    build(x * 2, L, mid);
    build(x * 2 + 1, mid + 1, R);
    upd(x);
}

void modify(int x, int L, int R, int ql, int qr, LL D) {
    pushdown(x);
    if (L == ql && R == qr) {
        mi[x] += D;
        tag[x] += D;
        return;
    }
    int mid = (L + R) / 2;
    if (qr <= mid) modify(x * 2, L, mid, ql, qr, D);
    else if (ql > mid) modify(x * 2 + 1, mid + 1, R, ql, qr, D);
    else {
        modify(x * 2, L, mid, ql, mid, D);
        modify(x * 2 + 1, mid + 1, R, mid + 1, qr, D);
    }
    upd(x);
}

LL query(int x, int L, int R, int ql, int qr) {
    pushdown(x);
    if (ql == L && qr == R) return mi[x];
    int mid = (L + R) / 2;
    if (qr <= mid) return query(x * 2, L, mid, ql, qr);
    else if (ql > mid) return query(x * 2 + 1, mid + 1, R, ql, qr);
    else return min(query(x * 2, L, mid, ql, mid), query(x * 2 + 1, mid + 1, R, mid + 1, qr));
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        if (pos.find(a[i]) == pos.end()) {
            pre[i] = i;
        } else {
            pre[i] = pos[a[i]];
        }
        pos[a[i]] = i;
        d[pre[i]] = i - pre[i];
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = 1e18;
        }
    }
    f[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        build(1, 0, n);
        for (int j = 1; j <= n; j++) {
            modify(1, 0, n, j, j, f[i - 1][j]);
            //printf("modify %d %d %lld\n",j,j,f[i-1][j]);
            if (pre[j] != j) {
                modify(1, 0, n, 0, pre[j] - 1, d[pre[j]]);
                //printf("modify %d %d %lld\n",0,pre[j]-1,d[pre[j]]);
            }
            f[i][j] = query(1, 0, n, 0, j - 1);
            //printf("f[%d][%d] = %lld\n",i,j,f[i][j]);
        }
    }
    printf("%lld\n",f[k][n]);
}