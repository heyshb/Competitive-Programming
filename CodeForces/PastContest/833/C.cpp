#include <bits/stdc++.h>
#define MAXP 17
#define MOD 19
using namespace std;

long long L,R;

int K,N,num[20];
long long p[15];
unordered_map<long long,int> mp,cnt;

long long dp(int dep,long long mask,bool full,bool zero)
{
    int i;
    if(zero && dep <= N-2) return 0;
    if(dep == -1) return 1;
    if(!full)
    {
        auto it = mp.find(mask);
        if(it != mp.end()) return it->second;
    }
    
    long long ret = 0;
    for(i=(full?num[dep]:9);i>=0;i--)
    {
        if(mask/p[i]%MOD == 0) continue;
        ret += dp(dep-1,mask-p[i],full&&(i==num[dep]),zero&&(i==0));
    }
    if(!full) mp[mask] = ret;
    return ret;
}

void dfs(int num,int dep,long long mask)
{
    int i;
    if(num == 9)
    {
        mask += p[9]*dep;
        cnt[mask/MOD] += K * dp(MAXP,mask,true,true);
    }
    else for(i=0;i<=dep;i++) dfs(num+1,dep-i,mask+p[num]*i);
}

void work(long long x)
{
    int i;
    if(!x) return;
    if(x == (long long)1e18) cnt[p[1]+MAXP]++, x--;
    
    N = 0;
    for(i=0;i<=MAXP;i++)
    {
        num[i] = x%10; x /= 10;
        if(x) N++;
    }
    dfs(0,MAXP+1,0);
}

long long calcAns()
{
    long long ret = 0;
    for(auto it=cnt.begin();it!=cnt.end();it++)
        if (it->first > 0)
            ret += (it->second > 0);
    return ret;
}

int main()
{
    int i;
    for(i=1,p[0]=1;i<10;i++) p[i] = p[i-1] * MOD;
    mp.reserve(1024); mp.max_load_factor(0.25);
    cnt.reserve(1024); cnt.max_load_factor(0.25);
    scanf("%lld%lld",&L,&R);
    K = 1; work(R);
    K = -1; work(L-1);
    printf("%lld",calcAns());
    return 0;
}

