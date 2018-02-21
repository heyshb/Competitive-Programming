#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn=500010;  
const int maxm=500010;  
int n;  
struct note  
{  
    int to;  
    int next;  
}edge[1000010];  
int head[maxn];  
int ip;  
int dfn[maxn],low[maxn],sccno[maxn],cnt,scc,instack[maxn];  
stack<int>stk;  
void init()  
{  
    memset(head,-1,sizeof(head));  
    ip=0;  
}  
void addedge(int u,int v)  
{  
    edge[ip].to=v,edge[ip].next=head[u],head[u]=ip++;  
}  
void adddouble(int u,int v)
{
	addedge(u,v);
	addedge(v,u);
}
void dfs(int u)  
{  
    dfn[u]=low[u]=++scc;  
    stk.push(u);  
    instack[u]=1;  
    for (int i=head[u]; i!=-1; i=edge[i].next)  
    {  
        int v=edge[i].to;  
        if (!dfn[v])  
        {  
            dfs(v);  
            low[u]=min(low[u],low[v]);  
        }  
        else if (instack[v])  
            low[u]=min(low[u],dfn[v]);  
    }  
    if (low[u]==dfn[u])  
    {  
        cnt++;  
        int x;  
        do  
        {  
            x=stk.top();  
            stk.pop();  
            sccno[x]=cnt;  
            instack[x]=0;  
        }while (x!=u);  
    }  
}  
bool solve()  
{  
    scc=cnt=0;  
    memset(sccno,0,sizeof(sccno));  
    memset(dfn,0,sizeof(dfn));  
    memset(low,0,sizeof(low));  
    memset(instack,0,sizeof(instack));  
    while (!stk.empty()) stk.pop();  
    for (int i=0; i<2*n; i++) if (!dfn[i]) dfs(i);  
    for (int i=0; i<2*n; i+=2)  
    {  
        if (sccno[i]==sccno[i^1]) return false;  
    }  
    return true;  
}  

int N,M,R[100010];
vector<int>e[100010];

int main()
{
	
	scanf("%d%d",&N,&M);
	n = M;
	init();
	for (int i=1;i<=N;i++)scanf("%d",&R[i]);
	for (int i=0;i<M;i++)
	{
		int X;
		scanf("%d",&X);
		while(X--)
		{
			int tmp;
			scanf("%d",&tmp);
			e[tmp].push_back(i);
		}
	}
	for (int i=1;i<=N;i++)
	{
		int X=e[i][0],Y=e[i][1];
		if (R[i])
		{
			adddouble(X*2,Y*2);
			adddouble(X*2+1,Y*2+1);
		}
		else
		{
			adddouble(X*2,Y*2+1);
			adddouble(X*2+1,Y*2);
		}
	}
	puts(solve()?"YES":"NO");
}
