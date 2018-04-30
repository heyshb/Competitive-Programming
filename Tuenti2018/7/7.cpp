#include <bits/stdc++.h>

using namespace std;

int N,v[100000],code[100000];
int perm[100000];

time_t st,ed;

char s[100010] = {0};
int len = 0;
int stk[100010],top;
int match[100000];
int minp = 50000,maxp = 50000;

string simulate()
{
	string ret = "";
	for (int i=1;i<=N;i++)code[i] = perm[v[i]],match[i] = -1;
	top = 0;
	for (int i=1;i<=N;i++)
	{
		if (code[i] == 6)
		{
			stk[++top] = i;
		}
		else if (code[i] == 7)
		{
			if (!top) return "CE";
			int mt = stk[top--];
			match[i] = mt;
			match[mt] = i;
		}
	}
	for (int i=1;i<=N;i++)
	if (code[i] == 6 && match[i] == -1)
	{
		return "CE";
	}
	for (int i=minp;i<=maxp;i++)s[i] = 0;
	
	minp = 50000;
	maxp = 50000;
	char *p = s + 50000;
	int i = 1;
	while(i<=N)
	{
		if (clock() > st + 2) return "TLE";
		if (ret.length() > 1000) return "OLE";
		switch(code[i])
		{
			case 1:
				(*p)++;
				break;
			case 2:
				(*p)--;
				break;
			case 3:
				p++;
				maxp = max(maxp,int(p-s));
				break;
			case 4:
				p--;
				minp = min(minp,int(p-s));
				break;
			case 5:
				ret += (*p);
				break;
			case 6:
				if ((*p) == 0)
					i = match[i];
				break;
			case 7:
				if ((*p) != 0)
					i = match[i];
				break;
			default:
				break;
		}
		i++;
	}
	return ret;
}

int main()
{
	freopen("7_2.in","r",stdin);
	N = 148;
	for (int i=1;i<=N;i++)scanf("%d",&v[i]);
	reverse(v+1,v+N+1);
	for (int i=1;i<=7;i++)perm[i] = i;
	for (int i=1;i<=5040;i++)
	{
		st = clock();
		string ret = simulate();
		if (ret != "CE")
		cout <<i << ":" << ret << endl;
		//puts(">>");
		next_permutation(perm+1,perm+8);
		//puts("!!");
	}
}
