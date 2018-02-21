#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL ans;
int A,B,C,N;
vector<int> v1,v2;

int main()
{
	scanf("%d%d%d",&A,&B,&C);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		int co;
		char str[10];
		scanf("%d",&co);
		scanf("%s",str);
		if (str[0]=='U')
			v1.push_back(co);
		else 
			v2.push_back(co);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int p1=min(int(v1.size()),A)-1,p2=min(int(v2.size()),B)-1;
	while(p1+1<v1.size() && p2+1<v2.size() && C>0)
	{
		C--;
		if (v1[p1]<v2[p2])
			p1++;
		else
			p2++;
	}
	while(p1+1<v1.size() && C>0) {p1++;C--;}
	while(p2+1<v2.size() && C>0) {p2++;C--;}
	ans=0;
	for (int i=0;i<=p1;i++)ans+=LL(v1[i]);
	for (int i=0;i<=p2;i++)ans+=LL(v2[i]);
	printf("%d %I64d\n",p1+p2+2,ans);
}

