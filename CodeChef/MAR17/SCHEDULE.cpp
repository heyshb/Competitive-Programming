#include <bits/stdc++.h>

using namespace std;

int T,N,K,A[2000010],B[2000010],M;
char s[2000010];
vector <int> d; 

int calc(int len,int x)
{
	if (len<=x) return 0;//          1 2 3 4 5 6 7 8 
	return len/(x+1);    //00100100  0 0 1 1 1 2 2 2   
} 

bool check(int x)
{
	if (!x) return false;
	if (x==1)
	{
		int cnt1 = 0,cnt2 = 0;
		for (int i=1;i<=N;i++)
		if ((i&1)^A[i])
			cnt1++;
		else
			cnt2++;
		return cnt1<=K || cnt2<=K;
	}
	int cnt = 0;
	for (int i=0;i<M;i++)cnt+=calc(d[i],x);
	return cnt<=K;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		scanf("%s",s+1);
		for (int i=1;i<=N;i++)A[i] = s[i]-'0';
		d.clear();
		A[N+1] = -1;
		int cnt = 1;
		for (int i=1;i<=N;i++)
		if (A[i]!=A[i+1])
		{
			d.push_back(cnt);
			cnt = 1;
		}
		else
			cnt++;
		
		M = d.size();
		//for (int i=0;i<M;i++)printf("%d ",d[i]);puts("");
		
		int L = 0, R = N;
		while(R>L+1)
		{
			int mid = (L+R)>>1;
			if (check(mid))
				R = mid;
			else
				L = mid;
		}
		printf("%d\n",R);
	}
}
