#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,a[100010],s,f;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	scanf("%d%d",&s,&f);	
	int len = f - s;
	int sum = 0;
	for (int i=1;i<=len;i++) sum += a[i];
	int mx = -1,ans;
	for (int i=1;i<=N;i++)
	{
		if (sum == mx)
		{
			int tmp = s - i + 1;
			if (tmp <= 0) tmp += N;
			if (tmp > N) tmp -= N;
			ans = min(ans, tmp);
		}
		if (sum >= mx)
		{
			//printf("%d %d\n",i,sum);
			mx = sum;
			ans = s - i + 1;
			//printf("%d\n",ans); 
			if (ans <= 0) ans += N;
			if (ans > N) ans -= N;
		}
		sum -= a[i];
		len++;
		if (len > N) len = 1;
		sum += a[len];
	}
	printf("%d\n",ans);
} 
