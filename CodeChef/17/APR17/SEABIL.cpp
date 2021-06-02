#include <bits/stdc++.h>
 
using namespace std;
 
int N,M;
int X[110],Y[110],Z[110];
int v[110][110],a[110][110];
int s[110][110];
 
struct boom
{
	int x,y,dx,dy,E;
};
vector<boom>ans;
 
void ins(int x,int y,int dx,int dy,int E)
{
	//printf("FUCK %d %d %d %d %d\n",x,y,dx,dy,E);
	if (!a[x][y]) return;
	if (!E) return;
	a[x+dx*E][y+dy*E] = a[x][y];
	for (int i=0;i<E;i++)a[x+dx*i][y+dy*i] = 0;
	for (int i=0;i<=N;i++)
	{
		//for (int j=0;j<=N;j++)printf("%d",a[i][j]);
		//puts("");
	}
	ans.push_back((boom){x,y,dx,dy,E});
}
 
void print()
{
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)printf("%d %d %d %d %d\n",ans[i].x,ans[i].y,ans[i].dx,ans[i].dy,ans[i].E);
}
 
void copy()
{
	for (int i=0;i<=N;i++)
		for (int j=0;j<=N;j++)
		a[i][j] = v[i][j];
}
 
void goleft(int x,int y)
{
	ins(x,y,0,-1,y);
}
 
void goright(int x,int y)
{
	ins(x,y,0,1,N-y);
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		memset(v,0,sizeof(v));
		memset(s,0,sizeof(s));
		for (int i=1;i<=M;i++)
		{
			scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
			v[X[i]][Y[i]] = i;
		}
		
		ans.clear();
		int sum = 0;
		vector<int>now;
		copy();
		
		
		
		for (int i=0;i<=0;i++)
		{
			now.clear();
			for (int j=0;j<=N;j++)
				if (a[i][j])
					now.push_back(j);
			if (!now.size()) continue;
			//for(auto t:now) printf("%d ",t);puts("");
			int S = 0, L = -1, R = -1, maxS = 0, d = 0;
			bool find = false;
			for (int j=0;j<now.size();j++)
			{
				S+=Z[a[i][now[j]]];
				//system("pause");
				if (S > maxS)
				{
					maxS = S;
					L = j;
				}
				if (S - maxS < d) 
				{
					d = S - maxS;
					R = j;
					find = true;
				}
			}
			if (!find)
			{
				goleft(i,now[now.size()-1]);
				continue;
			}
			//printf("%d %d\n",L,R);
			if (L>=0)
				goleft(i,now[L]);
			if (R+1<now.size()) 
				goright(i,now[R+1]);
		}
		
		
		
		for (int i=N;i>=0;i--)
		if (a[i][0])
		{
			ins(i,0,-1,0,i);
			ins(0,0,-1,-1,1);
			break;
		}
		for (int i=N;i>=0;i--)
		if (a[i][N])
		{
			ins(i,N,-1,0,i);
			ins(0,N,-1,1,1);
			break;
		}
		print();
	}
} 
