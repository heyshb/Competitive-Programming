#include <bits/stdc++.h>
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
const int MOD = 1e9 + 7;
using namespace std;
const int MAXN = 1e6 + 10;
const int MAXM = 1e6;
typedef long long LL;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, Q;
int belong[MAXN], block;
struct Query {
    int l, r, ID, lca, ans;
    bool operator < (const Query &rhs) const{
        return belong[l] == belong[rhs.l] ? r < rhs.r : belong[l] < belong[rhs.l];
    //    return belong[l] < belong[rhs.l];
    }
}q[MAXN];
vector<int>v[MAXN];
int a[MAXN], date[MAXN];
void Discretization() {
    sort(date + 1, date + N + 1);
    int num = unique(date + 1, date + N + 1) - date - 1;
    for(int i = 1; i <= N; i++) a[i] = lower_bound(date + 1, date + num + 1, a[i]) - date;    
}
int deep[MAXN], top[MAXN], fa[MAXN], siz[MAXN], son[MAXN], st[MAXN], ed[MAXN], pot[MAXN], tot;
void dfs1(int x, int _fa) {
    fa[x] = _fa; siz[x] = 1;
    st[x] = ++ tot; pot[tot] = x; 
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        //if(deep[to]) continue;
        if (to == _fa) continue;
        deep[to] = deep[x] + 1;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]]) son[x] = to;
    }
    ed[x] = ++tot; pot[tot] = x;
}
void dfs2(int x, int topfa) {
    top[x] = topfa;
    if(!son[x]) return ;
    dfs2(son[x], topfa);
    for(int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if(top[to]) continue;
            dfs2(to, to);
    }
}
int GetLca(int x, int y) {
    while(top[x] != top[y]) {
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
}
void DealAsk() {
    for(int i = 1; i <= Q; i++) {
        int x = read(), y = read();
        if(st[x] > st[y]) swap(x, y);
        int _lca = GetLca(x, y);
        q[i].ID = i;
        if(_lca == x) q[i].l = st[x], q[i]. r = st[y], q[i].lca = 0;
        else q[i].l = ed[x], q[i].r = st[y], q[i].lca = _lca;
    }
}
int Ans, out[MAXN], used[MAXN], happen[MAXN];
int tt[MAXM + 10], backup[MAXM + 10];
int inv[MAXM + 10];
bool modified[MAXM + 10];
vector<int> this_query_modify;
typedef pair<int,int> pii;
vector<pii>fac[MAXM + 10];
void add(int x) {
    //printf("add %d\n",x);
    for (auto t:fac[x]) {
        if (!modified[t.first]) {
            modified[t.first] = true;
            this_query_modify.push_back(t.first);
        }
        tt[t.first] += t.second;
    }
    /*
    for (auto t:fac[x]) {
        Ans = 1LL * Ans * inv[tt[t.first] + 1] % MOD;
        tt[t.first] += t.second;
        Ans = 1LL * Ans * (tt[t.first] + 1) % MOD;
    }
    */
}
void delet(int x) {
    for (auto t:fac[x]) {
        if (!modified[t.first]) {
            modified[t.first] = true;
            this_query_modify.push_back(t.first);
        }
        tt[t.first] -= t.second;
    }
    /*
    for (auto t:fac[x]) {
        Ans = 1LL * Ans * inv[tt[t.first] + 1] % MOD;
        tt[t.first] -= t.second;
        Ans = 1LL * Ans * (tt[t.first] + 1) % MOD;
    }
    */
}
void Calc_And_Clear() {
    for (auto t:this_query_modify) {
        Ans = 1LL * Ans * inv[backup[t] + 1] % MOD;
        Ans = 1LL * Ans * (tt[t] + 1) % MOD;
        modified[t] = false;
        backup[t] = tt[t];
    }
    this_query_modify.clear();
}
void Add(int x) {
    //printf("rev %d\n",x);
    used[x] ? delet(a[x]) : add(a[x]); used[x] ^= 1;
}
LL quick_pow(LL a,LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}
void Mo() {
    sort(q + 1, q + Q + 1);
    int l = 1, r = 0, fuck = 0;
    this_query_modify.clear();
    for(int i = 1; i <= Q; i++) {
        while(l < q[i].l) Add(pot[l]), l++, fuck++;
        while(l > q[i].l) l--, Add(pot[l]), fuck++;
        while(r < q[i].r) r++, Add(pot[r]), fuck++;
        while(r > q[i].r) Add(pot[r]), r--, fuck++;
        if(q[i].lca) Add(q[i].lca);
        Calc_And_Clear();
        q[i].ans = Ans;
        if(q[i].lca) Add(q[i].lca);
    }
    
    for(int i = 1; i <= Q; i++) out[q[i].ID] = q[i].ans;
    for(int i = 1; i <= Q; i++)
        printf("%d\n", out[i]);
    
}
bool is_prime[MAXM + 10];
int prime_cnt, prime[MAXM + 10];
int min_d[MAXM + 10];
void Prework() {
    for (int i=1;i<=MAXM;i++) {
        is_prime[i] = true;
    }
    prime_cnt = 0;
    for (int i=2;i<=MAXM;i++) {
        if (is_prime[i]) {
            min_d[i] = i;
            prime[++prime_cnt] = i;
        }
        for (int j=1;j<=prime_cnt && i*prime[j]<=MAXM;j++) {
            is_prime[i*prime[j]] = false;
            min_d[i*prime[j]] = prime[j];
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    /*
    for (int i=1;i<=30;i++) {
        printf("%d %d %d\n",i, is_prime[i],min_d[i]);
    } */
    //puts("here");
    inv[1] = 1;
    for (int i=2;i<=MAXM;i++) {
        inv[i] = quick_pow(i, MOD - 2);
        int tmp = i;
        vector<int>g;
        while(tmp > 1) {
            g.push_back(min_d[tmp]);
            tmp /= min_d[tmp];
        }
        for (int L=0;L<g.size();) {
            int R = L;
            while(R + 1 < g.size() && g[R + 1] == g[L]) {
                R++;
            }
            fac[i].push_back(pii(g[L], R - L + 1));
            L = R + 1;
        }
    }
    //puts("done");
}
int main() {
    //freopen("FCTRE.in","r",stdin);
    Prework();
    int T = read();
    while(T--) {
        N = read();
        //block = 1.5 * sqrt(2 * N) + 1;
        //block = pow(N, 0.66666666666);
        block = 2.5 * sqrt(2 * N) + 1;
        for(int i = 1; i <= N * 2; i++) belong[i] = i / block + 1;
        //Discretization();
        for(int i = 1; i <= N; i++) {
            v[i].clear();
        }
        for(int i = 1; i <= N - 1; i++) {
            int x = read(), y = read();
            v[x].push_back(y); v[y].push_back(x);
        }
        for(int i = 1; i <= N; i++) a[i] = read();
        for (int i=1;i<=N;i++) {
            top[i] = 0;
            son[i] = 0;
        }
        tot = 0;
        deep[1] = 1; dfs1(1, 0);
        for(int i = 1; i <= N; i++) used[i] = false;
        Ans = 1;
        memset(tt, 0, sizeof(tt));
        memset(backup, 0, sizeof(backup));
        memset(modified, false, sizeof(modified));
        
        dfs2(1, 1);
        /*
        for (int i=1;i<=N;i++) {
            printf("%d %d %d %d\n",i, son[i], top[i], siz[i]);
        }
        */
        Q = read();
        DealAsk();
        Mo();
    }
    return 0;
}