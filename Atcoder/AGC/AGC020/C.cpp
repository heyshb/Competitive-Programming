#include <bits/stdc++.h>

using namespace std;

bitset<4000010>b;
int N,A[2010];

int main()
{
	b.reset();
	b.set(0);
	scanf("%d",&N);
	int S = 0;
	for (int i=1;i<=N;i++)scanf("%d",&A[i]),b |= (b << A[i]),S += A[i];
	for (int i=(S + 1) / 2; i <= S; i++)
		if (b[i]){
			printf("%d\n",i);
			break;
		}
}
