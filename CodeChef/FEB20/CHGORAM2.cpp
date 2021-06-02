#include<bits/stdc++.h>
#define N 201010
#define M 1000000007
#define LL long long
using namespace std;
LL E[5555555];
LL an,*f[N],*g[N];
int T,n,i,x,y,tot,o,fir[N],ne[N*2],la[N*2],mx[N],F[N],hs[N],to[N],sz[N];
int col[N];
void ins(int x,int y){la[++tot]=y;ne[tot]=fir[x];fir[x]=tot;}
void dfs(int x){
    mx[x]=1;to[x]=x;
    for(int i=fir[x],y;i;i=ne[i])if(y=la[i],F[x]!=y){
        F[y]=x;dfs(y);mx[x]=max(mx[x],mx[y]+1);
        if(mx[y]>mx[hs[x]])hs[x]=y,to[x]=to[y];
    }
    sz[to[x]]=mx[x];
}
void work(int x,int y){
    for(int i=0;i<=mx[y];i++)an+=f[y][i]*g[x][i+1]+g[y][i]*f[x][i-1];
    for(int i=0;i<=mx[y];i++)g[x][i+1]+=f[y][i]*f[x][i+1],g[x][i-1]+=g[y][i],f[x][i+1]+=f[y][i];
}
void dfs2(int x){
    if(to[x]==x){f[x][0]=col[x];return;}
    dfs2(hs[x]);f[x]=f[hs[x]]-1;g[x]=g[hs[x]]+1;f[x][0]=col[x];if (col[x]) an+=g[x][0];
    int i,j,y;
    for(j=fir[x];j;j=ne[j])if(y=la[j],y!=F[x]&&y!=hs[x])dfs2(y),work(x,y);
    /*
    printf("dfs %d\n",x);
    for (int i=0;i<=2;i++) {
        printf("f[%d][%d]=%d\n",x,i,f[x][i]);
        printf("g[%d][%d]=%d\n",x,i,g[x][i]);
    }
    */
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);an=tot=0;o=1;
        for(i=1;i<n;i++)scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
        for(i=1;i<=n;i++) {
            scanf("%d",&col[i]);
        }
        dfs(1);
        for(i=1;i<=n;i++)if(to[i]==i){
            o+=sz[i]-1;
            f[i]=&E[o];
            o++;
            g[i]=&E[o];
            o+=sz[i]*2+2;
        }
        dfs2(1);
        printf("%lld\n",an * 6);
        for (i=1;i<=n;i++) {
            fir[i] = 0;
            F[i] = 0;
            mx[i] = 0;
            sz[i] = 0;
            to[i] = 0;
            hs[i] = 0;
        }
        for (i=1;i<=o;i++) {
            E[i] = 0;
        }
    }   
}