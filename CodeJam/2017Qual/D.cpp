#include <bits/stdc++.h>

using namespace std;

//+ x o 1 2 3 
int sum1[2][110];
int sum2[2][220];//i+j i-j+N
int v[110][110];
int aft[110][110];
int N;
int NN;
vector<int>v1,v2;
vector<int>e[210];
bool state[210];
int result[210];

void makegraph1()
{
	//printf("MAKEGRAPH1\n");
	v1.clear();
	v2.clear();
	for (int i=1;i<=N;i++)if (!sum1[0][i]) v1.push_back(i);
	for (int i=1;i<=N;i++)if (!sum1[1][i]) v2.push_back(i);
	//for (auto t:v1) printf("%d\n",t);
	for (int i=1;i<=N;i++)e[i].clear();
	//printf("%d %d %d\n",v[1][2],sum1[0][1],sum2[1][2]);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
		if (v[i][j] != 2 && v[i][j] != 3 && !sum1[0][i] && !sum1[1][j])
		{
			//printf("%d --> %d\n",i,j);
			e[i].push_back(j);
		}
	NN = N;
}

void makegraph2()
{
	//printf("MAKEGRAPH2\n");
	v1.clear();
	v2.clear();
	for (int i=1;i<=N*2;i++)if (!sum2[0][i]) v1.push_back(i);
	for (int i=1;i<=N*2;i++)if (!sum2[1][i]) v2.push_back(i);
	//for (auto t:v1) printf("%d\n",t);
	for (int i=1;i<=N*2;i++)e[i].clear();
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
		if (v[i][j] != 1 && v[i][j] != 3 && !sum2[0][i+j] && !sum2[1][i-j+N])
		{
			//printf("%d-->%d\n",i+j,i-j+N);
			e[i+j].push_back(i-j+N);
		}
	NN = 2*N;
}

bool find(int x)
{
	for (int i=0;i<e[x].size();i++)
	{
		int Y = e[x][i];
		if (state[Y]) continue;
		state[Y] = true;
		if (result[Y] == 0 || find(result[Y]))
		{
			result[Y] = x;
			return true;
		}
	}
	return false;
}

int run()
{
	int res = 0;
	memset(result,0,sizeof(result));
	for (int i=1;i<=NN;i++)
	{
		memset(state,false,sizeof(state));
		if (find(i)) res++;
		//printf("%d %d\n",i,res);
	}
	return res;
}

int main()
{
	freopen("Dl.in","r",stdin);
	freopen("Dl.out","w",stdout);
	int Casi,M;
	scanf("%d",&Casi);
	for (int _=1;_<=Casi;_++)
	{
		memset(v,false,sizeof(v));
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		scanf("%d%d",&N,&M);
		int ans = 0;
		for (int i=1;i<=M;i++)
		{
			char tmp[2];
			int V,x,y;
			scanf("%s",tmp);
			if (tmp[0] == '+')
				V = 1;
			else if (tmp[0] == 'x')
				V = 2;
			else
				V = 3;
			scanf("%d%d",&x,&y);
			v[x][y] = V;
			if (V != 1)
			{
				ans++;
				sum1[0][x]++;
				sum1[1][y]++;
				//printf("FUCK 0 %d 1 %d\n",x,y);
			}
			if (V != 2)
			{
				ans++;
				sum2[0][x+y]++;
				sum2[1][x-y+N]++;
			}
		}
		memset(aft,0,sizeof(aft));
		makegraph1();
		ans+=run();
		int cnt = 0;
		for (int i=1;i<=N;i++)
		if (result[i])
		{
			int L = result[i];
			if (!aft[L][i]) cnt++;
			aft[L][i] += 2;
		}
		//0printf("FUCK %d\n",ans);
		makegraph2();
		ans+=run();
		for (int i=1;i<=2*N;i++)
		if (result[i])// x+y = result[i]    x-y+N = i --> 2x+N = i+res
 		{
 			int x = (result[i]+i-N)/2, y = (result[i]-i+N)/2;
 			if (!aft[x][y]) cnt++;
 			aft[x][y] += 1;
		}
		printf("Case #%d: %d %d\n",_,ans,cnt);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
			if (aft[i][j]) 
			{
				if (aft[i][j]+v[i][j] == 1) printf("+ ");
				if (aft[i][j]+v[i][j] == 2) printf("x ");
				if (aft[i][j]+v[i][j] == 3) printf("o ");
				printf("%d %d\n",i,j);
			}
	}
}
