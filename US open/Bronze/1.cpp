#include <bits/stdc++.h>

using namespace std;

char s[4][4];
bool ok[26][26];

int main()
{
	freopen("tttt.in","r",stdin);
	freopen("tttt.out","w",stdout);	
	for (int i=0;i<3;i++)scanf("%s",s[i]);
	memset(ok,false,sizeof(ok));
	set<int>st;
	for (int i=0;i<3;i++)
	{
		st.clear();
		for (int j=0;j<3;j++)st.insert(s[i][j]-'A');
		if (st.size()==2)
		{
			auto v1 = st.begin();
			auto v2 = v1;
			v2++;
			ok[*v1][*v2] = true;
		}
		if (st.size()==1)
		{
			auto v1 = st.begin();
			ok[*v1][*v1] = true;
		}
	}
	for (int i=0;i<3;i++)
	{
		st.clear();
		for (int j=0;j<3;j++)st.insert(s[j][i]-'A');
		if (st.size()==2)
		{
			auto v1 = st.begin();
			auto v2 = v1;
			v2++;
			ok[*v1][*v2] = true;
		}
		if (st.size()==1)
		{
			auto v1 = st.begin();
			ok[*v1][*v1] = true;
		}
	}
	st.clear();
	for (int j=0;j<3;j++)st.insert(s[j][j]-'A');
	if (st.size()==2)
	{
		auto v1 = st.begin();
		auto v2 = v1;
		v2++;
		ok[*v1][*v2] = true;
	}
	if (st.size()==1)
	{
		auto v1 = st.begin();
		ok[*v1][*v1] = true;
	}
	st.clear();
	for (int j=0;j<3;j++)st.insert(s[j][2-j]-'A');
	if (st.size()==2)
	{
		auto v1 = st.begin();
		auto v2 = v1;
		v2++;
		ok[*v1][*v2] = true;
	}
	if (st.size()==1)
	{
		auto v1 = st.begin();
		ok[*v1][*v1] = true;
	}
	int ans1=0,ans2=0;
	for (int i=0;i<26;i++)
		for (int j=i;j<26;j++)
		if (ok[i][j])
		{
			if (i==j) ans1++;
			else ans2++;
		}
	printf("%d\n%d\n",ans1,ans2);
} 
