#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int MOD;

struct matrix
{
	LL v[2][2];
	friend matrix operator * (matrix a,matrix b)
	{
		matrix c;
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
			{
				c.v[i][j] = 0;
				for (int k=0;k<2;k++)
				c.v[i][j] = (c.v[i][j]+a.v[i][k] * b.v[k][j])%MOD;
			}
		return c;
	}
	void print()
	{
		for (int i=0;i<2;i++)
		{
			for (int j=0;j<2;j++)printf("%lld ",v[i][j]);
			puts("");
		}
	}
}E;

matrix po(matrix a,LL x)
{
	matrix res = E;
	while(x)
	{
		if (x&1) res = res * a;
		a = a * a;
		x>>=1;
	}
	return res;
}

int main()
{
	int T;
	LL N,A;
	scanf("%d",&T);
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)E.v[i][j]=(i==j);
	while(T--)
	{
		scanf("%lld%lld%d",&A,&N,&MOD);
		LL ten = 1;
		while(ten<=A)ten=ten*10LL;
		matrix ori,mul;
		ori.v[0][0] = 0;
		ori.v[0][1] = A%MOD;
		ori.v[1][0] = ori.v[1][1] = 0;
		
		//ori.print();
		
		mul.v[0][0] = ten%MOD;
		mul.v[0][1] = 0;
		mul.v[1][0] = mul.v[1][1] = 1;
		
		//mul.print();
		
		ori = ori*po(mul,N);
		printf("%lld\n",ori.v[0][0]);
	}
}
