#include <bits/stdc++.h>
using namespace std;

const int maxn = 600100;
struct Edge
{
    int no,v,next;      //no：边的编号
}edges[maxn];

int n,m,ebcnum;         
int e,head[maxn];
int pre[maxn];          
int dfs_clock;          
int isbridge[maxn];     
vector<int> ebc[maxn];  

void addedges(int num,int u,int v)    //加边
{
    edges[e].no = num;
    edges[e].v = v;
    edges[e].next = head[u];
    head[u] = e++;
    edges[e].no = num++;
    edges[e].v = u;
    edges[e].next = head[v];
    head[v] = e++;
}

int dfs_findbridge(int u,int fa)    //找出所有的桥
{
    int lowu = pre[u] = ++dfs_clock;
    for(int i=head[u];i!=-1;i=edges[i].next)
    {
        int v = edges[i].v;
        if(!pre[v])
        {
            int lowv = dfs_findbridge(v,u);
            lowu = min(lowu,lowv);
            if(lowv > pre[u])
            {
                isbridge[edges[i].no] = 1; //桥
            }
        }
        else if(pre[v] < pre[u] && v != fa)
        {
            lowu = min(lowu,pre[v]);
        }
    }
    return lowu;
}

void dfs_coutbridge(int u,int fa)     //保存边_双连通分量的信息
{
    ebc[ebcnum].push_back(u);
    pre[u] = ++dfs_clock;
    for(int i=head[u];i!=-1;i=edges[i].next)
    {
        int v = edges[i].v;
        if(!isbridge[edges[i].no] && !pre[v]) dfs_coutbridge(v,u);
    }
}

void init()
{
    memset(pre,0,sizeof(pre));
    memset(isbridge,0,sizeof(isbridge));
    memset(head,-1,sizeof(head));
    e = 0; ebcnum = 0;
}

vector<pair<int,int> >seg;
typedef long long LL;
struct query
{
	int L,R,num;
}q[maxn];
int Q;
LL ans[maxn];
multiset<int>s;
vector<pair<int,int> >qs[maxn];
vector<int>R[maxn];
LL ansl[maxn],S[maxn];

LL C(LL x)
{
	return x * (x + 1) / 2;
}

int main()
{
    int u,v;
    scanf("%d%d",&n,&m);
	 
    init();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        addedges(i,u,v);
    }
    dfs_findbridge(1,-1);
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        if(!pre[i])
        {
            ebc[ebcnum].clear();
            dfs_coutbridge(i,-1);
            ebcnum++;
        }
    }
    for(int i=0;i<ebcnum;i++)
    {
    	int mi = 10000000, ma = -1;
        for(int j=0;j<ebc[i].size();j++)
    	{
            //cout<<ebc[i][j]<<" ";
            mi = min(mi,ebc[i][j]);
            ma = max(ma,ebc[i][j]);
    	}
    	//cout<<endl;
    	if (ebc[i].size() > 1)
    	{
    		R[mi].push_back(ma);
    		s.insert(ma);
    		//printf("seg %d %d\n",mi,ma);
    	}
    }
    s.insert(n+1);
    scanf("%d",&Q);
    for (int i=1;i<=Q;i++)
    {
    	int u,v;
    	scanf("%d%d",&u,&v);
    	q[i] = (query){u,v,i};
    	qs[u].push_back(make_pair(v,i));
	}
	for (int i=1;i<=n;i++)
	{
		ansl[i] = (*s.begin()) - 1;//ansl : the max right p
		//printf("ansl[%d]=%lld\n",i,ansl[i]);
		for (auto t:R[i]) s.erase(t);
	} 
	S[0] = 0;
	for (int i=1;i<=n;i++)
	{
		S[i] = S[i-1] + (ansl[i] - i + 1);
	}
	for (int i=1;i<=Q;i++)
	{
		int l = q[i].L, r = q[i].R, num = q[i].num;
		if (ansl[l] >= r) ans[num] = C(r-l+1);
		else
		{
			int ll = l, rr = r, mid;
			while(ll < rr - 1)
			{
				mid = (ll + rr) / 2;
				if (ansl[mid] >= r)
					rr = mid;
				else
					ll = mid;
			}		
			//printf("fuck %d\n",ll);
			//printf("%lld\n",S[ll] - S[l-1]);
			ans[num] = S[ll] - S[l-1] + C(r - ll);
		}
	}
    for (int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
    return 0;
}
