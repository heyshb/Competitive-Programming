#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ": " << (x) << endl
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef vector<int> vi;
 
const int maxn=1e5+10;
bool notprime[maxn];
int prime[maxn],cnt;
void getprime()
{
    notprime[0]=notprime[1]=1;
    cnt=0;
    for(int i=2;i<maxn;++i)
    {
        if(!notprime[i]) prime[cnt++]=i;
        for(int j=0;j<cnt && 1ll*i*prime[j]<maxn;++j)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
 
ll ans;
int c,d,x;
 
ll calc(int z)
{
    printf("calc %d\n",z);
    ll t=1;
    for(int i=0;i<cnt;++i)
    {
        if(prime[i]*prime[i]>z) break;
        if(z%prime[i]==0)
        {
            t*=2;
            while(z%prime[i]==0) z/=prime[i];
        }
    }
    if(z>1) t*=2;
    return t;
}
 
void solve(int g,int els)
{
    int cz=els+d;
    if(cz%c!=0) return;
    ll z=cz/c;
    ll lcm=g*z;
    ans+=calc(z);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    getprime();
    int kase;
    cin>>kase;
    while(kase--)
    {
        cin>>c>>d>>x;
        ans=0;
        for(int i=1;1ll*i*i<=x;++i)
        {
            if(x%i==0)
            {
                solve(i,x/i);
                if(x/i!=i) solve(x/i,i);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}