#include <bits/stdc++.h>

using namespace std;



int T,N,A[100010];
struct seg
{
	int a,b;
};
vector<seg>s;
int T1[100010],T2[100010];

int main()
{
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)scanf("%d",&A[i]);
		s.clear();
		int now = 1, cnt1,cnt2;
		while(now<=N)
		{
			while(now<=N && A[now]) now++;
			if (now>N) break;
			cnt1 = 0;
			cnt2 = 0;
			while(now<=N && !A[now])
			{
				cnt1++;
				now++;
			}
			while(now<=N && A[now])
			{
				cnt2++;
				now++;
			}
			if (!cnt2) break;
			s.push_back((seg){cnt1,cnt2});
		}
		for (auto se:s)
		{
			printf("%d %d\n",se.a,se.b);
		}
		int S = 0;
		for (int i=0;i<s.size();i++)
		{
			S+=s[i].
		}
	}
	
}
