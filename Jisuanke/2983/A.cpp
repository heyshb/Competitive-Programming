#include <bits/stdc++.h>

using namespace std;

int N,a[500010],b[500010],M;
int Ts[500010],Tm[500010];
vector<int>pos[500010];
const int MOD = 998244353;
void clear() {
    for (int i=1;i<=N;i++) {
        Ts[i] = 0;
        Tm[i] = 0;
    } 
}
int lowbit(int x) {
    return x & -x;
}

void add(int x,int y) {
    //printf("add %d %d\n",x,y);
    while(x <= N) {
        Ts[x] += y;
        if (Ts[x] >= MOD) Ts[x] -= MOD;
        Tm[x] = max(Tm[x], y);
        x += lowbit(x);
    }
}

int getsum(int x) {
    if (x == 0) return 1;
    int ret = 0;
    while(x) {
        ret += Ts[x];
        if (ret >= MOD) ret -= MOD;
        if (ret < 0) ret += MOD;
        x -= lowbit(x);
    }
    return ret;
}

int getmax(int x) {
    int ret = 0;
    if (x == 0) return 0;
    while(x) {
        ret = max(ret, Tm[x]);
        x -= lowbit(x);
    }
    return ret;
}

int f1[500010],f2[500010],g1[500010],g2[500010];
struct query {
    int tp,pos,v;
}q[500010];
int Q;
bool cmp(query q1,query q2) {
    return q1.pos < q2.pos;
}

void gao(int *f,int *g) {
    clear();
    for (int i=1;i<=N;i++) {
        pos[i].clear();
    }
    g[0] = 1;
    a[0] = 1;
    for (int i=1;i<=N;i++) {
        //printf("%d\n",i);
        f[i] = getmax(a[i] - 1) + 1;
        add(a[i], f[i]);
        pos[f[i]].push_back(i);
    }
    clear();
    for (int i=1;i<=N;i++) {
        //printf("solve %d\n",i);
        Q = 0;
        for (auto t:pos[i-1]) q[++Q] = (query){0,t,a[t]};
        for (auto t:pos[i]) q[++Q] = (query){1,t,a[t]};
        sort(q+1,q+Q+1,cmp);
        for (int j=1;j<=Q;j++) {
            if (q[j].tp == 0) {
                add(q[j].v, g[q[j].pos]);
            } else {
                g[q[j].pos] = getsum(q[j].v - 1);
                //printf("g[%d]=%d\n",q[j].pos,g[q[j].pos]);
            }
        }
        for (auto t:pos[i-1]) add(a[t], -g[t]);
    }
}

int quick_pow(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        //a[i] = (i + 1) / 2;
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b+1,b+N+1);
    b[0] = -1;
    M = 0;
    for (int i=1;i<=N;i++) {
        if (b[i] != b[i - 1]) {
            b[++M] = b[i];
        }
    }
    for (int i=1;i<=N;i++) {
        a[i] = lower_bound(b+1,b+M+1,a[i]) - b;
    }

    pos[0].push_back(0);
    gao(f1,g1);
    for (int i=1;i<=N;i++) {
        a[i] = N + 1 - a[i];
    }
    reverse(a+1, a+N+1);
    gao(f2,g2);
    reverse(f2+1,f2+N+1);
    reverse(g2+1,g2+N+1);

    
    /*
    for (int i=1;i<=N;i++) {
        printf("%d %d %d %d\n",f1[i],g1[i],f2[i],g2[i]);
    }
    */
    

    int mx = 0;
    for (int i=1;i<=N;i++) {
        mx = max(mx, f1[i]);
    }

    int tot = 0;
    for (int i=1;i<=N;i++) {
        if (f1[i] == mx) {
            tot = (tot + g1[i]) % MOD;
        }
    }
    tot = quick_pow(tot, MOD - 2);
    for (int i=1;i<=N;i++) {
        if (f1[i] + f2[i] == mx + 1) {
            int sum = 1LL * g1[i] * g2[i] % MOD;
            printf("%d",1LL * sum * tot % MOD) ;
        } else {
            putchar('0');
        }
        printf("%c"," \n"[i==N]);
    }
}