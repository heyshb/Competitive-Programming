#include <bits/stdc++.h>

using namespace std;

int v[200];
typedef long long LL;

int main()
{
	freopen("Bl.in","r",stdin);
	freopen("Bl.out","w",stdout);
	int Casi;
	scanf("%d",&Casi);
	for (int _=1;_<=Casi;_++)
	{
		LL N;
		scanf("%lld",&N);
		int len = 0;
		do
		{
			v[++len] = N%10;
			N/=10;
		}while(N);
		reverse(v+1,v+len+1);
		//for (int i=1;i<=len;i++)printf("%d ",v[i]);puts("");
		int pos = -1;
		v[0] = -1;
		for (int i=1;i<=len;i++)
		if (v[i] < v[i-1])
		{
			pos = i-1;
			break;
		}
		if (pos != -1)
		{
			while(v[pos-1] == v[pos]) pos--;
			v[pos]--;
			for (int i=pos+1;i<=len;i++)v[i] = 9;
		}
		LL res = 0;
		for (int i=1;i<=len;i++)res = res*10LL + LL(v[i]);
		printf("Case #%d: %lld\n",_,res);
	}
}
