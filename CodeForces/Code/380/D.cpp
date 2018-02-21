#include <bits/stdc++.h>
#define INF 800000000
using namespace std;

int f[4010][4010][2];
bool ok[4010][4010][2]; 
int a[4010],s[4010];

int main()
{
	int N;
	scanf("%d",&N);
	s[0]=0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	memset(ok,false,sizeof(ok));
	ok[1][1][0]=ok[2][2][0]=true;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=i;j++)
			for (int k=0;k<=1;k++)
			{
				if (ok[i-j][j][k^1] || ok[i-j][j-1][k^1])
				{
					ok[i][j][k] = true;
				}
			}
}
