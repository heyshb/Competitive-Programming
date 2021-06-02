#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("robot.in","w",stdout);
	int T = 2;
	printf("%d\n",T);
	int b[4] = {2,3,4,2};
	int s[4] = {2,5,9,11};
	int e[3] = {3,4,3};
	srand(time(0));
	while(T--)
	{
		int N = 11;
		int K = 2;
		int M = 10;
		printf("%d %d %d\n",N,M,K);
		for (int i=0;i<3;i++)
			for (int j=0;j<e[j];j++)
			printf("%d %d\n",s[i] - rand()%b[i],s[i+1] - rand()%b[i+1]);
	}
}
