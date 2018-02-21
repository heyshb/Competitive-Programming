#include <bits/stdc++.h>
#define L first.first
#define R first.second
#define K second.first
#define ID second.second
#define TRY 80
using namespace std;
typedef pair<pair<int,int>,pair<int,int>> piiii;

int n,q,A[300010],ans[300010];
piiii qry[300010];

int MAGIC,cnt[300010];

int bigr()
{
    return rand()%10*100000000 + rand()%10000*10000 + rand()%10000;
}

bool cmp(piiii a,piiii b)
{
    int x = a.L/MAGIC,y = b.L/MAGIC;
    if(x == y) return a.R < b.R;
    return x < y;
}

int work(int l,int r,int k)
{
    int i,x,ret=n+1,lim = (r-l+1)/k;
    for(i=1;i<=TRY;i++)
    {
        x = A[bigr()%(r-l+1)+l];
        if(cnt[x] > lim) ret = ret < x ? ret : x;
    }
    return ret > n ? -1 : ret;
}

int main()
{
    int i,l,r;
    srand(19970702);
    
    scanf("%d%d",&n,&q); MAGIC = sqrt(n);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1;i<=q;i++) scanf("%d%d%d",&qry[i].L,&qry[i].R,&qry[i].K), qry[i].ID = i;
    sort(qry+1,qry+1+q,cmp);
    
    l = 1; r = 0;
    for(i=1;i<=q;i++)
    {
        while(l > qry[i].L) cnt[A[--l]]++;
        while(r < qry[i].R) cnt[A[++r]]++;
        while(l < qry[i].L) cnt[A[l++]]--;
        while(r > qry[i].R) cnt[A[r--]]--;
        ans[qry[i].ID] = work(qry[i].L,qry[i].R,qry[i].K);
    }
    
    for(i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}

