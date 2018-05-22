#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN=42000,MAXM=440000;
struct Dinic {
struct edge {
int x,y; 
int c; 
int f; 
edge *next,*back; 
edge(int x,int y,int c,edge *next):x(x),y(y),c(c),f(0),next(next),back(0) {}
void *operator new(size_t, void *p) {
return p;
}
} *E[MAXN],*data; 
char storage[2*MAXM *sizeof(edge)];
int S,T; 

int Q[MAXN]; 
int D[MAXN]; 
void DFS() {
memset(D,-1,sizeof(D));
int head=0,tail=0;
Q[tail++]=S;
D[S]=0;
for(;;) {
int i=Q[head++];
for(edge *e=E[i]; e; e=e->next) {
if(e->c==0)continue;
int j=e->y;
if(D[j]==-1) {
D[j]=D[i]+1;
Q[tail++]=j;
if(j==T)return;
}
}
if(head==tail)break;
}
}
edge *cur[MAXN]; 
edge *path[MAXN];
int flow() {
int res=0; 
int path_n; 
for(;;) {
DFS();
if(D[T]==-1)break;
memcpy(cur,E,sizeof(E));
path_n=0;
int i=S;
for(;;) {
if(i==T) { 
int mink=0;
int delta=INT_MAX;
for(int k=0; k<path_n; ++k) {
if(path[k]->c < delta) {
delta = path[k]->c;
mink=k;
}
}
for(int k=0; k<path_n; ++k) {
path[k]->c -= delta;
path[k]->back->c += delta;
}
path_n=mink; 
i=path[path_n]->x;
res+=delta;
}
edge *e;
for(e=cur[i]; e; e=e->next) {
if(e->c==0)continue;
int j=e->y;
if(D[i]+1==D[j])break;
}
cur[i]=e;
if(e) {
path[path_n++]=e;
i=e->y;
} else { 
D[i]=-1;
if(path_n==0)break;
path_n--;
i=path[path_n]->x;
}
 }
 }
 return res;
 }
 int cut(int *s) {
 int rst=0;
 for(int i=0; i<MAXN; ++i)
 if(D[i]==-1&&E[i])
 s[rst++]=i;
 return rst;
 }
 void init(int _S,int _T) {
 S=_S,T=_T;
 data=(edge *)storage;
 memset(E,0,sizeof(E));
 }
 void add_edge(int x,int y,int w) { 
 //printf("%d %d %d\n",x,y,w);
 E[x]=new((void *)data++) edge(x,y,w,E[x]);
 E[y]=new((void *)data++) edge(y,x,0,E[y]);
 E[x]->back = E[y];
 E[y]->back = E[x];
 }
 };


 Dinic dinic;
 
int Cases,N;
int v[110][110];
int gao(int col,int x)
{
	return (col - 1) * N + x;
}
 int main() {
	//freopen("C.in","r",stdin);
 scanf("%d",&Cases);
 int _=0;
 while(Cases--) {
 scanf("%d",&N);
 for (int i=1;i<=N;i++)
 for (int j=1;j<=N;j++)
 {
 	scanf("%d",&v[i][j]);
 	if (v[i][j] < 0) v[i][j] = -v[i][j] + N;
 }
 int rst=0;
 int S=0,T= 4*N*N + 1;
 dinic.init(S,T);
 /*
 for (int i=1;i<=N;i++)
	for (int j=1;j<=N;j++)
		e[gao(v[i][j],i)].push_back(gao(v[i][j],j));
 */
 for (int i=1;i<=2*N*N;i++)
 {
 	dinic.add_edge(S,i,1);
 	dinic.add_edge(2*N*N+i,T,1);
 }
 for (int i=1;i<=N;i++)
 	for (int j=1;j<=N;j++)
 		dinic.add_edge(gao(v[i][j],i),gao(v[i][j],j) + 2*N*N,1);
 rst=dinic.flow();
 printf("Case #%d: %d\n",++_,N*N-rst);
 }
}

