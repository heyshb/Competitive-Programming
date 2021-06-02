#include <bits/stdc++.h>

using namespace std;

int N,a[100010];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	int ans = 0; 
	for (int i=1;i<=N;i++)
		if (a[i]<=i && a[a[i]]==i) ans++;
	printf("%d\n",ans);
}
