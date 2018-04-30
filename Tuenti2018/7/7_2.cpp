#include <bits/stdc++.h>

using namespace std;

int N;
char v[100000],code[100000];

time_t st,ed;

char s[100010] = {0};
int len = 0;
int stk[100010],top;
int match[100000];
int minp = 50000,maxp = 50000;

string simulate()
{
	string ret = "";
	for (int i=1;i<=N;i++)code[i] = v[i],match[i] = -1;
	top = 0;
	for (int i=1;i<=N;i++)
	{
		if (code[i] == '[')
		{
			stk[++top] = i;
		}
		else if (code[i] == ']')
		{
			if (!top) return "CE";
			int mt = stk[top--];
			match[i] = mt;
			match[mt] = i;
		}
	}
	for (int i=1;i<=N;i++)
	if (code[i] == '[' && match[i] == -1)
	{
		return "CE";
	}
	//for (int i=1;i<=N;i++)if (match[i] != -1) printf("%d---%d\n",i,match[i]);
	char *p = s + 50000;
	int i = 1;
	while(i<=N)
	{
		switch(code[i])
		{
			case '+':
				(*p)++;
				break;
			case '-':
				(*p)--;
				break;
			case '>':
				p++;
				break;
			case '<':
				p--;
				break;
			case '.':
				ret += (*p);
				break;
			case '[':
				if ((*p) == 0)
					i = match[i];
				break;
			case ']':
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
	freopen("hello.txt","r",stdin);
	scanf("%s",v+1);
	N = strlen(v+1);
	cout << simulate() << endl;
}
