#include <bits/stdc++.h>

using namespace std;

int N;
char A[4010],B[4010];
int l[4010],r[4010];
int maxr[4010];
int ma[4010];
int ans;

void gao()
{
	for (int i=1;i<=N;i++)
	{
		int now = i;
		l[i] = 0;
		while(B[now] != '1')
		{
			now--;
			l[i]++;
			if (now == 0) now = N;
		}
		r[i] = 0;
		now = i;
		while(B[now] != '1')
		{
			now++;
			r[i]++;
			if (now == N+1) now = 1;
		}
	}
	for (int i=1;i<=N;i++)//A start point
	{
		//printf("solveing %d\n",i);
		int cnt = 0;
		for (int j=1;j<=N;j++)maxr[j] = 0;
		for (int j=1;j<=N;j++)
		{
			if (A[i+j-1] != B[j])
			{
				cnt++;
				//printf("update %d %d\n",l[j],r[j]-i+1);
				maxr[l[j]] = max(maxr[l[j]],r[j]);
			}
		}
		//for (int j=0;j<=N;j++)printf("%d ",maxr[l[j]]);puts("");
		ma[N+1] = 0;
		for (int j=N;j>=0;j--)
			ma[j] = max(ma[j+1],maxr[j]);
		int mini = 10000000;
		for (int j=0;j<=N;j++)
		{
			int delta = max(0,ma[j+1]-i+1);
			//printf("right %d delta = %d res = %d\n",j,delta,2*j + 2*delta + cnt);
			mini = min(mini,2*j + 2*delta + cnt + i - 1);
		}
		//printf("%d\n",mini);
		ans = min(ans,mini);
	}
}

int main()
{
	scanf("%s",A+1);
	scanf("%s",B+1);
	N = strlen(A+1);
	for (int i=N+1;i<=2*N;i++)A[i] = A[i-N];
	int cnt1 = 0,cnt2 = 0;
	for (int i=1;i<=N;i++)
	{
		cnt1 += (A[i] == '1');
		cnt2 += (B[i] == '1');
	}
	if (!cnt2)
	{
		if (cnt1) puts("-1");
		else puts("0");
		return 0;
	}
	ans = 10000000;
	gao();
	reverse(A+1,A+N+1);
	reverse(B+1,B+N+1);
	gao();
	printf("%d\n",ans);
}
