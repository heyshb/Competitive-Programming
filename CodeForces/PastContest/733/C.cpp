#include <bits/stdc++.h>

using namespace std;

int N,M,A[510],B[510];
int l[510],r[510];

int main()
{
	scanf("%d",&N)£»
	for (int i=1;i<=N;i++)scanf("%d",&A[i]);
	scanf("%d",&M);
	for (int i=1;i<=M;i++)scanf("%d",&B[i]);
	int now=1,tmp;
	for (int i=1;i<=M;i++)
	{
		l[i]=now;
		tmp=A[now];
		while(tmp<=B[i] && now<N)
		{
			tmp+=A[++now];
		} 
		if (tmp!=B[i]){puts("-1");return 0;}
	}
}
