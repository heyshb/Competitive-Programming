#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int MAXN = 1000010;
int N, M, P;
pii a[MAXN], b[MAXN];
struct monster {
    int x,y,z;
}m[4 * MAXN];
vector<pii>e[MAXN];

LL mx[4 * MAXN], tag[4 * MAXN];

void maintain(int x) {
    mx[x] = max(mx[x * 2], mx[x * 2 + 1]);
}

void build(int x,int L,int R) {
    if (L == R) {
        tag[x] = 0;
        mx[x] = -b[L].second;
        return;
    }
    int mid = (L + R) / 2;
    build(x*2,L,mid);
    build(x*2+1,mid+1,R);
    maintain(x);
}

void pushdown(int x) {
    if (!tag[x]) return;
    mx[x * 2] += tag[x];
    mx[x * 2 + 1] += tag[x];
    tag[x * 2] += tag[x];
    tag[x * 2 + 1] += tag[x];
    tag[x] = 0;
}

void update(int x,int L,int R,int ql,int qr,int delta) {
    if (L == ql && R == qr) {
        mx[x] += delta;
        tag[x] += delta;
        return;
    }
    pushdown(x);
    int mid = (L + R) / 2;
    if (qr <= mid) {
        update(x*2,L,mid,ql,qr,delta);
    } else if (ql > mid) {
        update(x*2+1,mid+1,R,ql,qr,delta);
    } else {
        update(x*2,L,mid,ql,mid,delta);
        update(x*2+1,mid+1,R,mid+1,qr,delta);
    }
    maintain(x);
}

LL getmx(int x,int L,int R,int ql,int qr) {
    if (L == ql && R == qr) {
        return mx[x];
    }
    pushdown(x);
    int mid = (L + R) / 2;
    if (qr <= mid) {
        return getmx(x*2,L,mid,ql,qr);
    } else if (ql > mid) {
        return getmx(x*2+1,mid+1,R,ql,qr);
    } else {
        return max(getmx(x*2,L,mid,ql,mid), getmx(x*2+1,mid+1,R,mid+1,qr));
    }
}

int main() {
    scanf("%d%d%d",&N,&M,&P);
    for (int i=1;i<=N;i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+N+1);
    for (int i=1;i<=M;i++) {
        scanf("%d%d",&b[i].first,&b[i].second);
    }
    sort(b+1,b+M+1);
    for (int i=N-1;i>=1;i--) {
        a[i].second = min(a[i].second, a[i + 1].second);
    }
    a[N + 1].second = 1e9;
    for (int i=M-1;i>=1;i--) {
        b[i].second = min(b[i].second, b[i + 1].second);
    }
    b[M + 1].second = 1e9;
    for (int i=1;i<=P;i++) {
        scanf("%d%d%d",&m[i].x,&m[i].y,&m[i].z);
        m[i].x = lower_bound(a + 1, a + N + 1, pii(m[i].x + 1, 0)) - a;
        m[i].y = lower_bound(b + 1, b + M + 1, pii(m[i].y + 1, 0)) - b;
        //printf("%d %d\n",m[i].x,m[i].y);
        if (m[i].x <= N && m[i].y <= M) {
            e[m[i].x].push_back(pii(m[i].y, m[i].z));
        }
    }
    build(1,1,M);
    LL ans = -1e18;
    for (int i=1;i<=N;i++) {
        for (auto t:e[i]) {
            update(1,1,M,t.first,M,t.second);
        }
        LL tmp = getmx(1,1,M,1,M);
        ans = max(ans, tmp - a[i].second);
    }
    printf("%lld\n",ans);
}