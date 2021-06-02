#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200011;
const int MAXM = 400011;
int n,m,q,val[MAXN],w[MAXN],col[MAXN],pre[MAXN],belong[MAXN],stk[MAXN],top,cc,vis[MAXN];
int ecnt,first[MAXN],to[MAXM],nxt[MAXM],cnt1,cnt2,block,deep[MAXN],f[MAXN][18],dfn[MAXN];
LL A[MAXN],ans;
unordered_map<int,int> Tim;
struct ask{int l,r,t,lb,rb,id;}a[MAXN];
struct UP{int x,y,pre;}b[MAXN];
inline bool cmp(ask q,ask qq){
    if(q.lb==qq.lb && q.rb==qq.rb) return q.t<qq.t;
    if(q.lb==qq.lb) return q.rb<qq.rb;
    return q.lb<qq.lb;
}
inline void link(int x,int y){ nxt[++ecnt]=first[x]; first[x]=ecnt; to[ecnt]=y; }
inline int getint(){
    int w=0,q=0; char c=getchar(); while((c<'0'||c>'9') && c!='-') c=getchar();
    if(c=='-') q=1,c=getchar(); while (c>='0'&&c<='9') w=w*10+c-'0',c=getchar(); return q?-w:w;
}
 
inline int lca(int x,int y){ 
    if(deep[x]<deep[y]) swap(x,y); int t=0; while((1<<t)<=deep[x]) t++; t--;
    for(int i=t;i>=0;i--) if(deep[x]-(1<<i)>=deep[y]) x=f[x][i]; if(x==y) return y;
    for(int i=t;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i]; return f[x][0];
}
 
inline int dfs(int x,int fa){
    int remain=0; dfn[x]=++cc;
    for(int i=first[x];i;i=nxt[i]) {
        int v=to[i]; if(v==fa) continue;
        f[v][0]=x; deep[v]=deep[x]+1; remain+=dfs(v,x);
        if(remain>=block) {
            ecnt++;
            while(remain>0)/*!!!*/ belong[stk[top]]=ecnt,top--,remain--;
            remain=0;
        }
    }
    stk[++top]=x;
    return remain+1;
}
 
inline void update(int x){//??x????
    if(vis[x]) {//??????
        vis[x]=0;//????????
        //ans-=(LL)w[ Tim[col[x]] ]*val[col[x]];
        Tim[col[x]]--;
        if (Tim[col[x]]==0) ans--;
    }
    else{//??????
        vis[x]=1;
        Tim[col[x]]++;
        if (Tim[col[x]]==1) ans++;
        //ans+=(LL)w[ Tim[col[x]] ]*val[col[x]];//!!!
    }
}
 
inline void change(int x,int y){
    while(x!=y) {
        if(deep[x]<deep[y]) update(y),y=f[y][0];
        else update(x),x=f[x][0];
    }
}
 
inline void modify(int x,int C){//?x?????C
    if(!vis[x]) col[x]=C;
    else {
        update(x);
        col[x]=C;
        update(x);     
    }
}
 
inline void work(){
	int cocnt = 0;
    n=getint(); q=getint(); int x,y; block=(int)pow(n,0.67);
    for(int i=1;i<=n;i++) 
	{
		col[i]=getint(),pre[i]=col[i];
		/*
		if (rc[col[i]])
			col[i] = rc[col[i]];
		else
			col[i] = (rc[col[i]] = ++cocnt);
		*/
	}
    for(int i=1;i<n;i++) { x=getint(); y=getint(); link(x,y); link(y,x); }
    ecnt=0; deep[1]=1; dfs(1,0);
    int ljh,LCA; for(int j=1;j<=17;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
    for(int o=1;o<=q;o++) {
        ljh=getint(); x=getint(); y=getint();
        if(ljh==2) 
		{ 
			/*
			if (rc[y])
				y = rc[y];
			else
				y = (rc[y] = ++cocnt);
			*/
			b[++cnt2].pre=pre[x]; 
			b[cnt2].x=x; 
			b[cnt2].y=y; 
			pre[x]=y;/*!!!*/ 
		}
        else
		{
            if(dfn[x]>dfn[y]) swap(x,y);
            a[++cnt1].l=x; a[cnt1].r=y;
            a[cnt1].lb=belong[x]; a[cnt1].rb=belong[y];
            a[cnt1].t=cnt2; a[cnt1].id=cnt1;
        }
    }
    sort(a+1,a+cnt1+1,cmp); cnt2=a[1].t;
    for(int i=1;i<=a[1].t;i++) modify(b[i].x,b[i].y);
    change(a[1].l,a[1].r); LCA=lca(a[1].l,a[1].r);
    update(LCA);//lca????
    A[a[1].id]=ans;
    update(LCA);
    for(int i=2;i<=cnt1;i++) {
        while(cnt2<a[i].t) cnt2++,modify(b[cnt2].x,b[cnt2].y);
        while(cnt2>a[i].t) modify(b[cnt2].x,b[cnt2].pre),cnt2--;
        change(a[i-1].l,a[i].l);
        change(a[i-1].r,a[i].r);
        LCA=lca(a[i].l,a[i].r);
        update(LCA);
        A[a[i].id]=ans;
        update(LCA);
    }
    for(int i=1;i<=cnt1;i++) printf("%lld\n",A[i]);
}
 
int main()
{
    work();
    return 0;
}
