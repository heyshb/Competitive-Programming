#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N,A,B,C,D;

int main()
{
	cin>>N>>A>>B>>C>>D;
	if (A>B) swap(A,B);
	N--;
	LL delta = B-A;
	LL mind = 10000000000000LL;
	bool ok = false;
	for (int i=0;i<=N;i++)
	{
		int j = N-i;
		LL tmp = A + LL(i)*C - LL(j)*C;
		if (B <= tmp + LL(i)*(D-C) && B >= tmp - LL(j)*(D-C))
			ok = true;
	}
	puts(ok?"YES":"NO");
}
