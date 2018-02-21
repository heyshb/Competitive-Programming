#include <bits/stdc++.h>

using namespace std;

//(20!)! % (16^)
typedef long long LL;

LL up[20];
LL x;

void get_up()
{
	up[0] = 0;
	up[1] = 1;
	for (LL i=2;i<=16;i++)
	{
		int last = 1, res = i;
	
	}
}

LL sumfac(LL x,LL f)
{
	if (!x) return 0; 
	return x/f + sumfac(x/f,f); 
}

int main()
{
	x = 1;
	for (int i=1;i<=20;i++)	x = x * LL(i); 
	printf("%I64d\n",x);
}


//2432902008176640000
