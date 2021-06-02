#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 100000;
const int MAXW = 1000000;
int SS[MAXW + 10];
vector<int>e[MAXN + 10];
vector<int>fac[MAXW + 10];
vector<pii>query[MAXN + 10];
int fa[MAXN + 10], d[MAXN + 10];
int N, Q;
int ans[MAXN + 10];
int sz[MAXN + 10], hson[MAXN + 10];
const LL MOD = 1e13 + 51;

inline long long multi(long long x,long long y,long long mod)
{
	long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
	return tmp<0 ? tmp+mod : tmp;
}

void dfs0(int x) {
    sz[x] = 1;
    int mx = -1;
    hson[x] = -1;
    for (auto &t:e[x]) {
        dfs0(t);
        sz[x] += sz[t];
        if (sz[t] > mx) {
            mx = sz[t];
            hson[x] = t;
        }
    }
}
LL quick_pow(LL a, LL x) {
    LL ret = 1;
    while(x) {
        if (x & 1) ret = multi(ret, a, MOD);
        a = multi(a, a, MOD);
        x >>= 1;
    }
    return ret;
}
LL inv(LL x) {
    return quick_pow(x, MOD - 2);
}
vector<int>FF[MAXW + 10];
vector<int>FAC(int x) {
    if (FF[x].size() > 0) return FF[x];
    vector<int>ret;
    for (int i=1;i*i<=x;i++) {
        if (x % i == 0) {
            ret.push_back(i);
            if (i * i != x) ret.push_back(x / i);
        }
    }
    return FF[x] = ret;
}

LL PO[MAXN + 10];
unordered_map<LL,int>fuck[MAXN + 10];
void dfs1(int x) {
    if (d[x] == 0) {
        PO[x] = 1;
        fuck[x][1] = 1;
        for (auto &q: query[x]) {
            ans[q.second] = 0;
        }
        return;
    }
    for (auto &t:e[x]) {
        if (t != hson[x]) dfs1(t);
    }
    dfs1(hson[x]);
    swap(fuck[x], fuck[hson[x]]);
    //printf("%d: %d %lld\n",x,hson[x],PO[hson[x]]);
    LL iv = inv(PO[hson[x]]);
    //printf("inv %lld = %lld\n",PO[hson[x]], iv);
    for (auto &t:e[x]) {
        if (t == hson[x]) continue;
        LL coe = multi(PO[t], iv, MOD);
        for (auto &tt:fuck[t]) {
            //printf("QAQ %lld %lld\n",PO[t],iv);
            //printf("merge %d to %d: %lld %lld\n",t,x,tt.first,coe);
            LL newv = multi(tt.first, coe, MOD);
            fuck[x][newv] += tt.second;
        }
    }
    PO[x] = PO[hson[x]] * d[x] % MOD;
    /*
    printf("PO[%d] = %lld\n",x,PO[x]);
    for (auto t:fuck[x]) {
        printf("%lld %d\n",t.first,t.second);
    }
    */
    LL iv2 = inv(PO[x]);
    for (auto q:query[x]) {
        int w = q.first;
        int id = q.second;
        LL S = w;
        //for (auto &t: fac[w]) {
        for (auto &t: FAC(w)) {
            LL in_table = multi(t, iv2, MOD);
            if (fuck[x].find(in_table) != fuck[x].end()) {
                LL ct = fuck[x][in_table];
                S -= w / t * ct;
            }
        }
        ans[id] = S;
    }
}

int main() {
    /*
    int S = 0;
    for (int i=1;i<=MAXW;i++) {
        for (int j=i;j<=MAXW;j+=i) {
            SS[j]++;
        }
    }
    for (int i=1;i<=MAXW;i++) fac[i].reserve(SS[i]);
    for (int i=1;i<=MAXW;i++) {
        for (int j=i;j<=MAXW;j+=i) {
            fac[j].push_back(i);
        }
    }
    */
    scanf("%d",&N);
    for (int i=2;i<=N;i++) {
        scanf("%d",&fa[i]);
        e[fa[i]].push_back(i);
        d[fa[i]]++;
    }
    scanf("%d",&Q);
    for (int i=1;i<=Q;i++) {
        int V, W;
        scanf("%d%d",&V,&W);
        query[V].push_back(pii(W, i));
    }
    dfs0(1);
    /*
    for (int i=1;i<=N;i++) {
        printf("%d %d\n",d[i],hson[i]);
    }
    */
    dfs1(1);
    for (int i=1;i<=Q;i++) {
        printf("%d\n",ans[i]);
    }
}