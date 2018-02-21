#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL a[5010];
LL s[5010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%lld",a[i]),s[i] = s[i-1] + a[i];
	LL maxv = -1e15;
	int ans1,ans2,ans3;
	for (int d1=1;d1<=N;d1++) 
}
