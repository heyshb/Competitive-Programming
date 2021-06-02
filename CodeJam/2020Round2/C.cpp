#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> pll;
typedef vector<pll> vpll;

const int MAXN = 110;
struct point{
    LL x,y;
    point operator -(point p){return (point){x-p.x,y-p.y};}
    LL operator *(point p){return x*p.y-y*p.x;}
    LL operator %(point p){return x*p.x+y*p.y;}
}a[MAXN];
map<pll, vpll> dic;
int n;
int v[MAXN],nxt[MAXN];
int solve(vector<int> &a)
{
    int t=0;
    int tt=0;
    int ans=0;
    for(auto x:a)
        if (x==1)tt++;
        else t+=x;
    if (t%2==0)ans=t+min(2,tt);
    else ans=t+min(1,tt);
    return ans;
}
int main()
{
    int Cases;
    for(int T=1;T<=Cases;T++)
    {
        scanf("%d",&n);
        int ans=2;
        ans = min(ans, n);
        for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
        dic.clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if (i!=j)
                {
                    point t=a[j]-a[i];
                    int flag=1;
                    for(int k=1;k<=n;k++)
                        if (i!=k && j!=k)
                            if ((a[i]-a[k])*(a[j]-a[k])==0)
                                if ((a[i]-a[k])%(a[j]-a[k])<0)flag=0;
                    if (!flag)continue;
                    LL g = __gcd(abs(t.x),abs(t.y));
                    t.x/=g;
                    t.y/=g;
                    dic[pll(t.x,t.y)].push_back(pll(i,j));
                }
        for(auto q:dic)
        {
            for(int i=1;i<=n;i++)v[i]=0;
            for(int i=1;i<=n;i++)nxt[i]=0;
            for(auto p:q.second)
            {
                v[p.second]=1;
                nxt[p.first]=p.second;
            }
            vector<int> save;

            for(int i=1;i<=n;i++) {
                if(!v[i])
                {
                    int now=i,cnt=1;
                    while(nxt[now]!=0){ cnt++; now=nxt[now]; }
                    save.push_back(cnt);
                }
            }
            ans=max(ans,solve(save));
        }
        printf("Case #%d: %d\n",T,ans);
    } 
}