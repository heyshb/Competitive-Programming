
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
#define Pair pair<int,int>
const int MOD = 1073741824;
const int N = 3000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
 
struct Edge {
    int to,next;
} edge[N*N*2];
int head[N],tot;
int n;//n个点
int father[N],pre[N];//father记录一个点属于哪个一个点为根的花
int Q[N*N*2],first,tail;//bfs队列
int match[N];//匹配
bool odd[N],vis[N];//odd记录一个点为奇点/偶点，1为奇，0为偶
int timeBlock;//LCA时间戳
int top[N],rinedge[N];
 
void addEdge(int x,int y) {//添边
    edge[tot].to=y;
    edge[tot].next=head[x];
    head[x]=tot++;
}
int Find(int x){//并查集寻找根节点
    if(father[x]!=x)
        return father[x]=Find(father[x]);
    return x;
}
int lca(int x, int y){//求解最近公共祖先
    timeBlock++;
    while(x){
        rinedge[x]=timeBlock;
        x=Find(top[x]);
    }
    x=y;
    while(rinedge[x]!=timeBlock)
        x=Find(top[x]);
    return x;
}
void blossom(int x, int y, int k) {//将奇环缩成一个点并将原来是奇点的点变为偶点并加入队列
    while(Find(x)!=Find(k)){
        pre[x]=y;
 
        y=match[x];
        odd[y]=false;
        Q[tail++]=y;
 
        father[Find(x)]=k;
        father[Find(y)]=k;
 
        x=pre[y];
    }
}
bool bfs(int s) {
    memset(top,0,sizeof(top));
    memset(pre,0,sizeof(pre));
    memset(odd,false,sizeof(odd));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        father[i]=i;
 
    vis[s]=true;
    first=tail=0;
    Q[tail++]=s;
 
    while(first!=tail){
        int now=Q[first++];
        for(int i=head[now];i!=-1;i=edge[i].next){
            int to=edge[i].to;
            if(!vis[to]){
                top[to]=now;
                pre[to]=now;
                odd[to]=true;
                vis[to]=true;
 
                if(!match[to]){
                    int j=to;
                    while(j){
                        int x=pre[j];
                        int y=match[x];
                        match[j]=x;
                        match[x]=j;
                        j=y;
                    }
                    return true;
                }
 
                vis[match[to]]=true;
                top[match[to]]=to;
                Q[tail++]=match[to];
            }
            else if(Find(now)!=Find(to) && odd[to]==false) {
                int k=lca(now,to);
                blossom(now,to,k);
                blossom(to,now,k);
            }
        }
    }
    return false;
}
 
int main() {
 
    memset(head,-1,sizeof(head));
    memset(match,0,sizeof(match));
    tot=0;
 
    int m;
    int k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addEdge(x,y);
        addEdge(y,x);
    }
 
    int res=0;
    for(int i=1;i<=n;i++)
        if(!match[i])
            res+=bfs(i);
    printf("%d\n",res);
    /*
    for(int i=1;i<=n;i++)
        printf("%d ",match[i]);
    printf("\n");
    */
 
    return 0;
}