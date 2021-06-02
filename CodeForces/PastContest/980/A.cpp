#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char s[110010];

int main()
{
	scanf("%s",s);
	N = strlen(s);
	int v = 0;
	for (int i=0;i<N;i++) v += (s[i] == 'o');
	if (v == 0) return 0 * puts("YES");
	puts(N % v == 0?"YES":"NO");
}
