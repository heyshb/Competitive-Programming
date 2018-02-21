#include <bits/stdc++.h>

using namespace std;

int s[6];
char color[6] = {'R','O','Y','G','B','V'};
int N;

int main()
{
	freopen("Bl.in","r",stdin);
	freopen("Bl.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int _=1;_<=T;_++)
	{
		scanf("%d",&N);
		int M = 0;
		for (int i=0;i<6;i++)
		{
			scanf("%d",&s[i]);
			M = max(M,s[i]);
		}
		string ans = "";
		int now,st;
		for (int i=0;i<6;i++)
		if (s[i]) now = i;
		st = now;
		vector<int>tmp;
		bool flag = true;
		int cnt = 0;
		while(true)
		{
			ans += color[now];
			s[now]--;
			if (++cnt==N)
			{
				//printf("%c %c\n",ans[cnt-1],ans[0]);
				if (ans[cnt-1] == ans[0]) flag = false;
				break;
			}
			tmp.clear();
			tmp.push_back((now+2)%6);
			tmp.push_back((now+3)%6);
			tmp.push_back((now+4)%6);
			int next = -1,M = 0;
			for (auto t:tmp)
			if (s[t] > M)
			{
				next = t;
				M = s[t];
			}
			if (next == -1)
			{
				for (int i=0;i<6;i++)
				if (s[i]) flag = false;
				break;
			}
			for (auto t:tmp)
			if (s[t] == M && t==st) next = t;
			now = next;
		}
		
		printf("Case #%d: ",_);
		if (flag)
			cout<<ans<<endl;
		else
			puts("IMPOSSIBLE");
	}
}
