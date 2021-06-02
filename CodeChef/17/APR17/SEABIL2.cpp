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
	if (x+dx*E>=0 && y+dy*E>=0)
	{
		a[x+dx*E][y+dy*E] = a[x][y];
		for (int i=0;i<E;i++)a[x+dx*i][y+dy*i] = 0;
	}
	ans.push_back((boom){x,y,dx,dy,E});
}
 
void print()
{
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)printf("%d %d %d %d %d\n",ans[i].x,ans[i].y,ans[i].dx,ans[i].dy,ans[i].E);
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
		for (int i=0;i<=N;i++)
			for (int j=0;j<=N;j++)a[i][j]=v[i][j];
		for (int i=0;i<=N;i++)
			for (int j=0;j<=N;j++)
			if (a[i][j] && Z[a[i][j]]>0)
			{
				int mi = min(i,j);
				ins(i,j,-1,-1,mi);
				int ti = i-mi, tj = j-mi;
				if (ti==0)
					ins(ti,tj,0,-1,tj);
				else
					ins(ti,tj,-1,0,ti);
				ins(0,0,-1,-1,4*N);
			}
		print();
	}
} 
