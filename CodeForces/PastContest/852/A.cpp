#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
char s[200010]; 
int split[200010];
int splitsmall;

int randsplit()
{
	for (int i=1;i<=N;i++)split[i] = rand()%2 + 1;
	int now = 1;
	int res = 0;
	int node = 1;
	for (int i=1;i<=N;)
	{
		
		int ed = min(N,i+split[node++]-1);
		if (ed == i)
			res += s[i] - '0';
		else
			res += (s[i] - '0') * 10 + s[i+1] - '0';
		i = ed + 1;
	}
	return res;
}

void printsplit()
{
	//for (int i=1;i<=N;i++)printf("%d\n",split[i]);
	for (int i=2;i<=N;i++)split[i] += split[i-1];
	int node = 1;
	for (int i=1;i<=N;i++)
	{
		printf("%c",s[i]);
		if (i == split[node] && i<N)
		{
			printf("+");
			node++;
		}
	}
	puts("");
}

int len;
char dx[30];
vector<char>res;

int calc(int x)
{
	//printf("X = %d\n",x);
	int res = 0;
	while(x)
	{
		res += x%10;
		x /= 10;
	}
	//printf("RES = %d\n",res);
	return res;
}

void printsm(int v)
{
	if (v < 10)
	{
		printf("%d",v);
		return;
	}
	printsm(v/10);
	printf("+");
	printf("%d",v%10);
}

bool check(int x)
{
	len = 0;
	while(x){dx[++len] = x%10 + '0';x /= 10;}
	reverse(dx+1,dx+len+1);
	for (int i=0;i<(1<<(len-1));i++)
	{
		res.clear();
		for (int j=0;j<len;j++)
		{
			res.push_back(dx[j+1]);
			if (i & (1<<j)) res.push_back('+');
		}
		int len2 = res.size();
		int v = 0, last = 0;
		for (int i=0;i<res.size();)
		if (i == res.size()-1 || res[i+1] == '+')
		{
			int tmp = 0;
			for (int j=last;j<=i;j++)tmp = tmp*10 + res[j] - '0';
			v += tmp;
			last = i+2;//a
			i = i+2;
		}
		else i++;
		//for (auto t:res) printf("%c",t);puts("");getchar();
		if (calc(v) < 10)
		{
			printsplit();
			for (auto t:res) printf("%c",t);puts("");
			printsm(v);
			return true;
		}
	}
	return false;
}

int main()
{
	//printsm(12345);
	srand(time(0));
	scanf("%d",&N);
	scanf("%s",s+1);
	while(1)
	{
		int v = randsplit();
		//puts("done");
		if (check(v)) break;
	}
}
