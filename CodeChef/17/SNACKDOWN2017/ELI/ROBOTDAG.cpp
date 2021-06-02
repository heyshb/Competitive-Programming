#include <bits/stdc++.h>
#define INF 1000000000
 
using namespace std;
 
int n,m,k,s,t,ans,tot,d[100010],head[400010],en[400010],nxt[400100],f[400010];
int cur[100010];
bool vis[100010];
queue<int> q;

void init()
{
	memset(d,0,sizeof(d));
	memset(head,0,sizeof(head));
	memset(en,0,sizeof(en));
	memset(nxt,0,sizeof(nxt));
	memset(f,0,sizeof(f));
}
 
bool bfs()
{
    for (int i=1;i<=t;i++) vis[i]=false;
    vis[s]=true;
    d[s]=0;
    q.push(s);
    while (!q.empty())
    {
        int i=q.front();
        q.pop();
        for (int j=head[i];j;j=nxt[j])
            if ((!vis[en[j]])&&(f[j]))
            {
                vis[en[j]]=true;
                d[en[j]]=d[i]+1;
                q.push(en[j]);
            }
    }   
    return vis[t];
}
 
int dfs(int x,int a)
{
    if ((x==t)||(a==0)) return a;
    int flow=0;
    for (int& i=cur[x];i;i=nxt[i])
    if ((f[i])&&(d[en[i]]==d[x]+1))
    {
    	//printf("%d\n",i);
        int ff=dfs(en[i],min(a,f[i]));
        if (!ff) continue;
        f[i]-=ff;
        f[i^1]+=ff;
        flow+=ff;
        a-=ff;
        if (a==0) break;
    }
    return flow;
}
 
void add(int a,int b,int c)
{
	//printf("Add %d-->%d: %d\n",a,b,c);
    tot++;
    en[tot]=b;
    f[tot]=c;
    nxt[tot]=head[a];
    head[a]=tot;
    tot++;
    en[tot]=a;
    f[tot]=0;
    nxt[tot]=head[b];
    head[b]=tot;
}

int LL[1010],RR[1010];

int getnum(int TM,int num)
{
	return TM*n + num;
}
 
int main()
{
	int Cases;
	scanf("%d",&Cases);
	while(Cases--)
	{
		init();
	    scanf("%d%d%d",&n,&m,&k);
	    for (int i=1;i<=m;i++)
	    	scanf("%d%d",&LL[i],&RR[i]);
	    if (k > m)
	    {
	    	puts("-1");
	    	continue;
	    }
	    
	    int MAXT = n;
	    
	    s = getnum(MAXT,n)+1;
	    t = getnum(MAXT,n)+2;
	    ans=0;
	    tot=1;
	    
	    for (int TT=0;TT<MAXT;TT++)
	    {
	    	for (int i=1;i<=m;i++)
	    		add(getnum(TT,LL[i]),getnum(TT+1,RR[i]),1);
	    }
	    add(s,getnum(0,1),k);
	    for (int TT=0;TT<=MAXT;TT++)
	    {
	    	add(getnum(TT,n),t,INF);
	    } 
	    while (bfs()) 
		{
			for (int i=1;i<=t;i++)cur[i] = head[i]; 
			ans+=dfs(s,INF);
		}
		assert(ans <= k); 
	    if (ans < k)
	    	puts("-1");
	    else	
	    	printf("%d\n",d[t]-2);
	}
}
