#include <bits/stdc++.h>

using namespace std;

int V;
// 0 1 2 3 4 5 6 7 8 9 A B C D E
int sum[16] = {1,0,0,0,1,0,1,0,2,1,1,2,0,1,0};
int main()
{
	int b; 
	scanf("%d",&V);
	int ans = 0;
	do
	{
		ans += sum[V%16];
		V/=16;
	}
	while(V);
	printf("%d\n",ans);
}
