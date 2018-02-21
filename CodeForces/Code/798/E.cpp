#include <bits/stdc++.h>

using namespace std;

int N,A[100010];
int ans[100010];
vector<pair<int,int> >v;
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		if (A[i]!=-1)
			v.push_back(make_pair(A[i],i));
	}
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();i++)
		ans[v[i].second] = i+1;
	int now = N;
	for (int i=1;i<=N;i++)if (ans[i]==0) ans[i] = now--;
	for (int i=1;i<=N;i++)printf("%d ",ans[i]);
}
