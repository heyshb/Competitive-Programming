#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int MAXN=22000,MAXM=80000;
struct Dinic{
    struct edge{
        int x,y;//�������� 
        int c;//���� 
        int f;//��ǰ���� 
        edge *next,*back;//��һ���ߣ������ 
        edge(int x,int y,int c,edge* next):x(x),y(y),c(c),f(0),next(next),back(0){}
        void* operator new(size_t, void *p){return p;}
    }*E[MAXN],*data;//E[i]���涥��i�ı߱�
    char storage[2*MAXM*sizeof(edge)];
    int S,T;//Դ����
    
    int Q[MAXN];//DFS�õ���queue
    int D[MAXN];//�����ţ�-1��ʾ���ɴ�
    void DFS(){
        memset(D,-1,sizeof(D));
        int head=0,tail=0;
        Q[tail++]=S;
        D[S]=0;
        for(;;){
            int i=Q[head++];
            for(edge* e=E[i];e;e=e->next){
                if(e->c==0)continue;
                int j=e->y;
                if(D[j]==-1){
                    D[j]=D[i]+1;
                    Q[tail++]=j;
                    if(j==T)return;
                }
            }
            if(head==tail)break;
        }
    }
    edge* cur[MAXN];//��ǰ��
    edge* path[MAXN];//��ǰ�ҵ�������·
    int flow(){
        int res=0;//������������� 
        int path_n;//path�Ĵ�С
        for(;;){
            DFS();
            if(D[T]==-1)break;
            memcpy(cur,E,sizeof(E));
            path_n=0;
            int i=S;
            for(;;){
                if(i==T){//���ҵ�һ������·������֮ 
                    int mink=0;
                    int delta=INT_MAX;
                    for(int k=0;k<path_n;++k){
                        if(path[k]->c < delta){
                            delta = path[k]->c;
                            mink=k;
                        }
                    }
                    for(int k=0;k<path_n;++k){
                        path[k]->c -= delta;
                        path[k]->back->c += delta;
                    }
                    path_n=mink;//���� 
                    i=path[path_n]->x;
                    res+=delta;
                }
                edge* e;
                for(e=cur[i];e;e=e->next){
                    if(e->c==0)continue;
                    int j=e->y;
                    if(D[i]+1==D[j])break;//�ҵ�һ�������ӵ�·���� 
                }
                cur[i]=e;//��ǰ���ṹ�����ʹ��Ĳ�������Ļ������ٷ���
                if(e){
                    path[path_n++]=e;
                    i=e->y;
                }
                else{//�ýڵ���û���κο�����Ļ�����ͼ��ɾȥ������һ�� 
                    D[i]=-1;
                    if(path_n==0)break;
                    path_n--;
                    i=path[path_n]->x;
                }
            }
        }
        return res;
    }
    int cut(int* s){
        int rst=0;
        for(int i=0;i<MAXN;++i)
            if(D[i]==-1&&E[i])
                s[rst++]=i;
        return rst;
    }
    void init(int _S,int _T){
        S=_S,T=_T;
        data=(edge*)storage; 
        memset(E,0,sizeof(E));
    }
    void add_edge(int x,int y,int w){//�ӽ�һ��x��y����Ϊw�ıߣ���Ҫ��֤0<=x,y<MAXN��0<w<=INT_MAX 
        E[x]=new((void*)data++) edge(x,y,w,E[x]);
        E[y]=new((void*)data++) edge(y,x,0,E[y]);
        E[x]->back = E[y];
        E[y]->back = E[x];
    }
}dinic;

int V,E,N,K;
int cnt[610];
int dis[610][610];
int mindis[610];
vector<pair<int,int> >e[610];
bool calced[610];
const int INF = 1e9;
int _S,_T;

void dij(int st)
{
	for (int i=1;i<=V;i++)dis[st][i] = INF,calced[i] = false,mindis[i] = INF;
	calced[st] = true;
	dis[st][st]	= 0;
	for (auto t:e[st]) mindis[t.X] = min(mindis[t.X],t.Y);
	for (int i=2;i<=V;i++)
	{
		int mi = INF, minpos = -1;
		for (int j=1;j<=V;j++)
		if (!calced[j] && mindis[j] < mi)
		{
			mi = mindis[j];
			minpos = j;
		}
		if (minpos == -1) break;
		dis[st][minpos] = mindis[minpos];
		calced[minpos] = true;
		for (auto t:e[minpos])
			mindis[t.X] = min(mindis[t.X],dis[st][minpos] + t.Y);
	}
}

bool check(int TT)
{
	dinic.init(_S,_T);
	for (int i=1;i<=V;i++)
	if (cnt[i])
	{
		dinic.add_edge(_S,i,cnt[i]);
		for (int j=1;j<=V;j++)
		if (dis[i][j] <= TT)
			dinic.add_edge(i,j+V,1); 
	}
	for (int i=1;i<=V;i++)
		dinic.add_edge(V+i,_T,1);
	int res = dinic.flow();
	return res >= K;
}

int main()
{
	scanf("%d%d%d%d",&V,&E,&N,&K);
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		cnt[tmp]++;
	}
	for (int i=1;i<=E;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	_S = 2 * V + 1, _T = 2 * V + 2;
	for (int i=1;i<=V;i++)
	if (cnt[i]) dij(i);
	int L = 0, R = 18000000;
	if (!check(R))
	{
		puts("-1");
		return 0;
	}
	if (check(L))
	{
		puts("0");
		return 0;
	}
	while(L != R-1)
	{
		int mid = (L + R) >> 1;
		if (check(mid))
			R = mid;
		else
			L = mid;
	}
	printf("%d\n",R);
}
