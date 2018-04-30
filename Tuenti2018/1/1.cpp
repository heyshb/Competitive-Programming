#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("1.out","w",stdout);
	int T;
	int _ = 0;
	scanf("%d",&T);
	while(T--)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		printf("Case #%d: %d\n",++_,(N-1)*(M-1));
	}
}
