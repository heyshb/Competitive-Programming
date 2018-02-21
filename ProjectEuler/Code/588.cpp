#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
int f[MAXN+10][4*MAXN+40];

int main()
{
	for (int i=0;i<=4;i++)f[1][i]=1; 
	for (int i=2;i<=MAXN;i++)
	{
		int tmp = 0;
		for (int j=0;j<=i*4;j++)
		{
			for (int k=j;k>=0&&k>=j-4;k--)
			{
				f[i][j]^=f[i-1][k];
			}
			tmp+=f[i][j];
			//printf("%d",f[i][j]);
		}
		printf("%d",tmp);
		puts("");
	} 
}
