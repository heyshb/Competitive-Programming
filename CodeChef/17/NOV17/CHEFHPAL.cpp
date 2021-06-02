#include <bits/stdc++.h>

using namespace std;

char *s3 = "aaababbb";
char *s4 = "abbaab";
int main()
{
	int T,N,M;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		if (M >= 3)
		{
			printf("1 ");
			for (int i=1;i<=N;i++)printf("%c",'a'+i%3);
			puts("");
			continue;
		}
		if (M == 1)
		{
			printf("%d ",N);
			for (int i=1;i<=N;i++)printf("a");
			puts("");
			continue;
		}
		if (N == 1) {puts("1 a");continue;}
		if (N == 2)	{puts("1 ab");continue;}
		if (N == 3) {puts("2 abb");continue;}
		if (N == 4) {puts("2 aabb");continue;}
		if (N <= 8)
		{
			printf("3 ");
			for (int i=0;i<N;i++)printf("%c",s3[i]);
			puts("");
			continue;
		}
		printf("4 ");
		for (int i=0;i<N;i++)printf("%c",s4[i%6]);
		puts("");
	}
}
