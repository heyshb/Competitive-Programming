#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
std::mt19937 rnd(time(0));

int N;
LL a[200010];

const int S=20;//随机算法判定次数，S越大，判错概率越小
//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
long long mult_mod(long long x,long long y,long long mod){
	x%=mod; y%=mod;
    if (x<1e9 && y<1e9) return x*y%mod;
    long long k=(long long)((long double)x*y/mod),res;
    res=(x*y-k*mod)%mod;
    return res<0? res+mod:res;
}
long long pow_mod(long long x,long long n,long long mod){//x^n%c
    if(n==1)return x%mod;
    x%=mod; long long tmp=x; long long ret=1;
    while(n){
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod); n>>=1;
    }
    return ret;
}
//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(long long a,long long n,long long x,long long t){
    long long ret=pow_mod(a,x,n);long long last=ret;
    for(int i=1;i<=t;i++){
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;return false;
}
//是素数返回true.(可能是伪素数，但概率极小) 合数返回false
bool Miller_Rabin(long long n){// Miller_Rabin()算法素数判定
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    long long x=n-1,t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++){
        long long a=rnd()%(n-1)+1;
        if(check(a,n,x,t))return false;//合数
    }
    return true;
}
//pollard_rho 算法进行质因数分解
long long factor[500000];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从1开始
long long gcd(long long a,long long b)
{
    if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b){long long t=a%b; a=b; b=t;}
    return a;
}
long long Pollard_rho(long long x,long long c){
    long long i=1,k=2,x0=rnd()%x;long long y=x0;
    while(1){
        i++; x0=(mult_mod(x0,x0,x)+c)%x;
        long long d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
void findfac(long long n){//对n进行素因子分解
    if(Miller_Rabin(n)){//素数
        factor[++tol]=n;
        return;
    }
    long long p=n;
    while(p>=n)p=Pollard_rho(p,rnd()%(n-1)+1);
    findfac(p);findfac(n/p);
}

LL test(LL g) {
    if (g <= 1) return 1e18;
    LL ret = 0;
    for (int i=1;i<=N;i++) {
        if (a[i] < g) {
            ret += g - a[i];
        } else {
            ret += min(a[i] % g, g - a[i] % g);
        }
    }
    return ret;
}

set<LL> checked;
int prm[7] = {2,3,5,7,11,13,17};

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld",&a[i]);
    }
    //puts("??");
    int TT = 100;
    LL ans = N;
    for (int i=0;i<7;i++) {
        checked.insert(prm[i]);
        ans = min(ans, test(prm[i]));
    }
    //puts("fuck");
    while(TT--) {
        int u = rnd() % N + 1;
        int v = rnd() % N + 1;
        while(v == u) {
            v = rnd() % N + 1;
        }
        for (int i=-1;i<=1;i++) {
            for (int j=-1;j<=1;j++) {
                if (a[u]+i<=1 || a[v]+j<=1) continue;
                LL gg = __gcd(a[u]+i, a[v]+j);
                if (gg == 1) continue;
                tol = 0;
                findfac(gg);
                for (int k=1;k<=tol;k++) {
                    LL fc = factor[k];
                    if (checked.find(fc) != checked.end()) {
                        continue;
                    }
                    checked.insert(fc);
                    ans = min(ans, test(fc));
                }
            }
        }
    }
    printf("%lld\n",ans);
}