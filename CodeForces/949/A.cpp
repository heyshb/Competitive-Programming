#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[200010];
bool vis[200010];
int pre[200010];
queue<int>q1,q0;

void print(int x)
{
	vector<int>ans;
	ans.clear();
	while(x != -1)
	{
		vis[x] = true;
		ans.push_back(x);
		x = pre[x];
	}
	reverse(ans.begin(),ans.end());
	printf("%d",ans.size());
	for (int i=0;i<ans.size();i++)printf(" %d",ans[i] + 1);
	puts("");
}

int main()
{
	scanf("%s",s);
	int N = strlen(s);
	int s0 = 0, s1 = 0;
	for (int i=0;i<N;i++)
	if (s[i] == '0') s0++;
	else s1++;
	int K = s0 - s1;
	if (K <= 0) return 0*puts("-1");
	int cnt = 0;
	for (int i=0;i<N;i++)
	if (s[i] == '0')
	{
		cnt++;
		pre[i] = -1;
		q0.push(i);
		if (cnt == K) break;
	}
	for (int i=0;i<N;i++)
	if (!pre[i])
	{
		if (s[i] == '0')
		{
			if (q1.empty()) return 0*puts("-1");
			pre[i] = q1.front();
			q1.pop();
			q0.push(i);
		}
		else
		{
			if (q0.empty()) return 0*puts("-1");
			pre[i] = q0.front();
			q0.pop();
			q1.push(i);
		}
	}
	for (int i=0;i<N;i++)
	if (pre[i] > i) return 0*puts("-1");
	printf("%d\n",K);
	for (int i=N-1;i>=0;i--)
	if (!vis[i]) print(i);
}
