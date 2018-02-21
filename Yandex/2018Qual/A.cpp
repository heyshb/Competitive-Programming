#include <bits/stdc++.h>

using namespace std;

bool lucky[100];

int main()
{
	for (int i=1;i<=10;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		lucky[tmp] = true;
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int cnt = 0,tmp;
		for (int i=1;i<=6;i++)scanf("%d",&tmp),cnt += lucky[tmp];
		puts(cnt>=3?"Lucky":"Unlucky");
	}
}
