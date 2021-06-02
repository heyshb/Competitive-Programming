#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL s[110][110];

int main()
{
	int N,M,X,Y;
	LL K;
	scanf("%d%d%I64d%d%d",&N,&M,&K,&X,&Y);
	LL MX,MN;
	MX = -K;
	MN = K;
	if (N==1)
	{
		LL LOOP = K/M;
		K%=M;
		if (K == 0) printf("%I64d %I64d %I64d\n",LOOP,LOOP,LOOP);
		else 
		{
			printf("%I64d %I64d %I64d\n",LOOP+1,LOOP,LOOP+(Y<=K));
		}
		return 0;
	}
	LL LOOP = K/((2*N-2)*M);
	K%=((2*N-2)*M);
	//printf("%I64d %I64d\n",LOOP,K);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		if (i==1 || i==N)
			s[i][j] = LOOP;
		else 
			s[i][j] = 2*LOOP;
			
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			if (K==0) break;
			K--;
			s[i][j]++;
		}
	for (int i=N-1;i>=1;i--)
		for (int j=1;j<=M;j++)
		{
			if (K==0) break;
			K--;
			s[i][j]++;
		}
		
	
		
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			if (s[i][j] > MX) MX = s[i][j];
			if (s[i][j] < MN) MN = s[i][j];
		}
	printf("%I64d %I64d %I64d\n",MX,MN,s[X][Y]);
	
}
