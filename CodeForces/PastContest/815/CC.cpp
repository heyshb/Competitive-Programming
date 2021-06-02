#include<bits/stdc++.h>


using namespace std;

const int maxn = 5010,MAX = 1000000010;

int n,tot;

int V[maxn],V2[maxn];
vector<int> G[maxn];

int f[maxn][maxn][2],size[maxn];
int sum = 0;

void dfs(int u){
	size[u]=0;
	
	for(int i=1;i<=n;i++)f[u][i][1]=MAX;
	for(auto v:G[u])dfs(v);
	for(auto v:G[u]){
		printf("%d %d\n",u,v);
		sum += size[u]*size[v];
		for(int i=size[u];i>=0;i--)
			for(int j=1;j<=size[v];j++){
				f[u][i+j][1]=min(f[u][i+j][1],f[u][i][1]+min(f[v][j][0],f[v][j][1]));
			}
		size[u]+=size[v];
	}
	size[u]++;
	for(int i=size[u];i;i--)f[u][i][1]=f[u][i-1][1]+V[u];f[u][0][1]=MAX;
	
	size[u]=0;
	for(int i=1;i<=n;i++)f[u][i][0]=MAX;
	for(auto v:G[u]){
		for(int i=size[u];i>=0;i--)
			for(int j=1;j<=size[v];j++){
				f[u][i+j][0]=min(f[u][i+j][0],f[u][i][0]+f[v][j][0]);
			}
		size[u]+=size[v];
	}
	size[u]++;
	for(int i=size[u];i;i--)f[u][i][0]=min(f[u][i][0],f[u][i-1][0]+V2[u]);
	
	/*for(int i=1;i<=n;i++)f[u][i][1]=MAX;
	for(auto v:G[u]){
		dfs(v);
		for(int i=size[u];i>=0;i--)
			for(int j=1;j<=size[v];j++){
				f[u][i+j]=min(f[u][i+j],f[u][i]+f[v][j]);
			}
		size[u]+=size[v];
	}
	size[u]++;
	for(int i=size[u];i;i--)f[u][i]=f[u][i-1]+V[u];*/
}

void Work(){
	dfs(1);
	int ans=0;
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<' '<<j<<' '<<f[i][j][0]<<' '<<f[i][j][1]<<endl;
	for(int i=1;i<=n;i++)if(f[1][i][0]<=tot||f[1][i][1]<=tot)ans=i;
	printf("%d\n",ans);
}

void Init(){
	//scanf("%d%d",&n,&tot);
	n = 5000;
	tot = 10000;
	for(int i=1;i<=n;i++){
		int x,y;
		//scanf("%d%d",&x,&y);
		x = y = 1;
		V[i]=x-y;V2[i]=x;
		if(i>=2){
			int t;
			//scanf("%d",&t);
			t = i-1;
			G[t].push_back(i);
			//printf("%d-->%d\n",t,i);
		}
	}
}

int main(){
	Init();
	Work();
	printf("%d\n",sum);
	return 0;
}
