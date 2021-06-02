#include <bits/stdc++.h>

using namespace std;

char s[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int len = strlen(s);
		int ma,mi,now;
		ma = mi = now = 0;
		int ans = 0;
		char nowsign = 0;
		int nowcnt = 0;
		for (int i=0;i<len;i++)
		{
			if (s[i] == '=') continue;
			if (s[i] == nowsign)
				nowcnt++;
			else
				nowcnt = 1;
			nowsign = s[i];
			ans = max(ans,nowcnt); 
		}
		printf("%d\n",ans+1);
	}
}
