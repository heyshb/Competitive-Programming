#include <stdio.h>
#include <string.h>
#define INF 9999999

int tcase,n,m,K,ans;
int edges[1010][2];

int S,T,tot,e[500010][2],siz[500010],p[10010];
int dis[10010],from[10010],cur[10010],gap[10010];

void adde(int sn,int fn,int val)
{
    e[++tot][0] = fn; e[tot][1] = p[sn]; p[sn] = cur[sn] = tot; siz[tot] = val;
    e[++tot][0] = sn; e[tot][1] = p[fn]; p[fn] = cur[fn] = tot; siz[tot] = 0;
}

int sap()
{
    int i,mmin,sn = S,flow = INF,lim = T+1,ret = 0;
    memset(dis,0,sizeof(dis)); memset(gap,0,sizeof(gap));
    gap[0] = lim;

    while(dis[S] <= lim)
    {
        for(i=cur[sn];i;i=e[i][1]) if(siz[i]>0 && dis[sn] == dis[e[i][0]]+1) break;
        cur[sn] = i;
        if(i)
        {
            sn = e[i][0]; from[sn] = i;
            flow = flow<siz[i]?flow:siz[i];
            if(sn != T) continue;
            ret += flow;
            for(;sn!=S;sn=e[from[sn]^1][0]) { siz[from[sn]] -= flow; siz[from[sn]^1] += flow;}
            flow = INF;
        }
        else
        {
            if(--gap[dis[sn]] == 0) break;
            cur[sn] = p[sn]; mmin = lim+3;
            for(i=p[sn];i;i=e[i][1]) if(siz[i]>0) mmin = mmin<dis[e[i][0]]?mmin:dis[e[i][0]];
            gap[dis[sn] = mmin+1]++;
            if(sn != S) sn = e[from[sn]^1][0];
        }
    }
    return ret;
}

void build(int lim)
{
    int i,j,sn,fn;
    tot = 1; memset(p,0,sizeof(p));
    S = 0; T = (n+1)*n+1;

    for(i=1;i<=m;i++)
    {
        sn = edges[i][0];
        fn = edges[i][1];
        for(j=0;j<lim;j++)
            adde(sn+j*n,fn+(j+1)*n,1);
    }

    adde(S,1,K);
    for(i=1;i<=lim;i++) adde(n+i*n,T,INF);
}

int work()
{
    int head = 1,tail = n+1,mid;
    while(head < tail)
    {
        mid = (head+tail) >> 1;
        build(mid);
        if(sap() == K) tail = mid;
        else head = mid + 1;
    }
    return head <= n ? head : -1;
}

int main()
{
	freopen("robot.in","r",stdin);
	freopen("tsr.out","w",stdout);
    int i;

    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d%d%d",&n,&m,&K);
        for(i=1;i<=m;i++) scanf("%d%d",&edges[i][0], &edges[i][1]);
        printf("%d\n",work());
    }

    return 0;
}
