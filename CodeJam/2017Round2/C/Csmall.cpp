#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int R,C;
char mp[51][51];
vector<pair<int,int> >beam;
bool b[51][51];

#define MAXN   
#define MAXM //������Ŀ����   
#define eps 1e-5  
using namespace std;  
struct Edge  
{  
    int from, to, next;  
}edge[MAXM];//ԭͼ  
int head[MAXN], edgenum;   
vector<int> G[MAXN];//�������ͼ   
int in[MAXN];//��ͼSCC�����   
int low[MAXN], dfn[MAXN];//ͨ����Ů�ڵ����ܵ����������������  ���������   
int dfs_clock;//ʱ���   
int sccno[MAXN], scc_cnt;//sccno[i]��ʾi�����ĸ�SCC  scc_cnt��SCC������   
stack<int> S;//�洢��ǰSCC�ĵ�   
bool Instack[MAXN];//�жϵ��Ƿ���ջ����   
int color[MAXN];//Ⱦɫ   
int fp[MAXN];//������ӦSCC��ŵ�ӳ��   
void init()  
{  
    edgenum = 0;  
    memset(head, -1, sizeof(head));   
}  
void addEdge(int u, int v)  
{  
    Edge E = {u, v, head[u]};  
    edge[edgenum] = E;  
    head[u] = edgenum++;  
}   
void getMap()//��ͼ  
{  
      
}   
void tarjan(int u, int fa)//��SCC   
{  
    int v;  
    low[u] = dfn[u] = ++dfs_clock;  
    S.push(u);  
    Instack[u] = true;  
    for(int i = head[u]; i != -1; i = edge[i].next)  
    {  
        v = edge[i].to;  
        if(!dfn[v])  
        {  
            tarjan(v, u);  
            low[u] = min(low[u], low[v]);  
        }  
        else if(Instack[v])  
        low[u] = min(low[u], dfn[v]);  
    }  
    if(low[u] == dfn[u])  
    {  
        scc_cnt++;  
        for(;;)  
        {  
            v = S.top(); S.pop();  
            Instack[v] = false;  
            sccno[v] = scc_cnt;  
            if(v == u) break;  
        }  
    }  
}  
void find_cut(int l, int r)  
{  
    memset(low, 0, sizeof(low));  
    memset(dfn, 0, sizeof(dfn));  
    memset(sccno, 0, sizeof(sccno));  
    memset(Instack, false, sizeof(Instack));  
    dfs_clock = scc_cnt = 0;  
    for(int i = l; i <= r; i++)  
    if(!dfn[i]) tarjan(i, -1);  
}  
void suodian()//���� + ����ͼ   
{  
    for(int i = 1; i <= scc_cnt; i++) G[i].clear(), in[i] = 0;  
    for(int i = 0; i < edgenum; i++)  
    {  
        int u = sccno[edge[i].from];  
        int v = sccno[edge[i].to];  
        if(u != v)  
        G[v].push_back(u), in[u]++; //����ͼ   
    }   
}  
void toposort()//�������� + Ⱦɫ   
{  
    queue<int> Q;  
    memset(color, 0, sizeof(color));  
    for(int i = 1; i <= scc_cnt; i++) if(in[i] == 0) Q.push(i);  
    while(!Q.empty())  
    {  
        int u = Q.front();  
        Q.pop();  
        if(color[u] == 0)//û����ɫ   
        {  
            color[u] = 1;//Ⱦɫ   
            color[fp[u]] = 2;  
        }  
        for(int i = 0; i < G[u].size(); i++)  
        {  
            int v = G[u][i];  
            if(--in[v] == 0)//��ȼ�һ   
            Q.push(v);  
        }  
    }  
}  
bool solve()  
{  
    memset(fp, 0, sizeof(fp));  
    for(int i = 0; i < N; i++)  
    {  
        if(sccno[2*i] == sccno[2*i + 1])  
        {  
            return false;  
        }  
        else  
        {  
            fp[sccno[2*i]] = sccno[2*i + 1];  
            fp[sccno[2*i + 1]] = sccno[2*i];  
        }  
    }  
    suodian(); 
    toposort(); 
    for(int i = 1; i < N; i++)  
    {  
        if(color[sccno[2*i]] == 1)//���н�   
        printf("");  
    }  
    printf("\n");  
    return true;
}  

int main()
{
	freopen("Csmall.in","r",stdin);
	freopen("Csmall.out","w",stdout);
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d%d",&R,&C);
		for (int i=1;i<=R;i++)scanf("%s",mp[i]+1);
		beam.clear();
		memset(b,false,sizeof(b));
		for (int i=1;i<=R;i++)
			for (int j=1;j<=C;j++)
			if (mp[i][j] == '|' || mp[i][j] == '-')
			{
				b[i][j] = true;
				beam.push_back(make_pair(i,j));
			}
		for (int i=0;i<beam.size();i++)
	}
}
