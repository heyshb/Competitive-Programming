#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[100010],b[100010];
map<string,int>num;
char tmp[20];
int sum[100010];
bool inb[100010];
typedef long long LL;

int main()
{
	scanf("%d%d",&N,&M);
	int cnt = 0;
	for (int i=1;i<=N;i++)
	{
		scanf("%s",tmp);
		string s = string(tmp);
		if (num.find(s) == num.end())
			num[s] = ++cnt;
		a[i] = num[s];
	}
	int zerocnt = 0;
	for (int i=1;i<=M;i++)
	{
		scanf("%s",tmp);
		string s = string(tmp);
		if (num.find(s) == num.end())
			return 0*puts("0"); 
		b[i] = num[s];
		inb[b[i]] = true;
		zerocnt++;
	}
	//for (int i=1;i<=N;i++)printf("%d ",a[i]);puts("");
	
	int R;
	for (R=1;R<=N;R++)
	{
		if (inb[a[R]] && sum[a[R]]==0) zerocnt--;
		sum[a[R]]++;
		if (zerocnt==0) break;
	}
	LL ans = 0;
	for (int L=1;L<=N;L++)
	{
		//printf("%d %d\n",L,R);
		//if (L == 5) printf("%d\n",sum[a[1]]);
		ans += (N - R + 1);
		if (--sum[a[L]] == 0 && inb[a[L]])
		{
			//puts("fuck");
			while(R<=N)
			{
				R++;
				sum[a[R]]++;
				if (a[R] == a[L]) break;
			}
			if (R == N+1) break;
		} 
	}
	printf("%lld\n",ans);
} 
