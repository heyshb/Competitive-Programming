#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MOD = 998244353;
const int MM = 200000;
int fac[MM + 10], ifac[MM + 10];

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

//https://blog.csdn.net/weixin_30493401/article/details/99470501
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
        //printf("n = %d, m = %d\n",n,m);
        for (int i=n+1;i<p;i++) A[i] = 0;
        for (int i=m+1;i<p;i++) B[i] = 0;
        //for (int i=0;i<p;i++) printf("%d ",A[i]);puts("");
        //for (int i=0;i<p;i++) printf("%d ",B[i]);puts("");
        for(int i=0;i<p;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
        ntt(p,A,B,C);
    }
}NTT;

int C(int N, int M) {
    if (M > N || M < 0) return 0;
    return 1LL * fac[N] * ifac[M] % MOD * ifac[N - M] % MOD;
}

int N, a[300010], b[300010], c[300010];
int cnt[30];
int ans[300010];

int main() {
    fac[0] = ifac[0] = 1;
    for (int i=1;i<=MM;i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = quick_pow(fac[i], MOD - 2);
    }
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        for (int j=0;j<30;j++) {
            cnt[j] += ((a[i] >> j) & 1);
        }
    }
    for (int bb=0;bb<30;bb++) {
        int one = cnt[bb];
        int zero = N - one;
        //printf("bb = %d one = %d zero = %d\n",bb,one,zero);
        for (int i=0;i<=one;i++) {
            if (i % 2 == 0) a[i] = 0;
            else a[i] = C(one, i);
        }
        for (int i=0;i<=zero;i++) {
            b[i] = C(zero, i);
        }
        NTT.mul(a, b, c, one, zero);
        for (int i=1;i<=N;i++) {
            int way = c[i];
            //printf("way %d = %d\n",i,way);
            ans[i] += 1LL * way * (1 << bb) % MOD;
            if (ans[i] >= MOD) ans[i] -= MOD;
        }
    }
    for (int i=2;i<=N;i++) {
        ans[i] += ans[i - 1];
        if (ans[i] >= MOD) ans[i] -= MOD;
    }
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int query;
        scanf("%d",&query);
        printf("%d\n",ans[query]);
    }
}