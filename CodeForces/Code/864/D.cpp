#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,A[200010];
int cnt[200010];
int fst[200010];
bool isf[200010];
set<int>st;

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]),cnt[A[i]]++;
		if (!fst[A[i]]) 
		{
			fst[A[i]] = i;
			isf[i] = true;
		}
	}
	for (int i=1;i<=N;i++)
	if (cnt[A[i]] > 1)
		st.insert(i);
	int ans = 0;
	for (int i=1;i<=N;i++)
	if (cnt[i] == 0)
	{
		ans++;
		while(true)
		{
			int pos = *st.begin();
			//printf("!!%d %d\n",A[pos],cnt[A[pos]]);
			if ((i > A[pos] && isf[pos]) || cnt[A[pos]] == 1)
			{
				st.erase(st.begin());
				continue;
			}
			cnt[A[pos]]--;
			A[pos] = i;
			
			st.erase(st.begin());
			break;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=N;i++)printf("%d%c",A[i]," \n"[i==N]);
}
