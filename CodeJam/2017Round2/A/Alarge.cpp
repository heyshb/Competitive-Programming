#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,P;
int sum[4];

int a[110][110];

bool S(int aa,int bb,int cc,int dd)
{
	return (bb + cc*2 + dd*3)%P == 0;
}

void solve2()
{
	memset(a,0,sizeof(a));
	for (int i=0;i<=sum[0];i++)
		for (int j=0;j<=sum[1];j++)
		{
			if (i > 0)
				a[i][j] = max(a[i][j], a[i-1][j] + S(i-1,j,0,0));
			if (j > 0)
				a[i][j] = max(a[i][j], a[i][j-1] + S(i,j-1,0,0));
		}
	cout<<a[sum[0]][sum[1]]<<endl;
}

int b[110][110][110];
void solve3()
{
	memset(b,0,sizeof(b));
	for (int i=0;i<=sum[0];i++)
		for (int j=0;j<=sum[1];j++)
			for (int k=0;k<=sum[2];k++)
			{
				if (i > 0)
					b[i][j][k] = max(b[i][j][k], b[i-1][j][k] + S(i-1,j,k,0));
				if (j > 0)
					b[i][j][k] = max(b[i][j][k], b[i][j-1][k] + S(i,j-1,k,0));
				if (k > 0)
					b[i][j][k] = max(b[i][j][k], b[i][j][k-1] + S(i,j,k-1,0));
				
			}
	cout<<b[sum[0]][sum[1]][sum[2]]<<endl;
}

int c[101][101][101][101];
void solve4()
{
	memset(c,0,sizeof(c));
	for (int i=0;i<=sum[0];i++)
		for (int j=0;j<=sum[1];j++)
			for (int k=0;k<=sum[2];k++)
				for (int l=0;l<=sum[3];l++)
				{
					if (i > 0)
						c[i][j][k][l] = max(c[i][j][k][l], c[i-1][j][k][l] + S(i-1,j,k,l));
					if (j > 0)
						c[i][j][k][l] = max(c[i][j][k][l], c[i][j-1][k][l] + S(i,j-1,k,l));
					if (k > 0)
						c[i][j][k][l] = max(c[i][j][k][l], c[i][j][k-1][l] + S(i,j,k-1,l));
					if (l > 0)
						c[i][j][k][l] = max(c[i][j][k][l], c[i][j][k][l-1] + S(i,j,k,l-1));
				}
	cout<<c[sum[0]][sum[1]][sum[2]][sum[3]]<<endl;
}

int main()
{
	freopen("Alarge.in","r",stdin);
	freopen("Alarge.out","w",stdout);
	int T,N;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d%d",&N,&P);
		int tmp;
		memset(sum,0,sizeof(sum));
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&tmp);
			sum[tmp%P]++;
		}
		printf("Case #%d: ",_);
		if (P==2)
			solve2();
		else if (P==3)
			solve3();
		else
			solve4();
	}
}
