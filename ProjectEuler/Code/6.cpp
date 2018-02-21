#include <bits/stdc++.h>

using namespace std;

int main()
{
	int ans = 0;
	for (int i=1;i<=10;i++)
		for (int j=i+1;j<=10;j++)ans+=2*i*j;
	printf("%d\n",ans);
}
