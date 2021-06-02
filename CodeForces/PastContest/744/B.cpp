#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int ans[1010];
bool ask[1010];

int main()
{
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)ans[i] = 1e9+10;
 	for (int i=0;i<10;i++)
 	{
 		for (int j=0;j<2;j++)
 		{
 			//printf("ASK %d %d\n",i,j);
 			int cnt = 0;
 			memset(ask,false,sizeof(ask));
 			for (int k=1;k<=N;k++)
 			{
	 			if (((k&(1<<i))>>i)==j)
	 			{
	 				ask[k] = true;
	 				cnt++;
	 			}	
	 		}
 			if (cnt>0 && cnt<N)
 			{
	 			printf("%d\n",cnt);
	 			for (int k=1;k<=N;k++)if (ask[k])printf("%d ",k);
	 			puts("");
				fflush(stdout);
				 
				for (int k=1;k<=N;k++)
				{
					int tmp;
					scanf("%d",&tmp);
	 				if (((k&(1<<i))>>i)!=j)ans[k] = min(ans[k],tmp);
	 			}
	 		}
	 		else continue;
		}
 	}
 	puts("-1");
 	for (int i=1;i<=N;i++)printf("%d ",ans[i]);
	fflush(stdout);
}
