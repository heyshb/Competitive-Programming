#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	long long n,m;
	scanf("%d",&T);
	while(T--)
	{
		cin>>n>>m;
		if (n*m%2==1) puts("No");
		else puts("Yes"); 
	}
}
