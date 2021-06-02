#include <bits/stdc++.h>

using namespace std;

int A,B;
char s[500010];
int N,x,y;
int ans[500010];
char out[200010]; 
int pos;

char gao(char ori,bool flag)
{
	if (!flag) return ori;
	if (ori == 'a') return 'b';
	return 'a';
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		A = B = 0;
		scanf("%s",s);
		N = strlen(s);
		for (int i=0;i<N;i++)
		{
			A += (s[i] == 'a');
			B += (s[i] == 'b');
		}
		scanf("%d%d",&x,&y);
		bool flag = false;
		if (A < B)
		{
			swap(A,B);
			swap(x,y);
			flag = true;
		}
		for (int i=1;i<=2*B;i++) ans[i] = 1; 
		A -= B;
		if (B)
		for (int i=1;A && ans[i] < x;i = (i + 2) % (2 * B))
		{
			ans[i]++;
			A--;
		}
		for (int i=1;i<=2*B;i++)
			for (int j=1;j<=ans[i];j++)
			if (i & 1)
				printf("%c",gao('a',flag));
			else	
				printf("%c",gao('b',flag));
		for (int i=1;i<=A;i++)
		{
			if (i > 1 && (x == 1 || (i % x == 1))) printf("*");
			printf("%c",gao('a',flag));
		}
		puts("");
	}
}
