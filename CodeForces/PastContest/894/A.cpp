#include <bits/stdc++.h>

using namespace std;

char str[110];
int s[110];

int main()
{
	scanf("%s",str+1);
	int N = strlen(str+1);
	for (int i=1;i<=N;i++)s[i]=s[i-1]+(str[i]=='Q');
	int ans = 0;
	for (int i=1;i<=N;i++)
	if (str[i] == 'A')
		ans += s[i-1] * (s[N]-s[i]);
	printf("%d\n",ans);
}
