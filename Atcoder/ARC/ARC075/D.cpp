#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int A,B,H[100010];

bool check(LL T)
{
	LL cnt = 0;
	for (int i=1;i<=N;i++)
	{
		if (T * LL(B) >= LL(H[i])) continue;
		cnt += ((H[i] - T*LL(B)) / LL(A-B)) + ((H[i] - T*LL(B)) % LL(A-B) != 0);
	}
	return cnt <= T;
}

int main()
{
	scanf("%d%d%d",&N,&A,&B);
	for (int i=1;i<=N;i++)scanf("%d",&H[i]);
	int L = 0, R = 1000000000;
	while(L != R-1)
	{
		int mid = (L+R)>>1;
		if (check(mid))
			R = mid;
		else
			L = mid;
	}
	printf("%d\n",R);
}
