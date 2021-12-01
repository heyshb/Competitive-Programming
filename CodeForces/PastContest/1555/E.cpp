#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

struct seg {
    int l, r, w;
}s[300010];

const int MM = 4000010;
int T[MM], tag[MM];

int n, m;
void pushdown(int x) {
    if (tag[x]) {
        tag[x * 2] += tag[x];
        tag[x * 2 + 1] += tag[x];
        T[x * 2] += tag[x];
        T[x * 2 + 1] += tag[x];
        tag[x] = 0;
    }
}
void add(int x, int L, int R, int ql, int qr, int val) {
    if (ql == L && qr == R) {
        T[x] += val;
        tag[x] += val;
        return;
    }
    pushdown(x);
    int mid = (L + R) / 2;
    if (qr <= mid) add(x*2,L,mid,ql,qr,val);
    else if (ql > mid) add(x*2+1,mid+1,R,ql,qr,val);
    else {
        add(x*2,L,mid,ql,mid,val);
        add(x*2+1,mid+1,R,mid+1,qr,val);
    }
    T[x] = min(T[x*2],T[x*2+1]);
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d",&s[i].l,&s[i].r,&s[i].w);
        s[i].r--;
    }
    sort(s+1,s+n+1,[](seg &s1, seg &s2){return s1.w<s2.w;});
    int R = 0;
    const int INF = 1e9;
    int ans = INF;
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n",s[i].l,s[i].r,s[i].w);
    }
    */
    for (int L = 1; L <= n; L++) {
        while(R + 1 <= n && T[1] == 0) {
            add(1, 1, m - 1, s[R + 1].l, s[R + 1].r, 1);
            R++;
        }
        //printf("%d %d\n",L,R);
        if (T[1] > 0) {
            ans = min(ans, s[R].w - s[L].w);
        } else break;
        add(1, 1, m - 1, s[L].l, s[L].r, -1);
    }
    printf("%d\n",ans);
}