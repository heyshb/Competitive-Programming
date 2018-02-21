#include <bits/stdc++.h>

using namespace std;

int sg[1<<16],N,M;
int v[6][6],s[6][6];
int tmpv[6][6],tr[100010],num[100010];
bool vis[100010];
vector<int>nex;

int lowbit(int x){return x&-x;}
void modify(int x,int y){while(x<=N){tr[x]^=y;x+=lowbit(x);}}
int get(int x){int res = 0;while(x){res^=tr[x];x-=lowbit(x);}return res;}

int getsum(int xx1,int yy1,int xx2,int yy2)
{
	return s[xx2][yy2]-s[xx2][yy1-1]-s[xx1-1][yy2]+s[xx1-1][yy1-1];
}

int getnum()
{
	char str[5][5];
	for (int i=1;i<=4;i++)scanf("%s",str[i]+1);
	int res = 0;
	for (int x=4;x>=1;x--)
		for (int y=4;y>=1;y--)
		{
			res<<=1;
			res+=str[x][y]-'0';
		}
	//printf("%d\n",res);
	return res;
}

int main()
{
	sg[0] = 0;
	memset(vis,false,sizeof(vis));
	for (int i=1;i<(1<<16);i++)
	//for (int i=1;i<=32;i++)
	{
		memset(s,0,sizeof(s));
		
		for (int j=0;j<16;j++)
			v[j/4+1][j%4+1] = ((i>>j) & 1);
		
		for (int j=1;j<=4;j++)
			for (int k=1;k<=4;k++)
				s[j][k] = s[j-1][k] + s[j][k-1] - s[j-1][k-1] + v[j][k];
		
		nex.clear();
		
		for (int j=1;j<=4;j++)
			for (int k=1;k<=4;k++)
				for (int l=j;l<=4;l++)
					for (int m=k;m<=4;m++)
					{
						if (getsum(j,k,l,m) != (l-j+1)*(m-k+1)) continue;
						int res = 0;
						for (int x=4;x>=1;x--)
							for (int y=4;y>=1;y--)
							{
								res<<=1;
								if (!(x>=j && y>=k && x<=l && y<=m)) res+=v[x][y];
							}
						nex.push_back(res);
					}
		//printf("Calc %d\n",i);
		for (int j=0;j<nex.size();j++)vis[sg[nex[j]]] = true;//,printf("%d ",nex[j]);
		//puts("");
		for (int j=0;j<=1000000;j++)if (!vis[j])
		{
			sg[i] = j;
			break; 
		}
		for (int j=0;j<nex.size();j++)vis[sg[nex[j]]] = false;
	}
	//for (int i=0;i<=256;i++)printf("%d %d\n",i,sg[i]);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		memset(tr,0,sizeof(tr));
		for (int i=1;i<=N;i++)num[i] = getnum();//printf("%d\n",num[i]);
		for (int i=1;i<=N;i++)modify(i,sg[num[i]]);
		while(M--)
		{
			int type,L,R;
			scanf("%d",&type);
			if (type==1)
			{
				scanf("%d%d",&L,&R);
				puts(get(L-1)^get(R)?"Pishty":"Lotsy");
			}
			else
			{
				scanf("%d",&L);
				R = getnum();
				modify(L,sg[num[L]]);
				num[L] = R;
				modify(L,sg[R]);
			}
		}
	}
}
