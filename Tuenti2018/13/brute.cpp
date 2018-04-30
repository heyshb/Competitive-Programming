#include <bits/stdc++.h>

using namespace std;

int f[10][10][10];

int xj(int L1,int R1,int L2,int R2)
{
	if (R1 < L2 || R2 < L1) return false;
	return true;
}
int F[10][3][3][3];

int vv[10];
int gt(int x)
{
	for (int i=0;i<199;i++)
	if (vv[i]==x)return i;
	assert(false);
}

int main()
{
	f[0][0][0] = 1;
	for (int i=1;i<10;i++)
		for (int j=1;j<10;j++)
			for (int k=1;k<10;k++)
			{
				f[i][j][k] = 0;
				for (int i1=0;i1<i;i1++)
					for (int i2=0;i2<j;i2++)
						for (int i3=0;i3<k;i3++)
						if (xj(i1+1,i,i2+1,j) && xj(i2+1,j,i3+1,k))
							f[i][j][k] += f[i1][i2][i3];
				int mx = max(max(i,j),k);
				int V = f[i][j][k];
				vv[0] = i;vv[1] = j;vv[2] = k; 	
				sort(vv,vv+3);
				unique(vv,vv+3);
				F[mx][gt(i)][gt(j)][gt(k)]+=V;
			}
	//for (int i=1;i<10;i++)printf("%d %d\n",i,f[i][i][i]);
	for (int N=1;N<=5;N++)
	{
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
				{
					if (F[N][i][j][k]) printf("F[%d][%d][%d][%d] = %lld\n",N,i,j,k,F[N][i][j][k]);
				}
	}
}
