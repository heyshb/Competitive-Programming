#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
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
typedef mint<MOD,5> mi; // 5 is primitive root for both common mods

const int MAXN = 1e7 + 1;
mi fac[MAXN + 10], ifac[MAXN + 10];
mi f[MAXN + 10], s[MAXN + 10];
int n, k;
int main() {
    scanf("%d%d",&n,&k);
    fac[0] = 1;
    for (int i = 1; i <= n + 1; i++) {
        fac[i] = fac[i - 1] * i;
    }
    ifac[n + 1] = inv(fac[n + 1]);
    for (int i = n; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1);
    }
    f[0] = 1;
    s[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = s[i - 1];
        if (i - k > 0) f[i] -= s[i - k - 1];
        f[i] *= fac[i - 1];
        //printf("f[%d] = %d\n",i,int(f[i]));
        s[i] = s[i - 1] + (f[i] * ifac[i]);
    }
    printf("%d\n",int(f[n]));
}