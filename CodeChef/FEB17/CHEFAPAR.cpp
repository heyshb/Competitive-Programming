#include <bits/stdc++.h>
using namespace std;

queue<int>q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,cnt1=0,cnt2=0;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
		{
			int v;
			scanf("%d",&v);
			if (v)
			{
				if (!q.empty())
				{
					q.pop();
					q.push(i);
					cnt1++;
				}
			}
			else
			{
				cnt2++;
				q.push(i);
			}
		}
		while(!q.empty())
		{
			q.pop();
			cnt1++;
		}
		printf("%d\n",cnt2*1000+cnt1*100);
	}
}
