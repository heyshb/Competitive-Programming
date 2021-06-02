#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 200010;

char s1[MAXN],s2[MAXN];
int N1,N2;

class Segment_Tree {
public:
    int T[4 * MAXN], tag[4 * MAXN];
    
    void build(int x,int L,int R) {
        //printf("build %d %d %d\n",x,L,R);
        T[x] = 0;
        tag[x] = -1;
        if (L == R) {
            return;
        }
        int mid = (L + R) / 2;
        build(2 * x, L, mid);
        build(2 * x + 1, mid + 1, R);
    }

    void pushdown(int x,int L,int R) {
        if (tag[x] == -1) {
            return;
        }
        int mid = (L + R) / 2;
        T[2*x] = (mid - L + 1) * tag[x];
        T[2*x+1] = (R - mid) * tag[x];
        tag[2*x] = tag[2*x+1] = tag[x];

        tag[x] = -1;
    }

    void modify(int x,int L,int R,int ql,int qr,int v) {
        if (ql > qr) {
            return;
        }
        if (ql <= L && qr >= R) {
            T[x] = v * (R - L + 1);
            tag[x] = v;
            return;
        }
        int mid = (L + R) / 2;
        pushdown(x, L, R);
        if (ql <= mid) modify(x*2,L,mid,ql,qr,v);
        if (qr > mid) modify(x*2+1,mid+1,R,ql,qr,v);
        T[x] = T[x*2] + T[x*2+1];
    }

    int getsum(int x,int L,int R,int ql,int qr) {
        if (ql > qr) return 0;
        if (ql <= L && qr >= R) {
            //printf("fuck %d %d %d %d %d %d\n",L,R,ql,qr,x,T[x]);
            return T[x];
        }
        int mid = (L + R) / 2;
        pushdown(x, L, R);
        int ret = 0;
        if (ql <= mid) {
            ret += getsum(2*x,L,mid,ql,qr);
        }
        if (qr > mid) {
            ret += getsum(2*x+1,mid+1,R,ql,qr);
        }
        return ret;
    }
}ST;

class Suffix_Array {
public:
    int N;
    char *s;
    int scp[MAXN],a[MAXN];
    int sa[MAXN],rank[MAXN],cnt[MAXN];
    int fir[MAXN],sec[MAXN],tmp[MAXN];
    int height[MAXN];
    int st[MAXN][22];
    int lg[MAXN];
    Suffix_Array(){}

    void init(char *_s) {
        s = _s;
        N = strlen(s + 1);
        build();
        get_height();
        get_st();
    }

    void build() {
        for (int i=1;i<=N;i++) scp[i] = s[i];
        sort(scp+1,scp+N+1);
        int *end = unique(scp+1,scp+N+1);
        for (int i=1;i<=N;i++)a[i] = lower_bound(scp+1, end, s[i]) - scp;
        for (int i=0;i<=N;i++) cnt[i] = 0;
        for (int i=1;i<=N;i++) cnt[a[i]]++;
        for (int i=1;i<=N;i++) cnt[i] += cnt[i - 1];
        for (int i=1;i<=N;i++) rank[i] = cnt[a[i] - 1] + 1;
        for (int L=1;L<=N;L<<=1) {
            for (int i=1;i<=N;i++) {
                fir[i] = rank[i];
                sec[i] = (i + L <= N ? rank[i + L] : 0);
            }

            for (int i=0;i<=N;i++) cnt[i]  = 0;
            for (int i=1;i<=N;i++) cnt[sec[i]]++;
            for (int i=1;i<=N;i++) cnt[i] += cnt[i - 1];
            for (int i=1;i<=N;i++) tmp[N - (--cnt[sec[i]])] = i;

            for (int i=0;i<=N;i++) cnt[i]  = 0;
            for (int i=1;i<=N;i++) cnt[fir[i]]++;
            for (int i=1;i<=N;i++) cnt[i] += cnt[i - 1];
            for (int j=1;j<=N;j++) {
                int i = tmp[j];
                sa[cnt[fir[i]]--] = i;
            }
            int last = 0;
            bool done = true;
            for (int j=1;j<=N;j++) {
                int i = sa[j];
                if (last == 0) {
                    rank[i] = 1;
                }
                else if (fir[i] == fir[last] && sec[i] == sec[last]) {
                    rank[i] = rank[last];
                    done = false;
                }
                else {
                    rank[i] = rank[last] + 1;
                }
                last = i;
            }
            if (done) {
                break;
            }
        }
    }

    void print() {
        puts("SA:");
        for (int i=1;i<=N;i++) printf("%d ",sa[i]);
        puts("\nRANK:");
        for (int i=1;i<=N;i++) printf("%d ",rank[i]);
        puts("");
        for (int i=1;i<=N;i++) printf("%d ",height[i]);
        puts("");
    }

    void get_height() {
        for (int i=1,k=0;i<=N;i++) {
            if (rank[i] == 1) {
                k = 0;
            }
            else {
                if (k > 0) k--;
                int j = sa[rank[i] - 1];
                while(i + k <= N && j + k <= N && a[i + k] == a[j + k]) k++;
            }
            height[rank[i]] = k;
        }
    }

    void get_st() {
        for (int i=0,j=1;j<=N;i++,j*=2) {
            lg[j] = i;
        }
        for (int i=1;i<=N;i++) {
            if (!lg[i]) {
                lg[i] = lg[i - 1];
            }
        }
        for (int i=1;i<=N;i++) {
            st[i][0] = height[i];
        }
        for (int j=1;j<=lg[N];j++) {
            for (int i=1;i<=N;i++) {
                st[i][j] = min(st[i][j-1], st[min(N,i+(1<<(j-1)))][j-1]);
            }
        }
    }

    int LCP(int x,int y) {
        if (x == y) {
            return N + 1 - x;
        }
        x = rank[x];
        y = rank[y];
        if (x > y) swap(x, y);
        return rmq(x + 1, y);
    }

    int rmq(int L,int R) {
        int len = R - L + 1;
        len = lg[len];
        return min(st[L][len],st[R-(1<<len)+1][len]);
    }

    LL solve() {
        height[N + 1] = 0;
        LL ret = 0;
        /*
        for (int i=1;i<=4*N;i++) {
            ST.T[i] = 0;
        }
        */
        ST.build(1, 1, N);
        for (int i=1;i<=N;i++) {
            int idx = sa[i];
            if (idx <= N1) {
                ret += N2 - ST.getsum(1, 1, N, N1 + 1 - idx + 1, N - idx + 1);
                //printf("%d\n",ST.getsum(1, 1, N, N1 + 1 - idx + 1, N - idx + 1));
                ST.modify(1, 1, N, N1 + 1- idx + 1, N - idx + 1, 1);
            }
            ST.modify(1, 1, N, height[i + 1] + 1, N, 0);
        }
        return ret;
    }
}SA;//1-base!

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s1 + 1);
        scanf("%s",s2 + 1);
        N1 = strlen(s1 + 1);
        N2 = strlen(s2 + 1);
        for (int i=N1+1;i<=N1+N2;i++) {
            s1[i] = s2[i - N1];
        }
        s1[N1+N2+1] = 0;
        SA.init(s1);
        //SA.print();
        printf("%lld\n",SA.solve());
    }
}

/*
1
ehehe
heheh

2
winter
camp
ehehe
heheh

5
abb
bba
aaa
aaaaa
winter
camp
ehehe
heheh
aaaaaaabaaaa
aabaaaaaa
*/