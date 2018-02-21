#include <bits/stdc++.h>

using namespace std; 

int getr(int l,int r)
{
	int len = (r - l + 1);
	return l + rand() % len;
}

int N = 100000,Q = 100000;
const int MAXV = 1000000;

int main()
{
	srand(time(0));
	freopen("HILLJUMP.in","w",stdout);
	printf("%d %d\n",N,Q);
	for (int i=1;i<=N;i++)printf("%d ",getr(1,MAXV));puts("");
	for (int i=1;i<=Q;i++)
	{
		int type = getr(1,2);
		int L = getr(1,N), R = getr(1,N);
		if (L > R) swap(L,R);
		if (type == 1)
		{
			printf("%d %d %d\n",type,L,R);
		}
		else
		{
			printf("%d %d %d %d\n",type,L,R,getr(1,MAXV));
		}
	}
}
