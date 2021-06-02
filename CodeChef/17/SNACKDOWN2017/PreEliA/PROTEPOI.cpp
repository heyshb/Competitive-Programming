#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int T;
vector<pair<int,int> >h,s;
map<int,int> H,S;

bool mid(int a,int l,int r)
{
	return a>=l && a<=r;
}

int main()
{
	freopen("PROTEPOI.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int N,K;
		scanf("%d%d",&N,&K);
		int M;
		scanf("%d",&M);
		//(N-K)/2+1, (N+K)/2
		int L = (N-K)/2 + 1 , R = (N+K)/2;
		s.clear();
		h.clear();
		for (int i=1;i<=M;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if (x1 > x2) swap(x1,x2);
			if (y1 > y2) swap(y1,y2);
			//printf("%d %d, %d %d\n",x1,y1,x2,y2);
			if (x1 == x2)// heng
			{
				if (mid(x1,L,R))
				{
					s.push_back(make_pair(x1,x1));
				}
				else if (!(y2 < L || y1 > R))
				{
					h.push_back(make_pair(max(y1,L),min(y2,R)));
				}
			}
			else
			{
				if (mid(y1,L,R))
				{
					h.push_back(make_pair(y1,y1));
				}
				else if (!(x2 < L || x1 > R))
				{
					s.push_back(make_pair(max(x1,L),min(x2,R)));
				}
			}
		}
		/* 
		puts("Heng:");
		for (auto t:h) printf("%d--%d\n",t.first,t.second);
		puts("Shu:");
		for (auto t:s) printf("%d--%d\n",t.first,t.second);*/
		H.clear();
		for (auto t:h)
		{
			int l,r;
			l = t.first;
			r = t.second;
			assert(r>=l);
			if (H.find(l) == H.end())
				H[l] = r;
			else
				H[l] = max(H[l],r);
		}
		S.clear();
		for (auto t:s)
		{
			int l,r;
			l = t.first;
			r = t.second;
			assert(r>=l);
			if (S.find(l) == S.end())
				S[l] = r;
			else
				S[l] = max(S[l],r);
		}
		int maxr;
		
		maxr = -1;
		h.clear();
		for (auto t=H.begin();t!=H.end();t++)
		if (t->second > maxr)
		{
			h.push_back(make_pair(t->first,t->second));
			maxr = t->second;
		}
		s.clear();
		
		maxr = -1;
		for (auto t=S.begin();t!=S.end();t++)
		if (t->second > maxr)
		{
			s.push_back(make_pair(t->first,t->second));
			maxr = t->second;
		}
		/*
		puts("Heng:");
		for (auto t:h) printf("%d--%d\n",t.first,t.second);
		puts("Shu:");
		for (auto t:s) printf("%d--%d\n",t.first,t.second);*/
		bool ok = true;
		int mini = 0;
		
		if (s[0].first != L || h[0].first != L) ok = false;
		maxr = -1;
		for (int i=0;i<s.size();)
		{
			mini++;
			maxr = s[i].second;
			while(i+1<s.size() && s[i+1].first<=maxr+1) i++;
			if (s[i].second <= maxr)
				break;
		}
		if (maxr != R) ok = false;
		
		maxr = -1;
		for (int i=0;i<h.size();)
		{
			mini++;
			maxr = h[i].second;
			while(i+1<h.size() && h[i+1].first<=maxr+1) i++;
			if (h[i].second <= maxr)
				break;
		}
		if (maxr != R) ok = false;
		if (ok) printf("%d\n",mini);
		else puts("-1");
	}
}
