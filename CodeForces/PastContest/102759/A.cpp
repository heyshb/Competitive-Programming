#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N, M;
int a[300010], b[300010];
int *firsta, *lasta;
int pool1[600010], pool2[600010];

int adda(int x) {
    if (firsta[x+1] == 0) {
        firsta[x+1] = lasta[x+1] = lasta[x] + 1;
    } else {
        firsta[x+1]++;
    }
    if (firsta[x] == lasta[x]) {
        firsta[x] = lasta[x] = 0;
    } else {
        lasta[x]--;
    }
    return firsta[x + 1];
}

int suba(int x) {
    if (lasta[x-1] == 0) {
        firsta[x-1] = lasta[x-1] = firsta[x] - 1;
    } else {
        lasta[x-1]--;
    }
    if (firsta[x] == lasta[x]) {
        firsta[x] = lasta[x] = 0;
    } else {
        firsta[x]++;
    }
    return lasta[x - 1];
}

LL T[2000010];
int cntb[1000010];
LL sb[1000010], sa[1000010];
LL tag[2000010];

void maintain(int x) {
    T[x] = min(T[x * 2], T[x * 2 + 1]);
}

void pushdown(int x) {
    if (tag[x]) {
        T[x * 2] += tag[x];
        tag[x * 2] += tag[x];
        T[x * 2 + 1] += tag[x];
        tag[x * 2 + 1] += tag[x];
        tag[x] = 0;
        maintain(x);
    }
}

void build(int x,int L,int R) {
    if (L == R) {
        tag[x] = 0;
        T[x] = sb[L] + 1LL * L * (M - cntb[L]);
        T[x] -= sa[L]; 
        return;
    }
    int mid = (L + R) / 2;
    build(x * 2, L, mid);
    build(x * 2 + 1, mid + 1, R);
    maintain(x);
}

void update(int x,int L,int R,int ql,int qr,int v) {
    if (ql > qr) return;
    if (L == ql && R == qr) {
        T[x] += v;
        tag[x] += v;
        return;
    }
    pushdown(x);
    int mid = (L + R) / 2;
    if (qr <= mid) update(x * 2, L, mid, ql, qr, v);
    else if (ql > mid) update(x * 2 + 1, mid + 1, R, ql, qr, v);
    else {
        update(x * 2, L, mid, ql, mid, v);
        update(x * 2 + 1, mid + 1, R, mid + 1, qr, v);
    }
    maintain(x);
}

int oa[300010];

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        oa[i] = a[i];
    }
    for (int i=1;i<=M;i++) {
        scanf("%d",&b[i]);
        cntb[b[i]]++;
        sb[b[i]] += b[i];
    }
    for (int i=1;i<=300000;i++) {
        cntb[i] += cntb[i-1];
        sb[i] += sb[i-1];
    }
    sort(a+1,a+N+1);
    reverse(a+1,a+N+1);
    for (int i=1;i<=N;i++) {
        sa[i] = sa[i - 1] + a[i];
    }
    build(1, 1, N);
    firsta = &pool1[300000];
    lasta = &pool2[300000];
    for (int i=1;i<=N;i++) {
        if (!firsta[a[i]]) firsta[a[i]] = i;
        lasta[a[i]] = i;
    }
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int tp, idx;
        scanf("%d%d",&tp, &idx);
        if (tp == 1) {
            int pos = adda(oa[idx]++);
            update(1, 1, N, pos, N, -1);
        } else if (tp == 2) {
            int pos = suba(oa[idx]--);
            update(1, 1, N, pos, N, 1);
        } else if (tp == 3) {
            b[idx]++;
            update(1, 1, N, b[idx], N, 1);
        } else {
            update(1, 1, N, b[idx], N, -1);
            b[idx]--;
        }
        if (T[1] >= 0) {
            puts("1");
        } else {
            puts("0");
        }
    }
}