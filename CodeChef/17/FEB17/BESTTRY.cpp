#include <bits/stdc++.h>

using namespace std;

#define MAXN 20
int N;
int a[MAXN];
int b[MAXN];
bool c[MAXN];

bool check()
{
	bool has0 = false;
	for (int i=1;i<=N;i++)
	{
		if (b[i]&has0) return false;
		if (!b[i]) has0 = true;
	}
	return true;
}

int get()
{
	int cnt = 0;
	for (int i=1;i<=N;i++)b[i]=a[i];
	while(!check())
	{
		//for (int i=1;i<=N;i++)printf("%d",b[i]);puts("");
		memset(c,false,sizeof(c));
		cnt++;
		for (int i=1;i<N;i++)
		if (b[i]==0 && b[i+1]==1) c[i] = true;
		for (int i=1;i<N;i++)
		if (c[i]) swap(b[i],b[i+1]);
	}
	return cnt;
}

void make(int A,int B,int C,int D)
{
	int now = 0;
	for (int i=1;i<=A;i++)a[++now]=0;
	for (int i=1;i<=B;i++)a[++now]=1;
	for (int i=1;i<=C;i++)a[++now]=0;
	for (int i=1;i<=D;i++)a[++now]=1;
}

void make3(int A,int B,int C,int D,int E,int F)
{
	int now = 0;
	for (int i=1;i<=A;i++)a[++now]=0;
	for (int i=1;i<=B;i++)a[++now]=1;
	for (int i=1;i<=C;i++)a[++now]=0;
	for (int i=1;i<=D;i++)a[++now]=1;
	for (int i=1;i<=E;i++)a[++now]=0;
	for (int i=1;i<=F;i++)a[++now]=1;
}

int main()
{
	//make(1,1,1,1);
	//N = 4;
	//printf("%d\n",get());
	
	
	
	for (int A=1;A<=4;A++)
		for (int B=1;B<=4;B++)
			for (int C=1;C<=4;C++)
				for (int D=1;D<=4;D++)
				{
					N = A+B+C+D;
					make(A,B,C,D);
					printf("%d %d %d %d %d\n",A,B,C,D,get()-(N-(B+D)));
				}
	
	
}
