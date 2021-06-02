#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
vector<int>v;
int cnt;
vector<int>ans[100010];
int swp = 0;

void print(int L,int R,int num)
{
	v.clear();
	if (num % 2 == 0)
	{
		for (int i=R;i>=L;i-=2)v.push_back(i);
		for (int i=R-1;i>=L;i-=2)v.push_back(i);
	}
	else
	{
		for (int i=R-1;i>=L;i-=2)v.push_back(i);
		for (int i=R;i>=L;i-=2)v.push_back(i);
	}
	if (swp)
		for (int i=1;i<=M;i++)ans[i].push_back(v[i-1]);
	else
		for (int i=0;i<M;i++)ans[num].push_back(v[i]);
}

bool inr(int x,int y)
{
	return x>0 && x<=N && y>=0 && y<M;
}

bool ner(int x,int y)
{
	if (x < y) swap(x,y);
	if (x - y == max(N,M)) return true;
	if (x - y == 1 && y%max(N,M) != 0) return true;
	return false;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int fuck(int V)
{
	int x,y;
	x = (V - 1) / N + 1;
	y = (V - 1) % N + 1;
	return (y - 1) * M + x;
}

int main()
{
	scanf("%d%d",&N,&M);
	if (N == 1 && M == 1)
	{
		puts("YES");
		puts("1");
		return 0;
	}
	if (N == 3 && M == 3)
	{
		puts("YES");
		puts("8 3 4");
		puts("1 5 9");
		puts("6 7 2");
		return 0;
	}
	if (N <= 3 && M <= 3)
	{
		puts("NO");
		return 0;
	}
	
		for (int i=1;i<=N;i++)ans[i].clear();
		if (N > M) 
		{
			swp = true;
			swap(N,M);
		}
		puts("YES");
		if (M == 4)
		{
			for (int num=2;num<=N;num+=2)
			{
				int st = (num-2)*M;
				v.clear();
				v.push_back(st+5);
				v.push_back(st+4);
				v.push_back(st+7);
				v.push_back(st+2);
				if (swp)
					for (int i=1;i<=M;i++)ans[i].push_back(v[i-1]);
				else
					for (int i=0;i<M;i++)ans[num-1].push_back(v[i]);
					
				v.clear();
				v.push_back(st+3);
				v.push_back(st+6);
				v.push_back(st+1);
				v.push_back(st+8);
				if (swp)
					for (int i=1;i<=M;i++)ans[i].push_back(v[i-1]);
				else
					for (int i=0;i<M;i++)ans[num].push_back(v[i]);
			}
			if (N & 1)
			{
				v.clear();
				v.push_back(N*M-1);
				v.push_back(N*M-3);
				v.push_back(N*M);
				v.push_back(N*M-2);
				if (swp)
					for (int i=1;i<=M;i++)ans[i].push_back(v[i-1]);
				else
					for (int i=0;i<M;i++)ans[N].push_back(v[i]);
			}
		}
		else
		for (int i=1;i<=N;i++)
		{
			print((i-1)*M+1,i*M,i);
		}
		if (swp) swap(N,M);
		for (int i=1;i<=N;i++)
			for (int j=0;j<M;j++)printf("%d%c",swp?fuck(ans[i][j]):ans[i][j]," \n"[j==M-1]);
	
} 
