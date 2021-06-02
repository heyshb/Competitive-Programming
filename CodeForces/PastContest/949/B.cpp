#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int A[10000];

int main()
{
	while(true)
	{
		int N;
		scanf("%d",&N);
		for (int i=1;i<=2*N;i++)A[i]=0;
		for (int i=1;i<=N;i++)A[2*i-1] = i;
		for (int i=1;i<N;i++)
		{
			for (int j=2*N;j>=1;j--)
			if (A[j])
			{
				printf("%3d ",N - A[j] + 1);
				for (int k=j;k>=1;k--)
				if (!A[k])
				{
					swap(A[k],A[j]);
					break;
				}
				break;	
			}	
		}		
		puts("");
	}
}
