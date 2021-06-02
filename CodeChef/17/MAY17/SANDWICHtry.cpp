#include <bits/stdc++.h>

using namespace std;

int main()
{
	for (int N=2;N<=6;N++)
	{
		for (int K=1;K<=N;K++)
		{
			//printf("%d %d:\n",N,K);
			printf("%d",(N+K-1)/K * K - N);
		}
		puts("");
	}
}
