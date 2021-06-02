#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct company
{
	int num,offer;
	LL salary;
	int hire;
}c[1010];

bool cmp(company a,company b){return a.salary > b.salary;}

int N,M;
LL minSalary[1010];
LL offeredSalary[1010],maxJobOffers[1010];
int qual[1010][1010];
char s[1010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);	
		for (int i=1;i<=N;i++)scanf("%lld",&minSalary[i]);
		for (int i=1;i<=M;i++)
		{
			scanf("%lld%d",&c[i].salary,&c[i].offer);
			c[i].num = i;
			c[i].hire = 0;
		}
		for (int i=1;i<=N;i++)
		{
			scanf("%s",s+1);
			for (int j=1;j<=M;j++)
				qual[i][j] = (s[j] == '1');
		}
		sort(c+1,c+M+1,cmp);
		LL sumsalary = 0;
		int jobcnt = 0;
		int nohire = 0;
		for (int i=1;i<=N;i++)
		{
			bool find = false;
			for (int j=1;j<=M;j++)
			{
				if (!c[j].offer || c[j].salary<minSalary[i] || !qual[i][c[j].num]) continue;
				find = true;
				jobcnt++;
				sumsalary += c[j].salary;
				c[j].hire++;
				c[j].offer--;
				//printf("candidate %d chooses company %d\n",i,c[j].num);
				break;
			}
		}
		for (int i=1;i<=M;i++)
		if (!c[i].hire) nohire++;
		printf("%d %lld %d\n",jobcnt,sumsalary,nohire);
	}
}
