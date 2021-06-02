#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int cnt1 = 0,cnt2 = 0;
		int N,P;
		scanf("%d%d",&N,&P);
		for (int i=1;i<=N;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			if (tmp <= P / 10) cnt2++;
			if (tmp >= P / 2) cnt1++;
		}
		puts(cnt1==1&&cnt2==2?"yes":"no");
	}	
	
}
