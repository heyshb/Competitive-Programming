#include <bits/stdc++.h>

using namespace std;

bool vis[256];
char s[100010];
bool hv[10];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int len = strlen(s);
		memset(hv,0,sizeof(hv));
		memset(vis,false,sizeof(vis));
		for (int i=0;i<len;i++)
		{
			int now = s[i] - '0';
			for (int j=0;j<10;j++)
			if (hv[j])
				vis[j*10+now] = vis[now*10+j] = true;
				
			hv[now] = true;
		}
		for (int i='A';i<='Z';i++)if (vis[i]) printf("%c",i);
		puts("");
	}
}
