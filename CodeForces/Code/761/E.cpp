#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int N,D[110]; 
vector<int> e[110];
LL XX[110],YY[110];

LL len;

void dfs(int fa,int x,LL X,LL Y,int dir)
{
	//printf("Calcing %d\n",x);
	len>>=1;
	XX[x] = X;
	YY[x] = Y;
	int tmpdir = 0;
	for (int i=0;i<e[x].size();i++)
	if (e[x][i] != fa)
	{
		int son = e[x][i];
		LL nextX=X,nextY=Y;
		tmpdir = (tmpdir + 1) % 4;
		if (tmpdir == 3-dir)
			tmpdir = (tmpdir + 1) % 4;
		if (tmpdir == 0) nextX+=len;
		else if (tmpdir == 1) nextY-=len;
		else if (tmpdir == 2) nextY+=len;
		else nextX-=len;
		
		//printf("%d ---> %d dir:%d %I64d,%I64d\n",x,son,tmpdir,nextX,nextY);
		dfs(x,son,nextX,nextY,tmpdir);
	}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		D[L]++;
		D[R]++;
		e[L].push_back(R);
		e[R].push_back(L);
		if (D[L]>4 || D[R]>4)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	len = 1LL<<40;
	dfs(-1,1,0,0,-1);
	for (int i=1;i<=N;i++)printf("%I64d %I64d\n",XX[i],YY[i]);
}
