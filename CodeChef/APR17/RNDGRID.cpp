#include <bits/stdc++.h>

using namespace std;

char s[10010];
int N,L;
int ans[1010][1010];
int v[10010];
char mp[1010][1010];
bool vis[1010][1010];
bitset<1010>mask[1010],space[1010],ori[1010],tmp,clr;
bool inrange(int x,int y){return x>0&&x<=N&&y>0&&y<=N;}

void print(int x)
{
	//cout<<space[x]<<endl;
	//cout << mask[x] << endl;
}
void printl()
{
	//puts("");
}

int main()
{
	//freopen("RNDGRID.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&L,&N);
		memset(vis,false,sizeof(vis));
		scanf("%s",s);
		//for (int i=1;i<=N;i++)
		//	for (int j=1;j<=N;j++)ans[i][j] = L;
		for (int i=0;i<=N+1;i++)
		{
			ori[i].reset();
			space[i].reset();
		}
		clr.reset();
		for (int i=1;i<=N;i++)clr.set(i);
		int dx = 0, dy = 0;
		for (int i=1;i<=N;i++)scanf("%s",mp[i]+1);
		for (int i=0;i<=N+1;i++)
			for (int j=0;j<=N+1;j++)
			if (!inrange(i,j) || mp[i][j] == '#')
			{
				ori[i].set(j);
				space[i].reset(j);
			}
			else
			{
				ori[i].reset(j);
				space[i].set(j);
			}
		//for (int i=0;i<=N+1;i++)cout<<ori[i]<<endl;cout<<endl;
		//puts("done");
		//for (int i=1;i<=N;i++)print(i);printl();
		int ans = 0;
		for (int i=0;i<L;i++)
		{
			if (s[i] == 'U') dx++;
			else if (s[i] == 'D') dx--;
			else if (s[i] == 'L') dy++;
			else dy--;
			//printf("%d %d\n",dx,dy);
			for (int j=1;j<=N;j++)
			{
				int xx = j - dx;
				if (xx < 0 || xx > N+1)
				{
					mask[j].reset();
					//continue;
				}
				else
				{
					//printf("WOW %d %d %d\n",j,xx,dy);
					if (dy > 0)
						mask[j] = ori[xx] << dy;
					else
						mask[j] = ori[xx] >> (-dy);
					mask[j] &= clr;
				}
				print(j);
			}
			int cnt = 0;
			for (int j=1;j<=N;j++)
			{
				cnt += (space[j] & mask[j]).count();
				space[j].flip();
				space[j] |= mask[j];
				space[j].flip();
				//print(j);
			}
			//printf("!! %d %d\n",cnt,i);
			if (cnt&1) ans^=i;
		}
		int cnt = 0;
		for (int i=1;i<=N;i++)cnt+=space[i].count();
		//printf("%d %d\n",cnt,L);
		if (cnt&1) ans^=L;
		printf("%d\n",ans);
	}
}
