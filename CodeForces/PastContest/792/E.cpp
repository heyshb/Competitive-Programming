#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
LL A[510];
vector<LL>d;
int main()
{
	scanf("%d",&N);
	LL MI = 2e9;
	for (int i=1;i<=N;i++)
	{
		scanf("%I64d",&A[i]);
		MI = min(MI,A[i]);
	}
	LL B = LL(sqrt(MI + 1) + 1);
	for (LL i=1;i<=B;i++)
		if (MI/i >= MI%i) d.push_back(i);
	for (LL i=1;i<=B;i++)
	{
		d.push_back(MI/i);
		if (MI%i == 0)
			d.push_back(MI/i-1);
	}
	sort(d.begin(),d.end()); 
	//for (int i=d.size()-1;i>=d.size()-10;i--)printf("%I64d\n",d[i]);
	for (int i=d.size()-1;i>=0;i--)
	{
		LL x = d[i];
		LL s = 0;
		bool flag = true;
		for (int j=1;j<=N;j++)
		if (A[j]/x < A[j]%x)
		{
			flag = false;
			break;
		}
		if (!flag) continue;
		for (int j=1;j<=N;j++) 
		{
			if (A[j]%(x+1)==0)
				s += A[j]/(x+1);
			else
				s += A[j]/(x+1) + 1;
		}
		//printf("%I64d ",x);
		printf("%I64d\n",s);
		return 0;
	}
}
