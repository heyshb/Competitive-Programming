#include <bits/stdc++.h>

using namespace std;

double f[110][210];

double E(int M,int N)
{
	int len = M-N+1;
	memset(f,0,sizeof(f));
	f[0][0] = 1;
	for (int i=1;i<=100;i++)
		for (int j=0;j<=2*M+12;j++)
		{
			int real = j-(M+6);
			for (int k =) 
		}
}

double S(int K)
{
	double res = 0;
	for (int M=2;M<=K;M++)
		for (int N=1;N<M;N++)
		res+=E(M,N);
	return res;
}

int main()
{
	printf("%.4lf\n",E(60,30));
}
