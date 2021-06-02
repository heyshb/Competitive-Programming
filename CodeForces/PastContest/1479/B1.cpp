#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int a[100010];
int T[400010], tag[400010];
const int INF = 1e9;

void pushdown(int x) {
    if (tag[x]) {
        T[x*2] += tag[x];
        T[x*2+1] += tag[x];
        tag[x*2] += tag[x];
        tag[x*2+1] += tag[x];
        tag[x] = 0;
    }
}

void maintain(int x) {
    T[x] = max(T[x*2], T[x*2+1]);
}

void setpos(int x,int L,int R,int pos,int val) {
    if (L == R) {
        tag[x] = 0;
        T[x] = val;
        return;
    }
    pushdown(x);
    int mid = (L + R) / 2;
    if (pos <= mid) setpos(x*2,L,mid,pos,val);
    else setpos(x*2+1,mid+1,R,pos,val);
    maintain(x);
}

void modify(int x,int L,int R,int ql,int qr,int val) {
    if (ql == L && qr == R) {
        tag[x] += val;
        T[x] += val;
        return;
    }
    pushdown(x);
    int mid = (L + R) / 2;
    if (qr <= mid) modify(x*2,L,mid,ql,qr,val);
    else if (ql > mid) modify(x*2+1,mid+1,R,ql,qr,val);
    else {
        modify(x*2,L,mid,ql,mid,val);
        modify(x*2+1,mid+1,R,mid+1,qr,val);
    }
    maintain(x);
}



int getval(int x,int L,int R,int ql,int qr) {
    if (L == ql && R == qr) {
        return T[x];
    }
    pushdown(x);
    int mid = (L + R) / 2;
    if (qr <= mid) return getval(x*2,L,mid,ql,qr);
    if (ql > mid) return getval(x*2+1,mid+1,R,ql,qr);
    //!!!!
    return max(getval(x*2,L,mid,ql,mid),getval(x*2+1,mid+1,R,mid+1,qr)); 
}

multiset<int>f[400010];
int delta[400010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=4*N+4;i++) {
        T[i] = -INF;
    }
    setpos(1,0,N,0,1);
    int GLOBAL = 0;
    multiset<int>allset;
    f[0].insert(1);
    allset.insert(1);
    for (int i=2;i<=N;i++) {
        /*
        if (a[i] != a[i - 1]) {
            modify(1,0,N,0,i-2,1);
        }
        */
        if (a[i] != a[i - 1]) {
            GLOBAL++;
        }
        if (!)
        int ma = *allset.rbegin();

    }
}