#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int N;
	scanf("%d",&N);
	bool ok = true;
	int pos = 0;
	while(N--)
	{
		int len;
		char str[10];
		scanf("%d%s",&len,str);
		if (str[0]=='E')
		{
			if (pos == 0 || pos == 20000) ok =false;
		}
		if (str[0]=='W')
		{
			if (pos == 0 || pos == 20000) ok =false;
		}
		if (str[0]=='N')
		{
			if (pos == 0) ok = false;
			if (pos - len < 0) ok = false;
			pos -= len;
		}
		if (str[0]=='S')
		{
			if (pos == 20000) ok = false;
			if (pos + len > 20000) ok = false;
			pos += len;
		}
	}
	if (pos != 0) ok = false;
	puts(ok?"YES":"NO");
}
