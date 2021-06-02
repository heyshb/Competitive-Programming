#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		bool ok = true;
		int N,tmp;
		scanf("%d",&N);
		if (N%2 == 0) ok = false;
		for (int i=1;i<=N/2+1;i++)
		{
			scanf("%d",&tmp);
			if (tmp != i) ok = false;
		}
		for (int i=N/2+2;i<=N;i++)
		{
			scanf("%d",&tmp);
			if (tmp != N+1-i) ok = false;	
		}
		puts(ok?"yes":"no");
	} 
}
