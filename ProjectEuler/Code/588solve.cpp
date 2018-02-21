#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL v[10] = {1,5,5,7,5,17,7,19,5,25};
map<int,int> mp;
LL f[2][1000010];

LL get(LL x)
{
	memset(f,0,sizeof(f));
	int now = 1, last;
	for (int i=0;i<=4;i++)f[1][i] = 1;
	for (int i=2;i<=x;i++)
	{
		last=now;
		now^=1;
		for (int j=0;j<=4*i;j++)
		{
			f[now][j] = 0;
			for (int k=j;k>=0 && k>=j-4;k--)
				f[now][j]^=f[last][k];
		}
	}
	LL ans=0;
	for (int i=0;i<=4*x;i++)ans+=f[now][i];
	return ans;
}

LL solve(LL x)
{
	//printf("Solve %I64d\n",x);
	if (x<10) return v[int(x)]; 
	LL res = 1,tmp,nowv;
	int digit[70],len=0;
	while(x)
	{
		digit[++len] = x%2;
		x/=2;
	}
	//for (int i=len;i>0;i--)printf("%d",digit[i]);puts("");
	//system("pause");
	digit[0]=1;
	int L = len, R;
	while(L)
	{
		R = L;
		while((!(digit[R]==0 && digit[R-1]==0)) && R>0) R--;
		if (R==0) 
		{
			R = 1;
			while(digit[R]==0) R++;
			LL tmp = 0;
			for (int i=L;i>=R;i--)tmp = tmp*2+digit[i];
			res *= get(tmp);
			//printf("%d %d %I64d\n",L,R,tmp);
			break;
		}
		while(digit[R]==0)R++;
		LL tmp = 0;
		for (int i=L;i>=R;i--)tmp = tmp*2+digit[i];
		//printf("%d %d %I64d\n",L,R,tmp);
		res *= get(tmp);
		R--;
		while(digit[R]==0) R--;
		L = R;
	}
	return res;
}

int main()
{
	/*
	LL v = 1;
	for (int i=1;i<=18;i++)
	{
		v*=10LL;
		printf("%I64d\n",solve(v));
	}*/
	LL v = 1;
	LL ans = 0;
	for (int i=1;i<=18;i++)
	{
		v*=10LL;
		LL tmp = solve(v);
		printf("%I64d %I64d\n",v,tmp);
		ans+=tmp;
		//assert(solve(i)==get(i));
	}
	printf("%I64d\n",ans);
}
