
#include <bits/stdc++.h>

time_t t;

int main()
{
	int x = 0;
	t = clock();
	while(true)
	{
		x++;
		if (clock() != t) break;
	}
	printf("%d\n",x);
}
