#include <bits/stdc++.h>

bool check[26];
int sum[25];
void calc(string s)
{
	memset(check,false,sizeof(check));
	int SS = 0;
	for (int i=0;i<24;i++)
	if (!check[i])
	{
		SS++;
		int j = i;
		while(!check[j])
		{
			check[j] = true;
			j = s[j] - 'A';
		}
	}
	sum[SS]++;
}

typedef long long LL;
const int M = 0;

int main()
{
	int N;
	string s;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		cin<<s;
		calc(s);
	}
	for (int i=1;i<=24;i++) printf("%d %d")
}
