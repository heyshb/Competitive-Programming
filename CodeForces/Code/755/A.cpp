#include <bits/stdc++.h>

using namespace std;

bool isprime(int x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (x%i==0) return false;
	}
	return true;
}

int main()
{
	int N;
	scanf("%d",&N);
	for (int i=1;i<=1000;i++)
	{
		if (!isprime(i*N+1))
		{
			printf("%d\n",i);
			return 0;
		}
	}
}
