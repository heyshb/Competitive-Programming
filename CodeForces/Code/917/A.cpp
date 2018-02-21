#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[10010];
int s1[10010],s2[10010];
int N;

bool check(int L,int R)
{
	int len = R - L + 1;
	if (s1[R] - s1[L-1] > len / 2 || s2[R] - s2[L-1] > len / 2) return false;
	
	return true; 
}

int main()
{
	scanf("%s",s+1);
	N = strlen(s+1);
	for (int i=1;i<=N;i++)
	{
		s1[i] = s1[i-1] + (s[i] == ')');
		s2[i] = s2[i-1] + (s[i] == '(');
	}
	int ans = 0;
	for (int i=1;i<=N;i++)
		for (int j=i+1;j<=N;j+=2)
		{
			ans += check(i,j);
		}
	printf("%d\n",ans);
} 
