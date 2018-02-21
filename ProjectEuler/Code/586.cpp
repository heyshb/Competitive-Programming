#include <bits/stdc++.h>

using namespace std;

int main()
{
	for (int N=1;N<=10000;N++)
	{
		//printf("Calc %d\n",N);
		int cnt = 0;
		for (int a=1;5*a*a<=N;a++)
		{
			for (int b=a;b<=N;b++)if (a*a+3*a*b+b*b==N)
			{
				cnt++;
				//printf("%d %d %d\n",a,b,N);
				break;
			}
		}
		if (cnt>3) printf("%d-------%d\n",N,cnt);
	}
}
