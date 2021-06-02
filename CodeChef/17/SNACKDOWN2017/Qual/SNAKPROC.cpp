#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T,N;
	char s[1010];
	scanf("%d",&T);
	while(T--)
	{
		int pos = 0;
		bool valid = true;
		scanf("%d",&N);
		scanf("%s",s);
		for (int i=0;i<N;i++)
		if (s[i] != '.')
		{
			if (s[i] == 'H')
			{
				if (pos != 0)
					valid = false;
				pos = 1;
			}
			else
			{
				if (pos != 1)
					valid = false;
				pos = 0;
			}
		}
		if (pos) valid = false;
		puts(valid?"Valid":"Invalid");
	}
}
