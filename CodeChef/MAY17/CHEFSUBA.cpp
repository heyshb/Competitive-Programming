#include <bits/stdc++.h>

using namespace std;

int N,K,P;
int A[200010];
char s[100010];
int sum[200010];
multiset<int>st;

int main()
{
	scanf("%d%d%d",&N,&K,&P);
	for (int i=N;i>=1;i--)scanf("%d",&A[i]);
	for (int i=N+1;i<=200000;i++)A[i] = A[i-N];
	for (int i=1;i<=200000;i++)sum[i] = sum[i-1] + A[i];
	scanf("%s",s);
	if (K >= N)
	{
		for (int i=0;i<P;i++)
			if (s[i] == '?')
				printf("%d\n",sum[N]);
		return 0;	
	}
	int L = 0, R = N;
	for (int i=K;i<=N;i++)
		st.insert(sum[i] - sum[i-K]);
	for (int i=0;i<P;i++)
	{
		if (s[i] == '?')
		{
			printf("%d\n",*prev(st.end()));
		}
		else
		{
			R++;
		//	printf("INS %d\n",sum[R] - sum[R-K]);
			
			st.insert(sum[R] - sum[R-K]);
			//printf("DEL %d\n",sum[L+K] - sum[L]);
			st.erase(st.find(sum[L+K] - sum[L]));
			//puts("done");
			L++;
		}
	}
}
