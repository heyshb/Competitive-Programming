#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(long long i=1;i<=n;++i)
#define bit(i) __builtin_popcount(i)
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
using namespace std;
struct node
{
    int x,y,w,prer,nxtr,prec,nxtc,c;
}a[310000];
int n,m;
int v[310000];
vector<pair<int,int> > q[2];
bool fuck(int x,int y)
{
    if (x==0 || y==0)return 0;
    int prec,nxtc,prer,nxtr;
    int i=(x-1)*m+y;
    prec=a[i].prec; nxtc=a[i].nxtc; prer=a[i].prer; nxtr=a[i].nxtr;
    if (!v[i])return 0;
    int sum=a[prec].w+a[nxtc].w+a[prer].w+a[nxtr].w;
    int cnt=a[prec].c+a[nxtc].c+a[prer].c+a[nxtr].c;
    if (sum>a[i].w*cnt)
    {
        v[i]=0;
        return 1;
    }
    return 0;
}
void del(pair<int,int> t,int ti)
{
    int prec,nxtc,prer,nxtr;
    int i=(t.first-1)*m+t.second;
    prec=a[i].prec; nxtc=a[i].nxtc; prer=a[i].prer; nxtr=a[i].nxtr;

    a[prec].nxtc=nxtc;
    if (fuck(a[prec].x,a[prec].y))q[ti].pb(mp(a[prec].x,a[prec].y));

    a[nxtc].prec=prec;
    if (fuck(a[nxtc].x,a[nxtc].y))q[ti].pb(mp(a[nxtc].x,a[nxtc].y));

    a[prer].nxtr=nxtr;
    if (fuck(a[prer].x,a[prer].y))q[ti].pb(mp(a[prer].x,a[prer].y));

    a[nxtr].prer=prer;
    if (fuck(a[nxtr].x,a[nxtr].y))q[ti].pb(mp(a[nxtr].x,a[nxtr].y));
}
int main()
{
    int T;
    cin>>T;
    for(int ti=1;ti<=T;ti++)
    {
        scanf("%d%d",&n,&m);

        a[0].x=a[0].y=a[0].w=a[0].c=0;

        long long sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int x=(i-1)*m+j;
                v[x]=1;
                a[x].x=i;
                a[x].y=j;
                scanf("%d",&a[x].w);
                sum+=a[x].w;
                a[x].c=1;
                a[x].prer=((i==1)?0:(i-2)*m+j);
                a[x].nxtr=((i==n)?0:i*m+j);
                a[x].prec=((j==1)?0:(i-1)*m+j-1);
                a[x].nxtc=((j==m)?0:(i-1)*m+j+1);
            }

        long long ans=0;
        int now=0; q[now].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if (fuck(i,j))q[now].pb(mp(i,j));
        ans+=sum;

        int round=0;
        while (!q[now].empty())
        {
            round++;
            //cout<<"round "<<round<<":"<<endl;
            q[now^1].clear();
            for(auto p:q[now])
            {
                //cout<<p.first<<" "<<p.second<<endl;
                sum-=a[(p.first-1)*m+p.second].w;
                del(p,now^1);
            }
            now^=1;
            ans+=sum;
        }
        printf("Case #%d: %lld\n",ti,ans);
    }
    return 0;
}