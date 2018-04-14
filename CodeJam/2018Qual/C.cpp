#include <bits/stdc++.h>

using namespace std;

bool mp[30][30];

int main()
{
	//cerr<<"fuck"<<endl;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int A,N,M;
		scanf("%d",&A);
		if (A == 20)
		{
			N = 4;
			M = 5;
		}
		else 
		{
			N = 10;
			M = 20;
		}
		for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)mp[i][j] = false;
		int cnt = 0;
		while(true)
		{
			cerr<<cnt<<endl;
			int maxsum = 0, maxx,maxy;
			for (int i=2;i<N;i++)
			{
				for (int j=2;j<M;j++)
				{
					int sum = 0;
					for (int k=-1;k<=1;k++)
						for (int l=-1;l<=1;l++)
							sum += (!mp[i+k][j+l]);
					if (sum > maxsum)
					{
						maxsum = sum;
						maxx = i;
						maxy = j;
					}
					if (maxsum == 9) break;
				}
				if (maxsum == 9) break; 
			}
			printf("%d %d\n",maxx+10,maxy+10);
			fflush(stdout);
			int x,y;
			scanf("%d%d",&x,&y);
			if (x == 0 && y == 0) break;
			x-=10;
			y-=10;
			if (!mp[x][y])
			{
				mp[x][y] = true;
				cnt++;
			}
		}
		//assert(cnt == A);
	}
}
