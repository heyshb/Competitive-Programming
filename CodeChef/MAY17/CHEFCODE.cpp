#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N,N1,N2;
LL A[20],B[20],K;
vector<LL>mulA,mulB;

int main()
{
	scanf("%d%lld",&N,&K);
	N1 = N/2;
	N2 = N - N1;
	for (int i=0;i<N1;i++)scanf("%lld",&A[i]);
	for (int i=0;i<N2;i++)scanf("%lld",&B[i]);
	for (int i=0;i<(1<<N1);i++)
	{
		double res = 1;
		bool ok = true;
		for (int j=0;j<N1;j++)
		if (i & (1<<j))
		{
			res*=double(A[j]);
			if (res*0.5 > double(K))
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			LL res2 = 1;
			for (int j=0;j<N1;j++)
			if (i & (1<<j))
				res2 *= A[j];
			if (res2 <= K) 
				mulA.push_back(res2);
		}
	}
	
	for (int i=0;i<(1<<N2);i++)
	{
		double res = 1;
		bool ok = true;
		for (int j=0;j<N2;j++)
		if (i & (1<<j))
		{
			res*=double(B[j]);
			if (res*0.5 > double(K))
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			LL res2 = 1;
			for (int j=0;j<N2;j++)
			if (i & (1<<j))
				res2 *= B[j];
			if (res2 <= K)
			mulB.push_back(res2);
		}
	}
	
	sort(mulB.begin(),mulB.end());
	int ans = 0;
	for (auto t:mulA)
	{
		LL maxB = K/t;
		if (mulB[mulB.size()-1] <= maxB)
			ans += mulB.size();
		else if (mulB[0] <= maxB)
		{
			int L = 0, R = mulB.size()-1;
			while(L < R-1)
			{
				int mid = (L+R)>>1;
				if (mulB[mid] <= maxB)
					L = mid;
				else 
					R = mid;
			}
			ans += L+1;
		}
	}
	printf("%d\n",ans-1);
}
