#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K,a[100010];
int bl[256];
int ans[100010];

int main()
{
	for (int i=0;i<256;i++)bl[i] = -1;
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]);
	for (int i=1;i<=N;i++)
	{
		int v = a[i];
		if (bl[v] != -1) continue;
		int want = max(0, v - K + 1);
		bool conflict = false;
		for (int j=v-1;j>=want;j--)
		if (bl[j] != -1)
		{
			if (v - bl[j] < K)
			{
				bl[v] = bl[j];
			}
			else
			{
				bl[v] = j + 1;
			}
			conflict = true;
			break;
		}
		if (!conflict) bl[v] = want;
		for (int i=v-1;i>=bl[v];i--)
		bl[i] = bl[v];
	}
	for (int i=1;i<=N;i++)printf("%d%c",bl[a[i]]," \n"[i==N]);
}
