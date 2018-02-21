#include <bits/stdc++.h>

using namespace std;

int tri(bool a,bool b)
{
	return a&&b;
}

int cir(bool a,bool b)
{
	return a||b;
}

int v[4];

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",((a^b)&(c|d))^((b&c)|(a^d)) );
}
