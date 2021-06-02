#include<bits/stdc++.h>
using namespace std;

#define LL long long

const int MOD=998244353;

class NTTClass{
public:
    static const int MAXL=22;
    static const int MAXN=1<<MAXL;
    static const int root=3;
    //static const int MOD=998244353;
    int rev[MAXN];

    int fast_pow(int a,int b){
        int ans=1;
        while(b){
            if(b&1)ans=1ll*ans*a%MOD;
            a=1ll*a*a%MOD;
            b>>=1;
        }
        return ans;
    }

    void transform(int n,int *t,int typ){
        for(int i=0;i<n;i++)
            if(i<rev[i])swap(t[i],t[rev[i]]);
        for(int step=1;step<n;step<<=1){
            int gn=fast_pow(root,(MOD-1)/(step<<1));
            for(int i=0;i<n;i+=(step<<1)){
                int g=1;
                for(int j=0;j<step;j++,g=1ll*g*gn%MOD){
                    int x=t[i+j],y=1ll*g*t[i+j+step]%MOD;
                    t[i+j]=(x+y)%MOD;
                    t[i+j+step]=(x-y+MOD)%MOD;
                }
            }
        }
        if(typ==1)return;
        for(int i=1;i<n/2;i++)swap(t[i],t[n-i]);
        int inv=fast_pow(n,MOD-2);
        for(int i=0;i<n;i++)t[i]=1ll*t[i]*inv%MOD;
    }

    void ntt(int p,int *A,int *B,int *C){
        transform(p,A,1);
        transform(p,B,1);
        for(int i=0;i<p;i++)C[i]=1ll*A[i]*B[i]%MOD;
        transform(p,C,-1);
    }

    void mul(int *A,int *B,int *C,int n,int m) {
        int p=1,l=0;
        while(p<=n+m)p<<=1,l++;
        for (int i=n+1;i<p;i++) A[i] = 0;
        for (int i=m+1;i<p;i++) B[i] = 0;
        for(int i=0;i<p;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
        ntt(p,A,B,C);
    }
}NTT;

int N,p,r;
const int MAXN = 1 << 21;
int fac[MAXN], ifac[MAXN];

int qp(int a,int x) {
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int s[MAXN]; // stirling(r, i)
int sh[MAXN],t1[MAXN],t2[MAXN],t3[MAXN];

void solve(int r) {
    if (r == 1) {
        s[0] = 0;
        s[1] = 1;
        return;
    }
    int d = r / 2;
    solve(d);
    //printf("solve %d\n",r);
    int nd = MOD - d, ndp = 1, ind = qp(nd, MOD - 2);
    for (int i=0;i<=d;i++) {
        t1[i] = 1LL * s[i] * fac[i] % MOD * ndp % MOD;
        ndp = 1LL * ndp * nd % MOD;
    }
    for (int i=0;i<=d;i++) {
        t2[i] = ifac[d - i];
    }
    NTT.mul(t1, t2, t3, d, d);
    int indp = 1;
    for (int j=0;j<=d;j++) {
        t1[j] = 1LL * indp * ifac[j] % MOD;
        t1[j] = 1LL * t1[j] * t3[j + d] % MOD;
        indp = 1LL * indp * ind % MOD;
    }
    for (int j=0;j<=d;j++) {
        t2[j] = s[j];
    }
    NTT.mul(t1, t2, t3, d, d);
    if (r % 2 == 1) {
        int nrn1 = MOD - (r - 1);
        for (int i=0;i<=r;i++) {
            s[i] = 1LL * nrn1 * t3[i] % MOD;
            if (i > 0) {
                s[i] = (s[i] + t3[i - 1]) % MOD;
            }
        }
    } else {
        for (int i=0;i<=r;i++) {
            s[i] = t3[i];
        }
    }
}

int qn;
int geo(int a1,int q,int n) {
    if (q == 1) {
        return 1LL * a1 * n;
    }
    //return 1LL * a1 * (1 - qp(q, n) + MOD) % MOD * qp(1 - q + MOD, MOD - 2) % MOD;
    return 1LL * a1 * (1 - qn + MOD) % MOD * qp(1 - q + MOD, MOD - 2) % MOD;
}


int main() { 
    fac[0] = 1;
    for (int i=1;i<MAXN;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    ifac[MAXN - 1] = qp(fac[MAXN - 1], MOD - 2);
    for (int i=MAXN - 2;i>=0;i--) {
        ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&p,&r);
        if (p == 1) {
            if (r == 1) {
                printf("%lld\n", (N + 1) % MOD);
            } else {
                puts("0");
            }
            continue;
        }
        solve(r);
        /*
        for (int i=0;i<=r;i++) {
            printf("%d ",s[i]);
        }
        puts("");
        */
        //puts("here");
        int ans = 0;
        int pi = 1;
        qn = 1;
        int pn = qp(p, N + 1);
        for (int i=0;i<=r;i++) {
            //printf("fuck %d %d %d\n",i,s[i],geo(1, qp(p, i), N + 1));
            //printf("%d:\n",i);
            //printf("%d %d %d\n",s[i],qp(p,i), geo(1,qp(p,i),N+1));
            //ans += 1LL * s[i] * geo(1, qp(p, i), N + 1) % MOD;
            ans += 1LL * s[i] * geo(1, pi, N + 1) % MOD;
            pi = 1LL * pi * p % MOD;
            qn = 1LL * qn * pn % MOD;
            //printf("after add %d:%d\n",1LL * s[i] * geo(1, qp(p, i), N + 1) % MOD,ans);
            //printf("cnm %d\n",1LL * s[i] * qp(geo(1, qp(p, i), N + 1), i) % MOD);
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        ans = 1LL * ans * ifac[r] % MOD;
        printf("%d\n",ans);
    }
    return 0;
}