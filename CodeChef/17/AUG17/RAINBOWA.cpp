#include <bits/stdc++.h>

using namespace std;

int N;
int A[110];
vector<pair<int,int> >d;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		bool ok = true;
		int last = 0;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			if (A[i] > 7) ok = false;
		}
		A[N + 1] = -1;
		d.clear();
		int cnt = 1;
		for (int i=1;i<=N;i++)
		if (A[i] != A[i+1])
		{
			d.push_back(make_pair(A[i],cnt));
			cnt = 1;
		}
		else
			cnt++;
		if (d.size() != 13) ok = false;
		for (int i=0;i<7;i++)
		if (d[i].first != i+1) ok = false;
		for (int i=0;i<7;i++)
		if (d[i].first != d[12-i].first || d[i].second != d[12-i].second) ok = false;
		puts(ok?"yes":"no");
	}
}
