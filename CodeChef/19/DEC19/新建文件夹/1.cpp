#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define N (1<<20)
const int mod = 998244353;
inline int add(int x) {return x >= mod ? x - mod: x;}
inline int sub(int x) {return x < 0 ? x + mod: x;}
inline int add(int x, int y) {return add(x+y);}
inline int mul(int x, int y) {return 1LL*x*y%mod;}

int fac[N], facinv[N];

int pow_mod(int x, int k)
{
	int ret = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) ret = 1LL*ret*x%mod;
		x = 1LL*x*x%mod; 
	}
	return ret;
}

void NTT(int *a, int n, bool idft = 0){
	static int rev[N]; int g = 3;
	for (int i = 0; i < n; i++)
       rev[i] = rev[i >> 1] >> 1 | (i & 1 ? n >> 1: 0);
	for (int i = 0; i < n; i++)
	    if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1, m = 2; m <= n; ++i, m <<= 1){
	    int wn = pow_mod(g, (mod - 1) >> i);
	    if (idft) wn = pow_mod(wn, mod - 2);
	    for (int j = 0; j < n; j += m){
	        int *l = a + j, *r = l + (m >> 1), w = 1;
			for (int k = 0; k < (m >> 1); l++, r++, k++, w = mul(w, wn)){
				int t = mul(*r, w);
				*r = sub(*l - t);
				*l = add(*l + t);
			}
		}
	} 
	if (idft){
		int inv = pow_mod(n, mod-2);
		for (int i = 0; i < n; i++)
			a[i] = mul(a[i], inv);
	}
}


int A[N], B[N];

void conv(int *a, int n, int *b, int m, int *c)
{
	int nn = 1;
	while (nn < n || nn < m) nn <<= 1;
	nn <<= 1;
	for (int i = 0; i < nn; ++i)
		A[i] = B[i] = 0;
	for (int i = 0; i < n; ++i)
		A[i] = a[i];
	for (int i = 0; i < m; ++i)
		B[i] = b[i];
	NTT(A, nn);
	NTT(B, nn);
	for (int i = 0; i < nn; ++i)
		A[i] = mul(A[i], B[i]);
	NTT(A, nn, 1);
	for (int i = 0; i < nn; ++i)
		c[i] = A[i];
}

void Strling1(int n, int S[])
{
	for (int i = 0; i <= n; ++i) 
		S[i] = 0; 
	if (n == 0)
	{
		S[0] = 1;
		return;
	}
	static int S2[N], a[N], b[N];
	if (n&1)
	{
		Strling1(n-1, S);
		S2[0] = mul(n-1, S[0]);
		S2[n] = S[n-1];
		for (int i = 1; i < n; ++i)
			S2[i] = add(mul(n-1, S[i]), S[i-1]);
		for (int i = 0; i <= n; ++i)
			S[i] = S2[i];
	}
	else
	{
		Strling1(n/2, S);
		int m = n/2;
		for (int i = 0; i <= m; ++i)
			a[i] = mul(S[m-i], fac[m-i]), b[i] = mul(facinv[i], pow_mod(m, i));
		conv(a, m+1, b, m+1, S2);
		for (int i = 0, j = m; i < j; ++i, --j)
			swap(S2[i], S2[j]);
		for (int i = 0; i <= m; ++i)
			S2[i] = mul(S2[i], facinv[i]);
		conv(S, m+1, S2, m+1, S);
	}
}

int seq(int q, int n)
{
	if (q == 1) return (n+1)%mod;
	return 1LL*(pow_mod(q, n+1)-1)*pow_mod(q-1, mod-2)%mod;
}

int main()
{
	//freopen("in.txt", "r", stdin);
    //freopen("tmp.in","r",stdin);
	fac[0] = fac[1] = facinv[0] = facinv[1] = 1;
	for (int i = 2; i < N; ++i)
	{
		fac[i] = mul(fac[i-1], i);
		facinv[i] = mul(mod-mod/i, facinv[mod%i]);
	}
	for (int i = 2; i < N; ++i)
		facinv[i] = mul(facinv[i-1], facinv[i]);
	
 	int T, n, p, r;
 	static int S[N];
  	scanf("%d", &T);
  	while (T--)
  	{
  		scanf("%d %d %d", &n, &p, &r);
  		Strling1(r, S);
  		LL ans = 0;
  		for (int j = 0; j <= r; ++j)
  		{
  			LL o = (r-j)&1? -1: 1;
			ans += o*S[j]*seq(pow_mod(p, j), n) % mod; 
  		}
  		ans %= mod;
  		if (ans < 0) ans += mod;
  		printf("%lld\n", ans*facinv[r]%mod);
  	}
    return 0;
}
