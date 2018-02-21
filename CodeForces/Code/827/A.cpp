#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MAXLEN 2000000
int N;
char v[MAXLEN+10];
string str[100010];
struct seg
{
	int l,r,num;
};
vector<seg>s;
bool cmp(seg a,seg b){return a.l<b.l;}

int main()
{
	memset(v,0,sizeof(v));
	scanf("%d",&N);
	int ml=0;
	for (int i=1;i<=N;i++)
	{
		cin>>str[i];
		//cout<<str[i]<<endl;
		int len = str[i].length();
		int K,ll;
		scanf("%d",&K);
		while(K--)
		{
			scanf("%d",&ll);
			s.push_back((seg){ll,ll+len-1,i});
		}
	}
	sort(s.begin(),s.end(),cmp);
	int rr = 0;
	for (int i=0;i<s.size();i++)
	{
		int len = str[s[i].num].length();
		for (int j=max(rr,s[i].l);j<=s[i].r;j++)
			v[j] = str[s[i].num][j - s[i].l];
		rr = max(rr,s[i].r);	
	}	
	for (int i=1;i<=rr;i++)
	if (v[i])
		printf("%c",v[i]);
	else
		printf("a");
}
