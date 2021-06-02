#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if (a<=b+1 && a>=b-1 && (a>0 || b>0)) 
		puts("YES");
	else
		puts("NO"); 
}
