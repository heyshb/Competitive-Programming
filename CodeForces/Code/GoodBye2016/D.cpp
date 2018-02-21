#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,t[110];
char vis[310][310][31][5];
/*
7 0 1
6   2
5 4 3
*/
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

struct state
{
	int x,y,num,step,dir;
};

bool get(int x,int y,int num,int step,int dir)
{
	return vis[x][y][num][step] & (1<<dir);
}

void st(int x,int y,int num,int step,int dir)
{
	vis[x][y][num][step] |= (1<<dir);
}
queue<state> q;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&t[i]);
	memset(vis,false,sizeof(vis));
	st(155,155,1,0,0);
	q.push((state){155,155,1,0,0});
	int nx,ny,nnum,nstep,ndir;
	while(!q.empty())
	{
		state now = q.front();
		//printf("NOW at %d %d %d %d %d\n",now.x,now.y,now.num,now.step,now.dir);
		//system("pause");
		q.pop();
		state next;
		if (now.step == t[now.num]-1)
		{
			if (now.num == N) continue;
			
			ndir = (now.dir+7)%8;
			nx = now.x + dx[ndir];
			ny = now.y + dy[ndir];
			nnum = now.num + 1;
			nstep = 0;
			//printf("%d %d %d %d %d\n",nx,ny,nnum,nstep,ndir);
			if (!get(nx,ny,nnum,nstep,ndir))
			{
				st(nx,ny,nnum,nstep,ndir);
				q.push((state){nx,ny,nnum,nstep,ndir});
			}
			
			ndir = (now.dir+1)%8;
			nx = now.x + dx[ndir];
			ny = now.y + dy[ndir];
			nnum = now.num + 1;
			nstep = 0;
			if (!get(nx,ny,nnum,nstep,ndir))
			{
				st(nx,ny,nnum,nstep,ndir);
				q.push((state){nx,ny,nnum,nstep,ndir});
			}
		}
		else
		{
			nx = now.x + dx[now.dir];
			ny = now.y + dy[now.dir];
			nnum = now.num;
			nstep = now.step + 1;
			ndir = now.dir;
			if (!get(nx,ny,nnum,nstep,ndir))
			{
				st(nx,ny,nnum,nstep,ndir);
				q.push((state){nx,ny,nnum,nstep,ndir});
			}
		}
	}
	int ans = 0;
	for (int i=1;i<310;i++)
		for (int j=1;j<310;j++)
		{
			bool expl = false;
			for (int k=1;k<=N;k++)
				for (int l=0;l<t[k];l++)
					for (int m=0;m<8;m++)
					if (get(i,j,k,l,m)) expl = true;
			if (expl) ans++;
		}
	printf("%d\n",ans);
}
