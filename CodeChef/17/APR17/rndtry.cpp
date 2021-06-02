#include <bits/stdc++.h>

using namespace std;

bool vis[6010][6010];

int main()
{
	srand(time(0));
	int x = 3000, y = 3000, cnt = 0;
	for (int i=0;i<5000;i++)
	{
		if (!vis[x][y])
		{
			cnt++;
			vis[x][y] = true;
		}
		int dir = rand()%4;
		if (dir==0) x++;
		if (dir==1) x--;
		if (dir==2) y++;
		if (dir==3) y--; 
	}
	printf("%d %d %d\n",cnt,x,y);
}
