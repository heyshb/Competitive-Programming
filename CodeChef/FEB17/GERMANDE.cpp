#include <bits/stdc++.h>

using namespace std;

int o1,o2,N;
int A[2000010],S[2000010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&o1,&o2);
		N = o1*o2;
		for (int i=1;i<=N;i++)scanf("%d",&A[i]);
		for (int i=N+1;i<=2*N;i++)A[i] = A[i-N];
		for (int i=1;i<=2*N;i++)S[i] = S[i-1] + A[i];
		bool canbe1 = false;
		for (int i=1;i<=o2;i++)
		{
			int now = i, cnt = 0, R;
			for (int j=1;j<=o1;j++)
			{
				R = now+o2-1;
				if (S[R]-S[now-1]>o2/2) cnt++;
				now+=o2;
				
			}
			if (cnt>o1/2)
			{
				canbe1 = true;
				break;
			}
		}
		printf("%d\n",canbe1);
	}
}
