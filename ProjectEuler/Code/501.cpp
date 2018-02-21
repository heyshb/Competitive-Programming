#include <bits/stdc++.h>

#define MAXN 100    // pre-calc max n for phi(m, n)  
#define MAXM 100010 // pre-calc max m for phi(m, n)  
#define MAXP 400000 // max primes counter  
#define MAX 4000010    // max prime  
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))   
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))  
#define isprime(x) (( (x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))  
  
namespace pcf {  
    long long dp[MAXN][MAXM];  
    unsigned int ar[(MAX >> 6) + 5] = { 0 };  
    int len = 0, primes[MAXP], counter[MAX];  
  
    void Sieve() {  
        setbit(ar, 0), setbit(ar, 1);  
        for (int i = 3; (i * i) < MAX; i++, i++) {  
            if (!chkbit(ar, i)) {  
                int k = i << 1;  
                for (int j = (i * i); j < MAX; j += k) setbit(ar, j);  
            }  
        }  
  
        for (int i = 1; i < MAX; i++) {  
            counter[i] = counter[i - 1];  
            if (isprime(i)) primes[len++] = i, counter[i]++;  
        }  
    }  
  
    void init() {  
        Sieve();  
        for (int n = 0; n < MAXN; n++) {  
            for (int m = 0; m < MAXM; m++) {  
                if (!n) dp[n][m] = m;  
                else dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];  
            }  
        }  
    }  
  
    long long phi(long long m, int n) {  
        if (n == 0) return m;  
        if (primes[n - 1] >= m) return 1;  
        if (m < MAXM && n < MAXN) return dp[n][m];  
        return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);  
    }  
  
    long long Lehmer(long long m) {  
        if (m < MAX) return counter[m];  
  
        long long w, res = 0;  
        int i, a, s, c, x, y;  
        s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);  
        a = counter[y], res = phi(m, a) + a - 1;  
        for (i = a; primes[i] <= s; i++) res = res - Lehmer(m / primes[i]) + Lehmer(primes[i]) - 1;  
        return res;  
    }  
}  

using namespace std;

typedef long long LL;
const LL N = 1000000000000LL;
const int up = 1000000;
bool isprime[up + 10];
int prime[up + 10], cnt;

LL po(int a,int b)
{
	LL res = 1;
	for (int i=1;i<=b;i++)res *= a;
	return res;
}

int main()
{
	pcf::init();
	//printf("%lld\n",pcf::Lehmer(1000000000000LL));
	memset(isprime,true,sizeof(isprime));
	for (int i=2;i<=up;i++)
	{
		if (isprime[i]) prime[++cnt] = i;
		for (int j=1;j<=cnt && i*prime[j]<=up;j++)
		{
			isprime[i * prime[j]] = false; 
			if (i % prime[j] == 0) break; 
		} 
	}
	LL ans = 0;
	for (int i=1;i<=cnt && po(prime[i],7)<=N;i++)ans++;
	for (int i=1;i<=cnt && po(prime[i],3)<=N;i++)
	{
		ans += pcf::Lehmer(N / po(prime[i],3));
		if (N / po(prime[i],3) >= prime[i]) ans--;
	}
	for (int a=1;a<=cnt && po(prime[a],3)<=N;a++)
		for (int b=a+1;b<=cnt && N/prime[a]/prime[b] > prime[b];b++)
		{
			ans += pcf::Lehmer(N / prime[a] / prime[b]);
			ans -= b;
		} 
	printf("%lld\n",ans);
	//for (int i=1;i<=20;i++)printf("%d\n",prime[i]);
} 
