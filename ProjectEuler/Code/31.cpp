#include <bits/stdc++.h>

using namespace std;

int v[9] = {0,1,2,5,10,20,50,100,200};
int f[9][210];

int main()
{
	f[0][0] = 1;
	for (int i=1;i<=8;i++)
	{
		for (int j=0;j<=200;j++)f[i][j] = f[i-1][j];
		for (int j=v[i];j<=200;j++)f[i][j] += f[i][j - v[i]];
	}
	printf("%d\n",f[8][200]);
}
