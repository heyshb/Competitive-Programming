#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int d = N-K-1;
	/*
	if (d==1)
	{
		puts("2");
		for (int i=2;i<=N;i++)
		printf("%d %d\n",1,i);
		return 0;
	}
	if (d==2)
	{
		puts("3");
		puts("1 2");
		puts("1 3");
		for (int i=4;i<=N;i++)printf("%d %d\n",2,i);
		return 0;
	}
	puts("4");
	for (int i=2;i<=d;i++)printf("%d %d\n",1,i);
	for (int i=1;i<=d-1;i++)printf("%d %d\n",i+1,i+d);
	for (int i=2*d;i<=N;i++)printf("%d %d\n",2,i);
	return 0;*/
	
	if (d%K == 0)
	{
		int len = d/K;
		printf("%d\n",2*len+2);
		int done = 1;
		for (int i=1;i<=K;i++)
		{
			int nowlen = len;
			//printf("!! %d %d\n",i,nowlen);
			for (int j=done+1;j<=done+nowlen;j++)
			if (j==done+1)
				printf("%d %d\n",1,j);
			else	
				printf("%d %d\n",j-1,j);
			done+=nowlen;
			printf("%d %d\n",done,d+1+i);
		}
	}
	else
	{
		//printf("D = %d K = %d\n",d,K);
		int len = d/K+1;
		if (d%K == 1)
			printf("%d\n",2*len+1);
		else	
			printf("%d\n",2*len+2);
		int done = 1;
		for (int i=1;i<=K;i++)
		{
			int nowlen = len-1;
			if (i<=d%K) nowlen++;
			//printf("!! %d %d\n",i,nowlen);
			int last = 1;
			for (int j=done+1;j<=done+nowlen;j++)
			{
				if (j==done+1)
					printf("%d %d\n",1,j);
				else	
					printf("%d %d\n",j-1,j);
				last = j;
			}
			done+=nowlen;
			printf("%d %d\n",last,N+1-i);
		}
	}
}
