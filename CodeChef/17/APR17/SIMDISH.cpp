#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s[2][4];
	int Casi;
	scanf("%d",&Casi);
	while(Casi--)
	{
		for (int i=0;i<2;i++)
			for (int j=0;j<4;j++)cin>>s[i][j];
		int cnt = 0;
		for (int i=0;i<4;i++)
		{
			bool flag = false;
			for (int j=0;j<4;j++)
				if (s[1][j] == s[0][i]) flag = true;
			if (flag) cnt++;
		}
		puts(cnt>=2?"similar":"dissimilar");
	}
}
