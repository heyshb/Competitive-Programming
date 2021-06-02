#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#define INF 1000000000
const int N = 20000 + 11 , M = 300000 + 11 ;
using namespace std ;
int  n , m ,k;
int tot , head[N] ;
long long ans; 
struct id 
{
    int to , nxt ;
    long  long val ;
} edge[M<<1] ; 
queue< int > Q;
int dis[N] ,cur[N],s,t; 
bool vis[N]; 
bool nosol;

int read(  )
{
    char ch = getchar(  ) ; int k = 1 , ret = 0 ;
    while( ch > '9' || ch < '0' ) { if( ch == '-' ) k = -1 ; ch = getchar( ) ; }
    while( ch <= '9' && ch >= '0' ) ret = ret * 10 + ch - '0' , ch = getchar( ) ;
    return ret * k ;
}


void adde( int u , int v , int c )
{
    edge[++tot].to = v , edge[tot].nxt = head[u] ;
    edge[tot].val = c , head[u] = tot ;
}

void add(int u,int v,int c)
{
	printf("Add %d %d %d\n",u,v,c);
	adde(u,v,c);
	adde(v,u,0);
}

int LL[1010],RR[1010];

int getnum(int TM,int num)
{
	return TM*n + num;
}

void input(  )
{
    n = read( ) , m = read( ) , k = read();
    nosol = false;
    if (k > n) nosol = true;
    memset( head , -1 , sizeof( head ) ) ;
    tot = 1 ;
    for( int x = 1 ; x <= m ; ++x  )
    {
        LL[x] = read();
        RR[x] = read();
    }
    s = getnum(n,n)+1;
	t = getnum(n,n)+2;
	
    for (int TT=0;TT<n;TT++)
    {
    	for (int i=1;i<=m;i++)
    		add(getnum(TT,LL[i]),getnum(TT+1,RR[i]),1);
    }
    add(s,getnum(0,1),k);
    for (int TT=0;TT<=n;TT++)
    {
    	add(getnum(TT,n),t,INF);
    } 
}

bool bfs(  )
{
    //memset( dis , -1 , sizeof(dis) ) ;
    memset(vis,false,sizeof(vis));
    Q.push( s ) ; dis[s] = 0 ;
    vis[s] = true;
    while( !Q.empty( ) )
    {
        int u = Q.front( ) ; Q.pop( ) ;
        //printf("%d\n",u); 
        for( int i = head[u] ; ~i ; i = edge[i].nxt )
        {
                
            int v = edge[i].to ;
            if( dis[v] < 0 && edge[i].val > 0 ) 
            {
                dis[v] = dis[u] + 1 ; Q.push( v ) ;
            }
            
        } 
    }
//    cout<<endl;
    return vis[t];
}


long long int dfs( int u , int inf )
{
    long long int ans = 0ll , cost = 0ll;
    if( u == t ) return inf ;
    for( int i = cur[u] ; ~i ; i = edge[i].nxt )
    {
        int  v = edge[i].to ;
        if( dis[v] != dis[u] + 1 ) continue ;
        ans = dfs( v , min( inf - cost , edge[i].val ) ) ;
        edge[i].val -= ans ;
        edge[i^1].val += ans ;
        if( edge[i].val ) cur[u] = i ;
        cost += ans ; 
        if( cost == inf ) return inf ;
    }
    if( !cost ) dis[u] = -1 ;
    return  cost ;
}


void sov(  )
{
	if (nosol)
	{
		puts("-1");
		return;
	}
    ans = 0 ;
    while( bfs( ) )
    {
    	//puts("fuck");
        int now ;  
        for( int i = 1 ; i <= t ; ++i ) cur[i] = head[i] ;
        ans += dfs( 1 , 1<<30 ) ;        
    }
    printf("%lld %d\n",ans,k);
    if (ans == k)
    	printf("%d\n",dis[t]);
    else 
    	puts("-1");
}


int main(  )
{
//    Init( ) ;
	int T;
	scanf("%d",&T);
	while(T--)
	{
	    input(  ) ;
	    sov( ) ;
	}	
//    fclose( stdin ) ;
//    fclose( stdout ) ;
    return 0 ;
}
