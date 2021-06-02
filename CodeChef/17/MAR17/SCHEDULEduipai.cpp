#include <bits/stdc++.h>

using namespace std;

int T,N,K,A[1000010],B[1000010],M;
char s[1000010];
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
		int cnt1,cnt2;
		for (int i=0;i<N;i++)
		if (i&1)
		{
			if (A[i])
				cnt1++;
			else
				cnt2++;
		}
		else
		{
			if (!A[i])
				cnt1++;
			else
				cnt2++;
		}
		return cnt1<=K || cnt2<=K;
	}
	int cnt = 0;
	for (int i=0;i<M;i++)cnt+=calc(d[i],x);
	return cnt<=K;
}

int get1(int x)
{
	int res = 0;
	for (int i=0;i<N;i++)
	if (x&(1<<i)) res++;
	return res;
}

int getmax(int v)
{
	for (int i=0;i<N;i++)B[i] = (v&(1<<i))?A[i]:(A[i]^1);
	B[N] = -1;
	int cnt = 1,res=1;
	for (int i=0;i<N;i++)
	if (B[i]!=B[i+1])
	{
		res = max(res,cnt);
		cnt = 1;
	}
	else
		cnt++;
	
	return res;
		
}

int main()
{
	N = 12;
	for (int mask=0;mask<(1<<N);mask++)
	{
		for (K=0;K<=N;K++)
		{
			for (int i=0;i<N;i++)A[i] = (mask>>i)&1;
			d.clear();
			A[N] = -1;
			int cnt = 1;
			for (int i=0;i<N;i++)
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
			
			int ans = 10000000;
			for (int i=0;i<(1<<N);i++)
			{
				if (get1(i)>K) continue;
				ans = min(ans,getmax(i));
			}
			printf("%d\n",ans);
			if (ans!=R)
			{
				//printf("%d %d\n",)
				system("pause");
			}
		}	
	}
}
