#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(LL _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void read(mint& a) { LL x; scanf("%lld",&x); a = mint(x); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((LL)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, LL p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

const int MOD = 998244353;
typedef mint<MOD,5> mi;

int n, m;
bitset<101>mask[110];
int g[110][110], order[110], iinv[110], tag[110];
void mcs(int n){
    int i, j, k;
    memset(tag, 0, sizeof(tag));
    memset(order, -1, sizeof(order));
    for (i = n - 1; i >= 0; i--) { // vertex: 0 ~ n-1
    for (j = 0; order[j] >= 0; j++) ;
    for (k = j + 1; k < n; k++)
    if (order[k] < 0 && tag[k] > tag[j]) j = k;
    order[j] = i, iinv[i] = j;
    for (k = 0; k < n; k++) if (g[j][k]) tag[k]++;
    }
}
int peo(int n){
    int i, j, k, w, min;
    for (i = n - 2; i >= 0; i--) {
        j = iinv[i], w = -1, min = n;
        for (k = 0; k < n; k++)
        if (g[j][k] && order[k] > order[j] && order[k] < min)
        min = order[k], w=k;
        if (w < 0) continue;
        for (k = 0; k < n; k++)
        if (g[j][k] && order[k] > order[w] && !g[k][w])
        return 0; // no
    }
    return 1; // yes
}

bool fucked[110];
mi fac[110], ifac[110];

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 100; i++) fac[i] = fac[i - 1] * i;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++) {
        int sz, tmp;
        scanf("%d",&sz);
        while(sz--) {
            scanf("%d",&tmp);
            mask[i].set(tmp);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = ((mask[i] & mask[j]).count() > 0);
        }
    }
    mcs(m);
    if (!peo(m)) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++) fucked[i] = false;
    mi ans = 1;
    int com = 0;
    for (int i = 1; i <= n; i++) {
        if (fucked[i]) continue;
        com++;
        vector<int> idx;
        for (int j = 0; j < m; j++) {
            if (mask[j].test(i)) {
                idx.push_back(j);
            }
        }
        vector<int> cnm;
        int sz = idx.size();
        if (sz == 0) continue;
        auto bm = mask[idx[0]];
        for (int i = 1; i < sz; i++) {
            bm &= mask[idx[i]];
        }
        vector<int> merge;
        for (int i = 1; i <= n; i++) {
            if (bm.test(i)) {
                merge.push_back(i);
                fucked[i] = true;
            }
        }
        ans *= fac[merge.size()];
        for (auto &t : merge) {
            for (int i = 1; i <= m; i++) {
                mask[i].reset(t);
            }
        }
    }
    ans *= fac[com];
    printf("%d\n",int(ans));
}