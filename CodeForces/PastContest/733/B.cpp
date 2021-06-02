#include <bits/stdc++.h>

using namespace std;

int N,l[100010],r[100010];
int L,R;

int main()
{
	scanf("%d",&N);
	L=R=0;
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		L+=l[i];
		R+=r[i];
	}
	int MAXV=abs(L-R),MAXPOS=0;
	for (int i=1;i<=N;i++)
	{
		L+=r[i]-l[i];
		R+=l[i]-r[i];
		if (abs(L-R)>MAXV)
		{
			MAXV=abs(L-R);
			MAXPOS=i;
		}
		L+=l[i]-r[i];
		R+=r[i]-l[i];
	}
	printf("%d\n",MAXPOS);
}
