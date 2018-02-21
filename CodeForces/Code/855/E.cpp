#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int b;
LL L,R;
int digit[100],len;
int cnt[100];
int t[100][100];
LL C[100][100]
LL ans[100][100];
LL C(int N,int M)
{
	
}

LL calc(int pos,bool up,int mask,bool leadzero)
{
	if (!up)
	{
		int cnt = 0;
		for (int i=0;i<b;i++) if (mask & (1<<i)) cnt++;
		if (len-pos+1 < cnt) return 0;
		return ans[len-pos+1][cnt];
	}
	int upbound = (up?digit[pos]:b-1);
	LL res = 0;
	for (int i=0;i<=upbound;i++)
	{
		int nmask = (leadzero && i==0)?0:(mask^(1<<i)); 
		res += calc(pos+1,up&&(i==upbound),nmaxk,leadezero&&(i==0));
	} 
	return res;
}

LL solve(LL x)
{
	len = 0;
	do
	{
		digit[++len] = x % b;
		x /= b;
	}while(x);
	reverse(digit+1,digit+len+1);
	return calc(1,1,0);
}

void getans()
{
	for (int i=1;i<=64;i++)
		for (int j=1;j<=i;j++)
		{
			ans[i][j] = 0;
			
		}
}

int main()
{
	for (int i=1;i<=70;i++)
	{
		int tmp = i;
		for (int j=2;j<=70;j++)
		{
			while(tmp % j == 0)
			{
				tmp /= j;
				t[i][j]++;
			}
			if (tmp == 1) break;
		}
	}
	for (int i=1;i<=100;i++)
		for (int j=0;j<=i;j++)
		{
			C[i][j] = 1;
			memset(cnt,0,sizeof(cnt));
			for (int k=1;k<=j;k++) 
			cnt[] -= 
		}
	getans();
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%lld%lld",&b,&L,&R);
		printf("%lld\n",solve(R) - solve(L-1));
	}
}
