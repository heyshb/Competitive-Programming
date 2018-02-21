#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,M,Q;
LL A[100010],B[100010];
LL S[100010];
LL SA = 0;
set<LL>st;

LL calc()
{
	LL res = 1e18;
	LL vv = -SA;
	auto t = st.lower_bound(vv);
	if (t != st.end())
		res = min(res,(*t) - vv);
	if (t != st.begin())
		res = min(res,vv - (*(--t)));
	return res;
}

int main()
{
	scanf("%d%d%d",&N,&M,&Q);
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d",&A[i]);
		if (i&1)
			SA += A[i];
		else
			SA -= A[i];
	}
	for (int i=1;i<=M;i++)scanf("%I64d",&B[i]);
	for (int j=0;j<=M-N;j++)
	{
		S[j] = 0;
		if (j<=1)
		{
			for (int k=1;k<=N;k++)
			if (k&1)
				S[j] -= B[k+j];
			else
				S[j] += B[k+j];
		}
		else
		{
			S[j] = S[j-2];
			S[j] += B[j-1];
			S[j] -= B[j];
			if (j & 1)
			{
				S[j] -= B[j+N];
				S[j] += B[j+N-1];
			}
			else
			{
				S[j] += B[j+N];
				S[j] -= B[j+N-1];
			}
		}
		st.insert(S[j]);
	}
	printf("%I64d\n",calc());
	while(Q--)
	{
		int L,R;
		LL v;
		scanf("%d%d%I64d",&L,&R,&v);
		if ((L&1) == (R&1))
		{
			if (L&1)
				SA += v;
			else
				SA -= v;
		}
		printf("%I64d\n",calc());
	}
}
