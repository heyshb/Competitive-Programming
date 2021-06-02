#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int cnt[110];
int N;

int main()
{
	scanf("%d",&N);
	int dif = 0;
	for (int i=1;i<=N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if (!cnt[tmp]) dif++;
		cnt[tmp]++;
	}
	if (dif != 2) return 0*puts("NO");
	int v = -1;
	for (int i=1;i<=100;i++)
	if (cnt[i])
	{
		if (v!=-1 && v!=cnt[i]) return 0*puts("NO");
		v = cnt[i];
	}
	puts("YES");
	vector<int>ans;
	for (int i=1;i<=100;i++)if (cnt[i]) ans.push_back(i);
	printf("%d %d\n",ans[0],ans[1]);
}
