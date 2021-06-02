#include <bits/stdc++.h>

using namespace std;

int sg[110][110][110];
bool vis[10];

int solve(int a,int b,int c)
{
	//printf("Solve %d %d %d\n",a,b,c);
	if (a<0 || b<0 || c<0) return 5;
	if (sg[a][b][c]!=-1) return sg[a][b][c];
	memset(vis,false,sizeof(vis));
	if (a==0 && c==0)
	{
		return 0;
	}
	int sg1,sg2;
	sg1 = solve(b,a-1,c);
	sg2 = solve(b,a,c-1);
	memset(vis,false,sizeof(vis));
	vis[sg1] = vis[sg2] = true;
	for (int i=0;i<=10;i++)if (!vis[i]) return sg[a][b][c] = i;
}

int main()
{
	memset(sg,-1,sizeof(sg));
	printf("%d\n",solve(1,0,0));
	for (int a=0;a<=3;a++)
		for (int b=0;b<=5;b++)
			for (int c=0;c<=6;c++)
			{
				printf("%d %d %d %d\n",a,b,c,solve(a,b,c));
				bool win;
				if (a>b) win = true;
				else if (a<b) win = false;
				else win = ((c&1));
				if ((solve(a,b,c)!=0) != (win)) 
				{
					printf("%d %d %d\n",a,b,c);
					printf("%d %d\n",solve(a,b,c),win);
					system("pause");
				}
			}
}
